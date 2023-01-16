#pragma once
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <GLFW/glfw3.h>

#include <iostream>

struct Camera
{
    const glm::vec3 baseFront{0, 0, -1};

    glm::vec3 pos{0, 0, 4};
    glm::quat q{0, 0, 0, 1};
    glm::vec3 front{0, 0, -1};
    glm::vec3 right{};
    glm::vec3 up{};
    glm::vec3 eulerEngle{0, 0, 0};

    float fov = 45.0;
    float aspect = 1920 * 1.0 / 1080;

    Camera()
    {
        update();
    }

    Camera(glm::vec3 _pos, float _aspect) : pos(_pos),
                                            aspect(_aspect)
    {
        update();
    }

    glm::mat4 getViewMatrix()
    {
        return glm::lookAt(pos, pos + front, up);
    }

    glm::mat4 getProjectionMatrix()
    {
        return glm::perspective(glm::radians(fov), aspect, 0.1f, 100.0f);
    }

    void onMouseMove(float deltaX, float deltaY)
    {
        eulerEngle.y += glm::radians(deltaX * 0.05f);
        eulerEngle.x += glm::radians(deltaY * 0.05f);

        q = glm::quat(eulerEngle);
        update();
    }

    void update()
    {
        front = glm::normalize(q * baseFront);
        right = glm::normalize(glm::cross(front, glm::vec3(0, 1, 0)));
        up = glm::normalize(glm::cross(right, front));
    }
};
