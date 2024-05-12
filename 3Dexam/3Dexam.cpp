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
    Player myPlayer(1.0f, glm::vec3(5, 10, 3), 0.f, 0.0f, 1.f, 1);
    Player myCube(1.0f, glm::vec3(0, 10, 1), 1.f, 1.0f, 1.f, 8);

    //points
    Player point1(10.0f, glm::vec3(0, 0, 0), 0.f, 0.0f, 1.f, 9);
    Player point2(1.0f, glm::vec3(0, 10, 1), 0.f, 0.0f, 1.f, 1);
    Player point3(1.0f, glm::vec3(10, 10, -4), 0.f, 0.0f, 1.f, 1);


    Math_class math;
    glm::vec3 x_cords = { 0, 1, 2 };
    glm::vec3 y_cords = { 0, 5, -4 };

    glm::vec3 graph1 = math.QuadraticInterpolation(x_cords, y_cords);


    //textures
    Texture texture1("Resources/Texture/textures/cool_Image.jpg", shaderProgram);


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
        point2.Ai(graph1, x_cords.z, x_cords.x);
        camera.Inputs(window);
        point1.calculateBarycentricCoordinates(myPlayer.position, true);
        point1.calculateBarycentricCoordinates(myCube.position, true);
        point1.calculateBarycentricCoordinates(point2.position, true);
        point1.calculateBarycentricCoordinates(point3.position, true);

        myPlayer.SphereCollision(point2); 
        point2.SphereCollision(myPlayer);
        //Set render distance and FOV
        glm::mat4 viewproj = camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");


        glm::mat4 model1 = glm::mat4(1.0f);
        model1 = glm::translate(model1, myCube.position);
        //model1 = glm::scale(model1, glm::vec3(10.f, 10.f, 10.f));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "camMatrix"), 1, GL_FALSE, glm::value_ptr(viewproj * model1));
        myCube.BindVAO();
        myCube.GetVBO().Bind();
        glDrawArrays(GL_LINE_STRIP, 0, myCube.mVertecies.size());
        myCube.UnbindVAO();
            

        glBindTexture(GL_TEXTURE_2D, texture1.texture);

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, myPlayer.position);
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "camMatrix"), 1, GL_FALSE, glm::value_ptr(viewproj * model));
        myPlayer.BindVAO();
        myPlayer.GetVBO().Bind();
        glDrawArrays(GL_TRIANGLES, 0, myPlayer.mVertecies.size());
        myPlayer.UnbindVAO();


        glm::mat4 model2 = glm::mat4(1.0f);
        model2 = glm::translate(model2, point1.position);
        model2 = glm::scale(model2, glm::vec3(10.f, 10.f, 10.f));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "camMatrix"), 1, GL_FALSE, glm::value_ptr(viewproj * model2));
        point1.BindVAO();
        point1.GetVBO().Bind();
        glDrawArrays(GL_TRIANGLES, 0, point1.mVertecies.size());
        point1.UnbindVAO();

        glm::mat4 model3 = glm::mat4(1.0f);
        model3 = glm::translate(model3, point2.position);
        //model3 = glm::scale(model3, glm::vec3(1.f, 1.f, 1.f));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "camMatrix"), 1, GL_FALSE, glm::value_ptr(viewproj * model3));
        point2.BindVAO();
        point2.GetVBO().Bind();
        glDrawArrays(GL_TRIANGLES, 0, point2.mVertecies.size());
        point2.UnbindVAO();

        glm::mat4 model4 = glm::mat4(1.0f);
        model4 = glm::translate(model4, point3.position);
        //model4 = glm::scale(model4, glm::vec3(1.f, 1.f, 1.f));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "camMatrix"), 1, GL_FALSE, glm::value_ptr(viewproj * model4));
        point3.BindVAO();
        point3.GetVBO().Bind();
        glDrawArrays(GL_TRIANGLES, 0, point3.mVertecies.size());
        point3.UnbindVAO();



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