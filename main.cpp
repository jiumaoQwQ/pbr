#include "init_glfw.h"
#include "Sphere.h"

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main()
{
    Shader shader("./shader/shader.vs","./shader/shader.fs");
    shader.use();

    Sphere sphere;

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0, 0, 0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.setMat4("View",camera.getViewMatrix());
        shader.setMat4("Projection",camera.getProjectionMatrix());
        shader.setMat4("Model",sphere.getModelMatrix());

        sphere.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}
