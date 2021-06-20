//
// Created by joe on 3/6/19.
//

#ifndef INC_2DENGINE_TUPLEUTILS_HPP
#define INC_2DENGINE_TUPLEUTILS_HPP
#include <tuple>
namespace utils {

	template<class Function, int n, class... Ts>
	struct apply_wrapper {
		static void apply_tuple(std::tuple<Ts...> &tuple, Function &&function1) {
			function1(std::get<n>(tuple));
			function1(std::get<n - 1>(tuple));
		}
	};

	template<class Function, class... Ts>
	struct apply_wrapper<Function, 0, Ts...> {
		static void apply_tuple(std::tuple<Ts...> &tuple, Function &&function1) {
			function1(std::get<0>(tuple));
		}
	};

	template<class ...Ts, class Function>
	void for_each_tuple(std::tuple<Ts...> &tuple, Function &&function) {
		apply_wrapper<Function, sizeof...(Ts) - 1, Ts...>::apply_tuple(tuple, std::forward<Function>(function));
	}
}
#endif //INC_2DENGINE_TUPLEUTILS_HPP
