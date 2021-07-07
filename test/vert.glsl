#version 450 core

layout(location = 0) in float tess_level_in;
layout(location = 1) in vec4 pos;
out float tess_level;
void main(){
    gl_Position =  pos;
    tess_level = tess_level_in;
}