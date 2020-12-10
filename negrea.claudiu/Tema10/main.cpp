#include "src/Papagal.hpp"
#include "src/Strut.hpp"

int main(){
	Papagal pap = Papagal();
	pap.adaugaCuvant("salut");
	pap.afiseazaCuvinte();
	
	Gaina * gaina = Gaina::creareGaina();
	gaina->zboara();
	gaina->sunet();
	gaina->vanzare(pap);
	
	Strut *strut = Strut::creareStrut();
	strut->zboara();
	strut->sunet();
	
	Gaina * gaini[10];
	for(int i = 0; i < 10; i++){
		gaini[i] = Gaina::creareGaina();
	}
	std::cout << "\n Inceput \n"; 
	std::cout << "Sunt: " << strut->getGaini() << " gaini \n"; 
	strut = *strut + *gaina;
	std::cout << "\n Dupa o adunare \n"; 
	std::cout << "Sunt: " << strut->getGaini() << " gaini \n\n"; 
	
	
	for(int i = 0; i < 10; i++){
		strut = *strut + *gaini[i];
	}
	std::cout << "Dupa 11 adunari sunt: " << strut->getGaini() << " gaini \n"; 
	return 0;
}
