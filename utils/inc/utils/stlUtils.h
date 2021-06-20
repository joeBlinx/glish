//
// Created by stiven on 17-10-29.
//

#ifndef ALLPROJECT_STLUTILS_H
#define ALLPROJECT_STLUTILS_H

#include <istream>
#include <optional>
namespace utils {
    template<class T>
    std::istream &operator>>(std::istream &istream, std::optional<T> &value) {
        T temp;
        istream >> temp;;
        value = temp;
        return istream;
    }

    template <class T>
    std::optional<T> operator+(std::optional<T> const & value1, T && value2){
        return *value1 + std::forward<T>(value2);
    }
    template <class T>
    std::optional<T> operator+(T && value2, std::optional<T> const & value1){
        return *value1 + std::forward<T>(value2);
    }
    template <class T>
    std::optional<T> operator-(std::optional<T> const & value1, T && value2){
        return *value1 - std::forward<T>(value2);
    }
    template <class T>
    std::optional<T> operator-(T && value2, std::optional<T> const & value1){
        return std::forward<T>(value2) - *value1 ;
    }
}
#endif //ALLPROJECT_STLUTILS_H
