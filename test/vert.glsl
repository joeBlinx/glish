#version 450 core

layout(location = 0) in float tess_level_in;
out float tess_level;
void main(){
    const vec4 positions[3] = vec4[3](
        vec4(0.25, -0.25, 0.5, 1.0),
        vec4(-0.25, -0.25, 0.5, 1.0),
        vec4(0.25, 0.25, 0.5, 1.0)
        );
    gl_Position =  positions[gl_VertexID];
    tess_level = tess_level_in;
}