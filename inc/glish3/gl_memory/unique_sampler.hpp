//
// Created by stiven.aigle on 21/07/09.
//

#ifndef GLISH3_UNIQUE_SAMPLER_H
#define GLISH3_UNIQUE_SAMPLER_H
#include "glish3/gl_glew.hpp"
namespace glish3 {
    struct UniqueSampler {
        UniqueSampler() = default;
        UniqueSampler(GLuint id) noexcept: _id(id) {}

        UniqueSampler(UniqueSampler const &) = delete;
        UniqueSampler &operator=(UniqueSampler const &) = delete;

        UniqueSampler(UniqueSampler &&old)noexcept : _id(old._id) { old._id = 0; }
        UniqueSampler &operator=(UniqueSampler &&old) noexcept {
            _id = old._id;
            old._id = 0;
            return *this;
        }

        ~UniqueSampler() {
            if (_id != 0) {
                glDeleteSamplers(1, &_id);
            }
        }
        GLuint get() const{ return _id;}
        operator GLuint() const{return get();}

    private:
        GLuint _id{};
    };
    inline UniqueSampler make_unique_sampler(){
        GLuint sampler;
        glCreateSamplers(1, &sampler);
        return {sampler};
    }
}
#endif //GLISH3_UNIQUE_SAMPLER_H
