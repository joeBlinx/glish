#version 450 core

layout(binding = 1) uniform atomic_uint area;
void main() {
    atomicCounterIncrement(area);
}