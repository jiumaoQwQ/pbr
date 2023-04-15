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
    Lights<1> lights;
    Light light;
    light.pos = {0, 0, 10};
    light.color = {150, 150, 150};
    lights.add_light(light);
    shader.setVec3("lightPositions[0]", lights.pos[0]);
    shader.setVec3("lightColors[0]", lights.color[0]);

    std::vector<Texture> textures(5);
    textures[0].loadTexture("./data/albedo.png");
    textures[1].loadTexture("./data/normal.png");
    textures[2].loadTexture("./data/metallic.png");
    textures[3].loadTexture("./data/roughness.png");
    textures[4].loadTexture("./data/ao.png");

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
