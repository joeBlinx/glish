#version 450 core

layout (location = 1) in vec4 pos;
layout (location = 0) in vec2 uv;

out VS_OUT{
    vec2 uv;
}vs_out;

void main(){
    gl_Position =  pos;
    vs_out.uv = uv;
}