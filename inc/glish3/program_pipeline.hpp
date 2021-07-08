//
// Created by stiven on 25/06/2021.
//

#ifndef GLISH3_PROGRAM_PIPELINE_HPP
#define GLISH3_PROGRAM_PIPELINE_HPP
#include "glish3/gl_memory/unique_program_pipeline.hpp"

namespace glish3{
    struct ProgramGL;
    struct ProgramPipeline{
        void use_stage(ProgramGL const& program) const;
        void bind() const;
    private:
        UniqueProgramPipeline _pipeline{make_unique_pipeline()};
    };
}
#endif //GLISH3_PROGRAM_PIPELINE_HPP
