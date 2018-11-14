#version 330 core
out vec4 color;
uniform vec2 col;

uniform int is_select;
void main() {

    color = vec4(col[0], 0, 0, 1);
    if(is_select == 1){
        color = vec4(1, 0, 0, 1);
    }
}
