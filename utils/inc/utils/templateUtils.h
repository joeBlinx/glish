//
// Created by stiven on 17-10-29.
//

#ifndef ALLPROJECT_TEMPLATEUTILS_H
#define ALLPROJECT_TEMPLATEUTILS_H

#include <iostream>
namespace utils{
    template <class ... Ts>
    void prettyPrint(Ts && ... args){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
}
#endif //ALLPROJECT_TEMPLATEUTILS_H
