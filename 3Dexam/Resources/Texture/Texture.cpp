#include "Texture.h"
#include <iostream>
#include <GLFW/glfw3.h>





Texture::Texture(const char* texture1, int num, Shader shaderProgram)
{
	ID = num; 

	glGenTextures(1, &texture);
	glActiveTexture(GL_TEXTURE0 + num);
	glBindTexture(GL_TEXTURE_2D, texture);

	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// load and generate the texture
	int nwidth, nheight, nrChannels;
	unsigned char* data = stbi_load(texture1, &nwidth, &nheight, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, nwidth, nheight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);


	shaderProgram.Activate();
	shaderProgram.setInt("ourTexture", num);

}

void Texture::UnbindTexture()
{
	glBindTexture(GL_TEXTURE_2D, ID);
}

