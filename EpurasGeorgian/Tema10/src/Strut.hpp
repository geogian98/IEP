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
		static Strut * newStrut();
		Strut * operator+ (const Gaina& g);
		int getGaini();
		void zboara();
		void sunet();

};

#endif
