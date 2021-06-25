//
// Created by stiven on 25/06/2021.
//

#ifndef GLISH3_UNIQUE_PROGRAM_PIPELINE_HPP
#define GLISH3_UNIQUE_PROGRAM_PIPELINE_HPP
#include <glish3/gl_glew.hpp>
namespace glish3 {
    struct UniqueProgramPipeline {
        UniqueProgramPipeline(GLuint pipeline_program) noexcept: _pipeline_program(pipeline_program) {}

        UniqueProgramPipeline(UniqueProgramPipeline const &) = delete;
        UniqueProgramPipeline &operator=(UniqueProgramPipeline const &) = delete;

        UniqueProgramPipeline(UniqueProgramPipeline &&old) noexcept : _pipeline_program(old._pipeline_program) { old._pipeline_program = 0; }
        UniqueProgramPipeline &operator=(UniqueProgramPipeline &&old) noexcept {
            _pipeline_program = old._pipeline_program;
            old._pipeline_program = 0;
            return *this;
        }

        ~UniqueProgramPipeline() {
            if (_pipeline_program != 0) {
                glDeleteProgramPipelines(1, &_pipeline_program);
            }
        }
        GLuint get() const{ return _pipeline_program;}
        operator GLuint() const{return get();}

    private:
        GLuint _pipeline_program{};
    };
    inline UniqueProgramPipeline make_unique_gl_program(){
        GLuint program_pipeline{};
        glCreateProgramPipelines(1, &program_pipeline);
        return {program_pipeline};
    }
}
#endif //GLISH3_UNIQUE_PROGRAM_PIPELINE_HPP
