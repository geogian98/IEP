#include "Gaina.hpp"

Gaina::Gaina(){
	std::cout << "Constructor gaina \n" ;
}
int Gaina::numar_gaini = 0;

Gaina * Gaina::creareGaina(){
			if (numar_gaini < 30){
				numar_gaini++;
				return new Gaina();
			}
			else{
				return nullptr;
				//throw logic_error("Nu se mai pot crea instante");
			}
		
		}

 int Gaina::getGaini(){ 
	return numar_gaini;
}
		
		
void Gaina::zboara(){ 
	std::cout << " zboara gaina (mai putin de 10 m)" << "\n";
}
std::string Gaina::sunet(){
	std::cout << "Gaina face cotcodac \n";
	return "cotccodac" ;
}
		
void Gaina::vanzare(Pasare& p){
	std::cout << "Gaina a fost vanduta pe o pasare \n";
}
void Gaina::decrementare(){
	numar_gaini--;
}

Gaina::~Gaina(){
	decrementare();
}
		
	
	

