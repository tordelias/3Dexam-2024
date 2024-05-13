#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include "glm/mat4x3.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cstdlib> 
#include <ctime> 
#include <stb/stb_image.h>

#include "Resources/Shaders/shaderClass.h"
#include"Resources/imported/Player.h"
#include "Resources/Camera/Camera.h"
#include "Resources/Texture/Texture.h"
#include"Math_class.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;



int main()
{

    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Test Win", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // build and compile our shader program
    // ------------------------------------
    Shader shaderProgram("Resources/Shaders/default.vert", "Resources/Shaders/default.frag");
    shaderProgram.Activate(); // you can name your shader files however you like

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------


    glEnable(GL_DEPTH_TEST);
    //glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

    //my objects
    Player myPlayer(1.0f, glm::vec3(5, 10, 3), 1.f, 1.0f, 1.f, 1);
    Player mygraph(1.0f, glm::vec3(0, 10, 1), 1.f, 1.0f, 1.f, 8);

    //points
    Player terrain(10.0f, glm::vec3(0, 0, 0), 1.f, 1.0f, 1.f, 9);
    Player aI(1.0f, glm::vec3(0, 10, 1), 1.f, 1.0f, 1.f, 1);
    Player cube0(1.0f, glm::vec3(10, 10, -4), 0.f, 0.0f, 1.f, 3);


    Math_class math;
    glm::vec3 x_cords = { 0, 1, 2 };
    glm::vec3 y_cords = { 0, 5, -4 };

    glm::vec3 graph1 = math.QuadraticInterpolation(x_cords, y_cords);


    //textures
    Texture texture1("Resources/Texture/textures/cool_Image.jpg", shaderProgram);
    Texture texture2("Resources/Texture/textures/cobblestone.jpg", shaderProgram);
    Texture texture3("Resources/Texture/textures/w101.jpg", shaderProgram);
    Texture texture4("Resources/Texture/textures/block.jpg", shaderProgram);


    Camera camera(SCR_WIDTH, SCR_HEIGHT, glm::vec3(0.0f, 10.0f, 40.0f));


    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // render the triangle

        myPlayer.inputs(window);
        //point3.inputs(window),
        aI.Ai(graph1, x_cords.z, x_cords.x);
        camera.Inputs(window);
        terrain.calculateBarycentricCoordinates(myPlayer.position, true);
        terrain.calculateBarycentricCoordinates(mygraph.position, true);
        terrain.calculateBarycentricCoordinates(aI.position, true);
        terrain.calculateBarycentricCoordinates(cube0.position, true);

        myPlayer.SphereCollision(aI);
        aI.SphereCollision(myPlayer);
        myPlayer.SphereCollision(cube0);
        //Set render distance and FOV
        glm::mat4 viewproj = camera.Matrix(45.0f, 0.1f, 1000.0f, shaderProgram, "camMatrix");

        glBindTexture(GL_TEXTURE_2D, texture2.texture);
        glm::mat4 model2 = glm::mat4(1.0f);
        model2 = glm::translate(model2, terrain.position);
        model2 = glm::scale(model2, glm::vec3(10.f, 10.f, 10.f));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "camMatrix"), 1, GL_FALSE, glm::value_ptr(viewproj * model2));
        terrain.BindVAO();
        terrain.GetVBO().Bind();
        glDrawArrays(GL_TRIANGLES, 0, terrain.mVertecies.size());
        terrain.UnbindVAO();
            

        glBindTexture(GL_TEXTURE_2D, texture1.texture);

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, myPlayer.position);
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "camMatrix"), 1, GL_FALSE, glm::value_ptr(viewproj * model));
        myPlayer.BindVAO();
        myPlayer.GetVBO().Bind();
        glDrawArrays(GL_TRIANGLES, 0, myPlayer.mVertecies.size());
        myPlayer.UnbindVAO();

        glm::mat4 model1 = glm::mat4(1.0f);
        model1 = glm::translate(model1, mygraph.position);
        //model1 = glm::scale(model1, glm::vec3(10.f, 10.f, 10.f));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "camMatrix"), 1, GL_FALSE, glm::value_ptr(viewproj * model1));
        mygraph.BindVAO();
        mygraph.GetVBO().Bind();
        glDrawArrays(GL_LINE_STRIP, 0, mygraph.mVertecies.size());
        mygraph.UnbindVAO();

        glBindTexture(GL_TEXTURE_2D, texture3.texture);

        glm::mat4 model3 = glm::mat4(1.0f);
        model3 = glm::translate(model3, aI.position);
        //model3 = glm::scale(model3, glm::vec3(1.f, 1.f, 1.f));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "camMatrix"), 1, GL_FALSE, glm::value_ptr(viewproj * model3));
        aI.BindVAO();
        aI.GetVBO().Bind();
        glDrawArrays(GL_TRIANGLES, 0, aI.mVertecies.size());
        aI.UnbindVAO();

        glBindTexture(GL_TEXTURE_2D, texture4.texture);
        glm::mat4 model4 = glm::mat4(1.0f);
        model4 = glm::translate(model4, cube0.position);
        //model4 = glm::scale(model4, glm::vec3(1.f, 1.f, 1.f));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "camMatrix"), 1, GL_FALSE, glm::value_ptr(viewproj * model4));
        cube0.BindVAO();
        cube0.GetVBO().Bind();
        glDrawArrays(GL_TRIANGLES, 0, cube0.mVertecies.size());
        cube0.UnbindVAO();



        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------


    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}