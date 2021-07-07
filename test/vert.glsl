#version 450 core

layout(location = 0) in float tess_level_in;
layout(location = 1) in vec4 pos;
out float tess_level;
void main(){
    const vec4 positions[3] = vec4[3](
        vec4(0.25, -0.25, 0.5, 1.0),
        vec4(-0.25, -0.25, 0.5, 1.0),
        vec4(0.25, 0.25, 0.5, 1.0)
        );
    gl_Position =  pos;
    tess_level = tess_level_in;
}