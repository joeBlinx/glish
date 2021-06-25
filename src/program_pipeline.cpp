//
// Created by stiven on 25/06/2021.
//

#include "glish3/program_pipeline.hpp"


void glish3::ProgramPipeline::use_stage(const glish3::ProgramGL &program)const {
    glUseProgramStages(_pipeline, program.get_types(), (GLuint)program);
}

void glish3::ProgramPipeline::bind() const {
    glBindProgramPipeline(_pipeline);
}
