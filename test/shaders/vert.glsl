#version 450 core

layout(location = 1) in vec4 pos;

void main(){
    gl_Position =  pos;
}