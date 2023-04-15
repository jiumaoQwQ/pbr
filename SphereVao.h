#pragma once

#include <glad/glad.h>

struct SphereVao
{
    SphereVao() {}
    ~SphereVao()
    {
        glDeleteVertexArrays(1, vao);
        glDeleteBuffers(4, vbo);
    }

    void copyIn(void *vertex, void *normal, void *texcoord, void *index,
                unsigned int vertex_size, unsigned int normal_size, unsigned int texcoord_size, unsigned int index_size)
    {
        glGenVertexArrays(1, vao);
        glGenBuffers(4, vbo);

        glBindVertexArray(vao[0]);

        glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
        glBufferData(GL_ARRAY_BUFFER, vertex_size, vertex, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
        glBufferData(GL_ARRAY_BUFFER, normal_size, normal, GL_STATIC_DRAW);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
        glBufferData(GL_ARRAY_BUFFER, texcoord_size, texcoord, GL_STATIC_DRAW);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(2);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[3]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_size, index, GL_STATIC_DRAW);

        num_of_index = index_size / sizeof(unsigned int);
    }

    void draw()
    {
        glBindVertexArray(vao[0]);

        glDrawElements(GL_TRIANGLE_STRIP, num_of_index, GL_UNSIGNED_INT, 0);
    }

    unsigned int vao[1], vbo[4];
    unsigned int num_of_index;
};