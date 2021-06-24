//
// Created by stiven on 21/06/2021.
//

#ifndef GLISH3_UNIQUE_VAO_HPP
#define GLISH3_UNIQUE_VAO_HPP
namespace glish3 {
    struct UniqueVao {
        UniqueVao() = default;
        UniqueVao(GLuint vao) noexcept: _vao(vao) {}

        UniqueVao(UniqueVao const &) = delete;
        UniqueVao &operator=(UniqueVao const &) = delete;

        UniqueVao(UniqueVao &&old) noexcept : _vao(old._vao) { old._vao = 0; }
        UniqueVao &operator=(UniqueVao &&old) noexcept {
            _vao = old._vao;
            old._vao = 0;
            return *this;
        }

        ~UniqueVao() {
            if (_vao != 0) {
                glDeleteVertexArrays(1, &_vao);
            }
        }
        GLuint get() const{ return _vao;}
    private:
        GLuint _vao{};
    };
    inline UniqueVao make_unique_vao(){
        GLuint vao;
        glCreateVertexArrays(1, &vao);
        return {vao};
    }
}
#endif //GLISH3_UNIQUE_VAO_HPP
