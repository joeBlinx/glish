#version 400
layout(location = 0) in vec2 pos;
layout(location = 1) in vec2 uv_in;


uniform mat3 view;
out vec2 uv;
void main(){

    gl_Position =  vec4(view*vec3(60*pos, 1), 1);
    uv = uv_in;
}