#pragma once

#include <glm/vec3.hpp>

#include "SphereVao.h"
#include "Shader.h"

#include <vector>
#include <cmath>

class Sphere
{
private:
    float radius = 1.0f;
    glm::vec3 pos = {0, 0, 0};

    SphereVao vao;

public:
    explicit Sphere()
    {
        std::vector<glm::vec3> positions, normals;
        std::vector<glm::vec2> uv;
        std::vector<unsigned int> indices;

        const unsigned int X_SEGMENTS = 64;
        const unsigned int Y_SEGMENTS = 64;
        const float PI = 3.14159265359f;
        for (unsigned int x = 0; x <= X_SEGMENTS; ++x)
        {
            for (unsigned int y = 0; y <= Y_SEGMENTS; ++y)
            {
                float xSegment = (float)x / (float)X_SEGMENTS;
                float ySegment = (float)y / (float)Y_SEGMENTS;
                float xPos = std::cos(xSegment * 2.0f * PI) * std::sin(ySegment * PI);
                float yPos = std::cos(ySegment * PI);
                float zPos = std::sin(xSegment * 2.0f * PI) * std::sin(ySegment * PI);

                positions.push_back(glm::vec3(xPos, yPos, zPos));
                uv.push_back(glm::vec2(xSegment, ySegment));
                normals.push_back(glm::vec3(xPos, yPos, zPos));
            }
        }

        bool oddRow = false;
        for (unsigned int y = 0; y < Y_SEGMENTS; ++y)
        {
            if (!oddRow)
            {
                for (unsigned int x = 0; x <= X_SEGMENTS; ++x)
                {
                    indices.push_back(y * (X_SEGMENTS + 1) + x);
                    indices.push_back((y + 1) * (X_SEGMENTS + 1) + x);
                }
            }
            else
            {
                for (int x = X_SEGMENTS; x >= 0; --x)
                {
                    indices.push_back((y + 1) * (X_SEGMENTS + 1) + x);
                    indices.push_back(y * (X_SEGMENTS + 1) + x);
                }
            }
            oddRow = !oddRow;
        }

        vao.copyIn(positions.data(), normals.data(), uv.data(), indices.data(),
                   positions.size() * sizeof(glm::vec3), normals.size() * sizeof(glm::vec3), uv.size() * sizeof(glm::vec2), indices.size() * sizeof(unsigned int));
    }

    void setPos(glm::vec3 const &_pos)
    {
        pos = _pos;
    }

    glm::mat4 getModelMatrix()
    {
        return glm::translate(glm::scale(glm::mat4(1.0f), glm::vec3(radius, radius, radius)), pos);
    }

    void draw()
    {
        vao.draw();
    }
};