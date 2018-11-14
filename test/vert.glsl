#version 330
layout(location = 0) in vec2 pos;

uniform vec2 posChange;
uniform vec2 size;
void main(){

    mat3 tran = mat3(
        size.x, 0, 0,
        0, size.y, 0,
        posChange.x, posChange.y, 1
    );
    gl_Position =  vec4(tran*vec3(pos, 1), 1);
}