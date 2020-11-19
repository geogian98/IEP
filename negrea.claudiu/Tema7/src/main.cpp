#include <memory>
#include <iostream>
#include <string>


//ITEM 22 DECLARE DATA MEMBERS PRIVATE


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
	
	void tranzactie(int suma){
		get()->tranzactie(suma);
	}
	
		
	private:
	 std::unique_ptr <ContBancar>cont;
	 ContBancar* get(){ return cont.get();}
};







int main(){



Card card(new ContBancar("Cristi"));
std::cout <<"Adresa card in memorie " << &card << "\n \n";
//card.get()->tranzactie(250);
card.tranzactie(200);   // easier to call
card.extras();                

ContBancar* c3 = new ContBancar("Cristian");
Card card2(c3);
//card2.get()->tranzactie(1250);

card2.tranzactie(150);;
card2.extras();

return 0;
}
