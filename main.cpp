#include <imgui_wrapper.h>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <iostream>

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(1280, 720, "pbr", NULL, NULL);

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow *window, int width, int height)
                                   { glViewport(0, 0, width, height); });

    glfwSetCursorPosCallback(window, [](GLFWwindow *window, double xpos, double ypos)
                             {
                                 // std::cout<<xpos<<" "<<ypos<<std::endl;
                             });

    glfwSetKeyCallback(window, [](GLFWwindow *window, int key, int scancode, int action, int mods)
                       {
                        if(key==GLFW_KEY_E && action==GLFW_PRESS)
                            std::cout<<"E pressed!"<<std::endl; });

    gladLoadGL(glfwGetProcAddress);

    ImGuiWrapper guiwrapper(window);

    bool showDemoWindow = true;

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        guiwrapper.frame();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui::ShowDemoWindow(&showDemoWindow);

        guiwrapper.render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}