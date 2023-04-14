#pragma once

#include <glad/gl.h>
#include <glfw/glfw3.h>

GLFWwindow *window;
static struct __Init_glfw
{
    __Init_glfw()
    {
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(800, 800, "ThreeBody", NULL, NULL);
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, [](GLFWwindow *window, int width, int height)
                                       { glViewport(0, 0, width, height); });
        gladLoadGL(glfwGetProcAddress);
    }
    ~__Init_glfw()
    {
        glfwTerminate();
    }
} __init_glfw;