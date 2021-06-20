//
// Created by stiven on 17-10-29.
//

#ifndef ALLPROJECT_TYPE_TRAIT_H
#define ALLPROJECT_TYPE_TRAIT_H

#include <optional>

namespace utils{

    template <class T>
    struct is_optional{
        static constexpr bool value = false;
    };

    template<class T>
    struct is_optional <std::optional<T>>{
        static constexpr bool value = true;
    };
    template<class T>
    struct is_optional <std::optional<T>&>{
        static constexpr bool value = true;
    };
}
#endif //ALLPROJECT_TYPE_TRAIT_H
