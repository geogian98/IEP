#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Pasare{
	public:
		void virtual zboara() = 0;
		string virtual sunet() = 0; 

};

class Papagal : public Pasare{
	public:
		void adaugaCuvant(const std::string& str){
			cuvinte.push_back(str);
		}
		void afiseazaCuvinte(){
			cout << "Acest papagal stie urmatoarele cuvinte: "; 
			for(size_t i = 0; i < cuvinte.size() ; i++){
				cout << cuvinte[i] << " ";
			}
			cout << endl;			
		}
		void zboara(){ cout << "zboara" << "\n";}
		string sunet(){ return "papagal" ;}

	private:
		vector<string> cuvinte;
};

class Gaina : public Pasare{
	public:
		Gaina()
		{
			static int nrgaini = 0;
			nrgaini++;
			if( nrgaini > 30){
				throw logic_error("Nu se mai pot crea instante");
			}
		
		}
		
		void zboara(){ cout << "zboara gaina (mai putin de 10 m)" << "\n";}
		string sunet(){ return "gaina" ;}
		
		void vanzare(Pasare& p){
			cout << "Gaina a fost vanduta pe o pasare \n";
		}

	
};




















int main(){
	
	Papagal papagal = Papagal();
	papagal.adaugaCuvant("salut");
	papagal.afiseazaCuvinte();
	
	Gaina gaina = Gaina();
	gaina.zboara();
	gaina.vanzare(papagal);
	return 0;
}
