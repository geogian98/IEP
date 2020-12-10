#include "Pasare.hpp"
#include "Gaina.hpp"

#ifndef STRUT_HPP
#define STRUT_HPP

class Strut: public Pasare{
	private:
		static Strut *strut;
		int gaini;
		Strut();
		Strut(Strut const&);
		void operator=(Strut const&);

	public:
		static Strut * creareStrut();
		Strut * operator+ (const Gaina& g);
		int getGaini();
		void zboara();
		std::string sunet();

};

#endif
