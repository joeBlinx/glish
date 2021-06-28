//
// Created by stiven on 10/19/18.
//

#include <glish3/Vao.hpp>

namespace glish3 {
    Vao::Vao():
    _vao(make_unique_vao())
    {}

    void Vao::bind() const{
        glBindVertexArray(_vao.get());
    }

    Vao::operator bool() const {
        return (bool)_vao.get();
    }

    Vao::operator GLuint() {
        return _vao.get();
    }


    void Vao::set_attrib(const buffer &vbo, int stride, const attrib_settings &settings) {

        glVertexArrayVertexBuffer(_vao.get(), 0, (GLuint)vbo, 0, stride*vbo._size_of_data);
        glEnableVertexArrayAttrib(_vao.get(), settings.index);
        glVertexAttribBinding(settings.index, 0);
        glVertexAttribFormat(settings.index, settings.size,
                              GL_FLOAT, GL_FALSE,
                             settings.offset*vbo._size_of_data);
    }



}