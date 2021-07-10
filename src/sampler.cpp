//
// Created by stiven.aigle on 21/07/09.
//
#include "glish3/sampler.hpp"

namespace glish3{
    sampler::sampler():_sampler(make_unique_sampler()) {

    }

    void sampler::bind(GLuint unit) const{
        glBindSampler(unit, _sampler);
    }

    void sampler::parameter(GLenum name, GLint param) const {
        glSamplerParameteri(_sampler, name, param);
    }

    void sampler::linear() const {
        parameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        parameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }

    void sampler::nearest() const {
        parameter(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        parameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }

    void sampler::repeat() const {
        parameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
        parameter(GL_TEXTURE_WRAP_R, GL_REPEAT);
        parameter(GL_TEXTURE_WRAP_S, GL_REPEAT);

    }

    void sampler::clamp_to_edge() const {
        parameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        parameter(GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
        parameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    }
}
