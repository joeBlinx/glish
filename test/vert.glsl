#version 400
layout(location = 0) in vec2 pos;
layout(location = 1) in vec2 uv_in;

out vec2 uv;
void main(){

    gl_Position =  vec4(vec3(pos, 0), 1);
    uv = uv_in;
}