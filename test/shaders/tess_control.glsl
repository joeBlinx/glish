#version 450 core

layout(vertices = 3) out;
in float tess_level[32];
void main() {
    if(gl_InvocationID == 0){

        gl_TessLevelInner[0] = tess_level[0];
        gl_TessLevelOuter[0] = tess_level[0];
        gl_TessLevelOuter[1] = tess_level[0];
        gl_TessLevelOuter[2] = tess_level[0];
    }
    gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;
}
