#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum Direction
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

struct Camera
{
    glm::vec3 pos = {0, 0, 10};
    glm::vec3 euler = {0, 0, 0};
    float fov = 45.0f;
    float aspect = 1.0f;
    float zNear = 0.1f;
    float zFar = 100.0f;

    const glm::vec3 worldUp = {0, 1, 0};
    const glm::vec4 direction = {0, 0, -1, 1};
    Camera()
    {
    }

    Camera(glm::vec3 const &_pos, glm::vec3 const &_euler) : pos(_pos), euler(_euler)
    {
    }
    glm::mat4 getViewMatrix()
    {
        glm::qua<float> quaternion = glm::qua<float>(glm::radians(euler));
        glm::vec4 lookatdir = glm::mat4_cast(quaternion) * direction;
        glm::vec3 lookatpos = pos + glm::vec3(lookatdir.x, lookatdir.y, lookatdir.z);
        return glm::lookAt(pos, lookatpos, worldUp);
    }
    glm::mat4 getProjectionMatrix()
    {
        return glm::perspective(fov, aspect, zNear, zFar);
    }
    void move(Direction dir)
    {
        float speed = 0.01;
        glm::qua<float> quaternion = glm::qua<float>(glm::radians(euler));
        glm::vec4 _forwardDir = glm::mat4_cast(quaternion) * direction;
        glm::vec3 forwardDir = glm::vec3(_forwardDir);
        glm::vec3 rightDir = glm::cross(forwardDir, worldUp);
        switch (dir)
        {
        case FORWARD:
            pos += forwardDir * speed;
            break;
        case BACKWARD:
            pos -= forwardDir * speed;
            break;
        case LEFT:
            pos -= rightDir * speed;
            break;
        case RIGHT:
            pos += rightDir * speed;
            break;
        default:
            break;
        }
    }
};