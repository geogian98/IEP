#include "Gaina.hpp"

int Gaina::gaini = 0;

Gaina::Gaina(){}

Gaina * Gaina::newGaina(){
			if (gaini < 30){
				gaini++;
				return new Gaina();
			}
			else{
				return nullptr;
			}
		
		}

 int Gaina::getGaini(){ 
	return gaini;
}
		
		
void Gaina::zboara(){ 
	std::cout << "gaina zboara" << "\n";
}
void Gaina::sunet(){
	std::cout << "cot co dac \n";
}
		
void Gaina::vanzare(Pasare& p){
	std::cout << "Gaina a fost vanduta \n";
}
void Gaina::decrementare(){
	gaini--;
}

Gaina::~Gaina(){
	decrementare();
}
		
	
	

