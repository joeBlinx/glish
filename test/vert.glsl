#version 330
layout(location = 0) in vec2 pos;
layout(location = 1) in vec2 b;


out vec2 c;
void main(){

    gl_Position =  vec4(vec3(pos, 0), 1);
    //c = pos;
    c = b;//vec2(0.2, 0);
}