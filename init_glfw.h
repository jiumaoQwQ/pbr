#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "Camera.h"

GLFWwindow *window;
static struct __Init_glfw
{
    __Init_glfw()
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(800, 800, "PBR", NULL, NULL);
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, [](GLFWwindow *window, int width, int height)
                                       { glViewport(0, 0, width, height); });
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

        glEnable(GL_CULL_FACE);
        glEnable(GL_DEPTH_TEST);
    }
    ~__Init_glfw()
    {
        glfwTerminate();
    }
} __init_glfw;

static Camera camera;