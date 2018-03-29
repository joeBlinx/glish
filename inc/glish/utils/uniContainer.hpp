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
			std::string a = nameUni;
			uniforms.insert(std::make_pair(a, std::make_unique<Uniform<T>>(&prog, std::move(nameUni))));
		}

		UniBase &operator[](std::string && uniform);

		void use();


		template<class TypeUniform>
		void update(std::string && name, TypeUniform && value) {

			auto it = uniforms.find(name);
			if(it != uniforms.end()){
				(uniforms[std::move(name)])->updateProg(&prog);
				*(uniforms[std::move(name)]) = (std::move(value));
			}else{
				std::cerr << "the key " << name << " doesn't exist and will be ignored\n";
			}
		}
		template<class TypeUniform, class ...Ts>
				void update(std::string && name, TypeUniform && value, Ts && ... args) {
			auto it = uniforms.find(name);

					update(std::move(name), std::move(value));
					update(std::forward<Ts>(args)...);



		}
	};
}


#endif //INC_2DENGINE_UNICONTAINER_HPP
