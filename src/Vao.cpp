//
// Created by stiven on 10/19/18.
//

#include "glish3/Vao.hpp"
#include <cassert>
#include "glish3/programGL.hpp"

namespace glish3 {

    Vao::Vao(ProgramGL const &progam_gl) :
    _vao(make_unique_vao()),
    _attributes(progam_gl.gather_attributes())
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


    void Vao::set_attrib(std::string_view index_name, int offset, int size) {
        GLint index = _attributes.at(std::string(index_name));
        glEnableVertexArrayAttrib(_vao.get(), index);
        glVertexArrayAttribFormat(_vao.get(), index, size,
                                  GL_FLOAT, GL_FALSE,
                                  offset);
    }

    void Vao::add_vbo(buffer &&vbo, int binding_point) {
        glVertexArrayVertexBuffer(_vao.get(), binding_point, (GLuint)vbo, 0, _stride);
        _vbos.push_back(std::move(vbo));
    }

    void Vao::bind_vbo(int binding_point) {
        std::ranges::for_each(_attributes, [&](auto const pair){
            auto const& [key, value] = pair;
            glVertexArrayAttribBinding(_vao.get(), value, binding_point);
        });
    }


}