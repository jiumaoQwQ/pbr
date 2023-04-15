#pragma once

#include <glm/glm.hpp>
#include <vector>

struct Light
{
    glm::vec3 pos = {10, 10, 10};
    glm::vec3 color = {10, 10 ,10};
};

template <int N>
struct Lights
{
    std::vector<glm::vec3> pos;
    std::vector<glm::vec3> color;
    Lights()
    {
        pos.reserve(N);
        color.reserve(N);
    }
    void add_light(Light const &light)
    {
        pos.push_back(light.pos);
        color.push_back(light.color);
    }
};