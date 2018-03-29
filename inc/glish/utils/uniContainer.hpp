//
// Created by Stiven on 28-Mar-18.
//

#ifndef INC_2DENGINE_UNICONTAINER_HPP
#define INC_2DENGINE_UNICONTAINER_HPP

#include <map>
#include <memory>
#include <glish/uniBase.hpp>
#include <glish/program/Program.hpp>
#include <glish/Uniform.hpp>
#include <utility>

namespace glish {
	class UniContainer {

		std::map<std::string, std::unique_ptr<UniBase> > uniforms;
		Program prog;
	public:
		template <class ...Args>
		UniContainer(Args && ...args):prog(std::forward<Args>(args)...){}

		template <class T>
				void add(std::string && nameUni){
			uniforms.insert(std::pair<std::string, std::unique_ptr<UniBase>{nameUni, new Uniform<T>{&prog, nameUni}});
		}

		UniBase &operator[](std::string && uniform);

		void use();

		template<class TypeUniform, class ...Ts>
				void update(std::string && name, TypeUniform && value, Ts && ... args) {
			auto it = uniforms.find(name);
					if(it != uniforms.end()){
						**it = std::move(value);
					}else{
						std::cerr << "the key " << name << " doesn't exist and will be ignored\n"
					}

					if constexpr (sizeof...(args) >= 2){
						update(std::forward<Ts>(args)...);
					}


		}
	};
}


#endif //INC_2DENGINE_UNICONTAINER_HPP
