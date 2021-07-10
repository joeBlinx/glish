//
// Created by stiven.aigle on 21/07/09.
//

#ifndef GLISH3_SAMPLER_H
#define GLISH3_SAMPLER_H

#include "glish3/gl_memory/unique_sampler.hpp"
#include <GL/glew.h>

namespace glish3{
    struct sampler{

        sampler();
        void bind(GLuint unit) const;
        void parameter(GLenum name, GLint param) const;
        void linear() const;
        void nearest() const;

        void repeat() const;
        void clamp_to_edge() const;
    private:
        UniqueSampler _sampler{};
    };
}
#endif //GLISH3_SAMPLER_H
