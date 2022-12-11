#include <glm/vec3.hpp>

class Sphere
{
public:
    Sphere(glm::vec3 _pos = {0, 0, 0}, float _radius = 1.0f) : pos(_pos), radius(_radius)
    {
        
    }
    void draw()
    {
    }

private:
    glm::vec3 pos;
    float radius;
};