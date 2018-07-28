#include <vector>
#include <GL/glew.h>


namespace glish{

    template<typename T>
    Vbo::Vbo(GLuint index, const std::vector<T> &data, GLenum usage ,GLenum target ):target(target) {
        glGenBuffers(1,&vbo); getError();
        glBindBuffer(target,vbo); getError();
        glBufferData(target, data.size()*sizeof(T), data.data(), usage);
        getError();
        glEnableVertexAttribArray(index); getError();
        glVertexAttribPointer(
                index,
                trait<T>::size,
                GL_FLOAT,
                GL_FALSE,
                0,
                (void *)0
        );
        getError();
    }
    template<class T>
    void Vbo::update(T &&value, int offset) {
        glBindBuffer(target, vbo); getError();
        glBufferSubData(target, offset*sizeof(T), sizeof(T), &value);
    }
    template<class T>
    void Vbo::update(std::vector<T> &&data, int offset) {
        glBindBuffer(target, vbo); getError();
        glBufferSubData(target, offset*sizeof(T), sizeof(T)*data.size(), data.data());
    }

}