//
// Created by stiven on 17-10-30.
//
#include <utils/glmAdd.h>
bool operator<=(glm::vec3 const & a, glm::vec3 const & b){
    return a.x <= b.x && a.y <= b.y && a.z <= b.z;
}