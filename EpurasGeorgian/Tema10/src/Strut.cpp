#include "Strut.hpp"

//constructor
Strut::Strut():gaini(0) {}
Strut * Strut::strut = nullptr;

Strut * Strut::newStrut(){
	if (! strut){
			strut = new Strut;
	}
	return strut;
}

void Strut::zboara(){
	std::cout << "Strutul zboara \n";
}
void Strut::sunet(){
	std::cout << "Nu stiu ce suntet scoate strutul,dar sa stiti ca am sa ma duc la zoo ca sa aflu! \n";
}
int Strut::getGaini(){
	return gaini;
}
Strut * Strut::operator +(const Gaina &g){
	Strut::newStrut()->gaini++;
	Gaina::decrementare();
	return Strut::newStrut();


}
