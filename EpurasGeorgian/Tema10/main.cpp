#include "src/Papagal.hpp"
#include "src/Strut.hpp"

int main(){

	Papagal pap = Papagal();
	pap.adaugaCuvant("sunt papagal");
	pap.adaugaCuvant("am penele colorate");
	pap.afiseazaCuvinte();
	
	Gaina * gaina = Gaina::newGaina();
	gaina->zboara();
	gaina->sunet();
	gaina->vanzare(pap);
	
	Strut *strut = Strut::newStrut();
	strut->zboara();
	strut->sunet();
	
	std::cout << "\n Before \n"; 
	std::cout << "Nr gaini: " << strut->getGaini() << " gaini \n"; 
	strut = *strut + *gaina;
	std::cout << "\n Dupa o adunare a unui strut cu o gaina \n"; 
	std::cout << "Sunt: " << strut->getGaini() << " gaini \n\n"; 
	
	return 0;
}
