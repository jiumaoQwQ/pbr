#include "init_glfw.h"
#include "Sphere.h"
#include "Light.h"
#include "Texture.h"

#include <iostream>

int main()
{
    Shader shader("./shader/shader.vs", "./shader/shader.fs");
    shader.use();

    Sphere sphere;
    Light light;
    light.pos = {0, 0, 10.0f};
    light.color = {150.0f, 150.0f, 150.0f};
    shader.setVec3("lightPositions[0]", light.pos);
    shader.setVec3("lightColors[0]", light.color);

    std::vector<Texture> textures(5);
    textures[0].loadTexture("./data/albedo.png");
    textures[1].loadTexture("./data/normal.png");
    textures[2].loadTexture("./data/metallic.png");
    textures[3].loadTexture("./data/roughness.png");
    textures[4].loadTexture("./data/ao.png");

    shader.setInt("albedoMap",0);
    shader.setInt("normalMap",1);
    shader.setInt("metallicMap",2);
    shader.setInt("roughnessMap",3);
    shader.setInt("apMap",4);
    
    for (int i = 0; i < 5; i++)
    {
        textures[i].bind(i);
    }

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0, 0, 0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.setVec3("camPos", camera.pos);
        shader.setMat4("view", camera.getViewMatrix());
        shader.setMat4("projection", camera.getProjectionMatrix());
        shader.setMat4("model", sphere.getModelMatrix());

        sphere.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}
