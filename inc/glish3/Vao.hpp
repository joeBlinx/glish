//
// Created by stiven on 10/16/18.
//

#ifndef GLISH3_VAP_H
#define GLISH3_VAP_H

#include <glish3/gl_glew.hpp>
#include <vector>
#include <glish3/buffer.hpp>
#include <array>
#include "glish3/gl_memory/unique_vao.hpp"
#include <algorithm>
#include <string_view>
#include <map>

namespace glish3{

    struct ProgramGL;
    template<class ...Ts>
    struct Format{
        static constexpr int stride = sizeof(std::tuple<Ts...>);
        static constexpr std::array offset{0ul, sizeof(Ts)...};
        static constexpr int size = sizeof...(Ts);
        std::array<std::string_view, size> index_names;
        std::array<int, size> size_of_data;
    };

    class Vao{
        UniqueVao _vao;
        std::vector<buffer> _vbos;
        std::map<std::string, GLint> _attributes;
        int _stride{};
        void set_attrib(std::string_view index_name, int offset, int size);

    public:

        explicit Vao(ProgramGL const &progam_gl);
        void bind() const;

        template<class ...Types>
        void set_attrib(Format<Types...> const& format){
            _stride = format.stride;
            std::array<int, format.size> indices;
            std::ranges::generate(indices, [i = 0]()mutable{
                return i++;
            });
            for(auto const i : indices){
                set_attrib(format.index_names[i], format.offset[i], format.size_of_data[i]);
            }
        }

        void add_vbo(buffer && vbo, int binding_point);
        void bind_vbo(std::string_view index_name, int binding_point);
        operator bool() const;

        operator GLuint();

    };

}
#endif //GLISH3_VAP_H
