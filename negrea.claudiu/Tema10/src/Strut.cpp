#include "Strut.hpp"

//constructor
Strut::Strut():gaini(0) {}
Strut * Strut::strut = nullptr;

Strut * Strut::creareStrut(){
	if (! strut){
			strut = new Strut;
	}
	return strut;
}

void Strut::zboara(){
	std::cout << "Strutul zboara \n";
}
std::string Strut::sunet(){
	std::cout << "Strutul face sunete \n";
	return "Strut";
}
int Strut::getGaini(){
	return gaini;
}
Strut * Strut::operator +(const Gaina &g){
	Strut::creareStrut()->gaini++;
	Gaina::decrementare();
	return Strut::creareStrut();


}
