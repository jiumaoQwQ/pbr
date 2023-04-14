#pragma once

#include <glm/vec3.hpp>

#include "SphereVao.h"
#include "Shader.h"

#include <vector>
#include <cmath>

#define PI 3.14159

class Sphere
{
private:
    float radius = 1.0f;
    glm::vec3 pos = {0, 0, 0};
    glm::vec3 color = {1, 1, 1};

    SphereVao vao;

public:
    explicit Sphere()
    {
        int X_SEGMENTS = 60;
        int Y_SEGMENTS = 60;
        std::vector<float> sphereVertices, sphereNormal, sphereTexcoord;
        std::vector<unsigned int> sphereIndices;

        for (int y = 0; y <= Y_SEGMENTS; y++)
        {
            for (int x = 0; x <= X_SEGMENTS; x++)
            {
                float xSegment = (float)x / (float)X_SEGMENTS;
                float ySegment = (float)y / (float)Y_SEGMENTS;
                float xPos = std::cos(xSegment * 2.0f * PI) * std::sin(ySegment * PI);
                float yPos = std::cos(ySegment * PI);
                float zPos = std::sin(xSegment * 2.0f * PI) * std::sin(ySegment * PI);

                sphereVertices.push_back(xPos);
                sphereVertices.push_back(yPos);
                sphereVertices.push_back(zPos);

                sphereNormal.push_back(xPos);
                sphereNormal.push_back(yPos);
                sphereNormal.push_back(zPos);

                sphereTexcoord.push_back(xSegment);
                sphereTexcoord.push_back(ySegment);
            }
        }

        for (int i = 0; i < Y_SEGMENTS; i++)
        {
            for (int j = 0; j < X_SEGMENTS; j++)
            {
                sphereIndices.push_back(i * (X_SEGMENTS + 1) + j);
                sphereIndices.push_back((i + 1) * (X_SEGMENTS + 1) + j + 1);
                sphereIndices.push_back((i + 1) * (X_SEGMENTS + 1) + j);

                sphereIndices.push_back(i * (X_SEGMENTS + 1) + j);
                sphereIndices.push_back(i * (X_SEGMENTS + 1) + j + 1);
                sphereIndices.push_back((i + 1) * (X_SEGMENTS + 1) + j + 1);
            }
        }

        vao.copyIn(sphereVertices.data(), sphereNormal.data(), sphereTexcoord.data(), sphereIndices.data(),
                   sphereVertices.size() * sizeof(float), sphereNormal.size() * sizeof(float), sphereTexcoord.size() * sizeof(float), sphereIndices.size() * sizeof(unsigned int));
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