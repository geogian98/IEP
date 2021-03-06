#include <memory>
#include <iostream>
#include <string>


//ITEM 13, am folosit unique_ptr in loc de auto_ptr 


class ContBancar{
	
	public: ContBancar(const std::string &nume);
		void tranzactie(int v);
		void extrasBancar();
		friend void activeaza(ContBancar&);
		friend void dezactiveaza(ContBancar&);
		bool isActive(){ return active;};
		int getDepozit(){ return depozit;}
		std::string getPosesor(){ return posesor;}
		
private: std::string posesor;
	 int depozit;
	 bool active ;

};

ContBancar::ContBancar(const std::string& nume): posesor(nume), depozit(0), active(false) { 
std::cout << " \n S-a creat un cont bancar, posesorul fiind: "<< nume << "\n";
}
void ContBancar::tranzactie(int v){

	if(active){
		if (v > 0){
			depozit += v;
			std::cout << "S-a efectuat o depunere de " << v << "lei in contul posesorului: " << posesor << "\n";
		}
		if(v < 0 ){
			depozit += v;
			std::cout << "S-a efectuat o retragere de "<< v << "lei \n";
		}
			
		std::cout << "In contul curent aveti :  "<< depozit << "lei\n";
	}
	else{
		std::cout << "Contul nu e activat \n";
	}
	
}

void ContBancar::extrasBancar(){

	if(!active){
	std::cout << " Cont blocat/ dezactivat \n";
	}
	std::cout << " Posesorul cardului: "<< posesor << "\n";
	std::cout << " In cont aveti: "<< depozit << "lei \n";
}


void activeaza(ContBancar& cont){cont.active = true;std::cout << "Cont activat \n";}
void dezactiveaza(ContBancar& cont){cont.active = false;std::cout << "Cont dezactivat \n";}



class Card{
	public:
	explicit Card(ContBancar *cb): cont(cb){
		activeaza(*cont);
	}
	~ Card(){
		dezactiveaza(*cont);
		}
	ContBancar* get(){ return cont.get();}
	
	void extras(){
		if( !cont->isActive() ){
			std::cout << " Cont blocat/ dezactivat \n";
		}
		else{
			std::cout << "\n ---EXTRAS BANCAR--- \n";
			std::cout << "Adresa cont bancar" << &cont << "\n";
			std::cout << " Posesorul cardului: "<< cont->getPosesor() << "\n";
			std::cout << " In cont aveti: "<< cont->getDepozit() << "lei \n\n";
			
		}
	}
	
		
	private:
	 std::unique_ptr <ContBancar>cont;
};

int main(){

/*
std::unique_ptr<ContBancar> c1( new ContBancar("Negrea Claudiu"));
c1->tranzactie(150);
c1->extrasBancar();

std::unique_ptr<ContBancar> c2( new ContBancar("Negrea Claudiu-Madalin"));
//c1 = c2;   Eroare
c2->extrasBancar();

//in schimb,  c1 se poate "reseta" 
c1.reset(new ContBancar("Negrea Claudiu-Madalin"));
c1->extrasBancar();

*/

Card card(new ContBancar("Cristi"));
std::cout <<"Adresa card in memorie " << &card << "\n \n";
card.get()->tranzactie(250);
card.extras();

//Card c2 = card; eroare 

return 0;
}
