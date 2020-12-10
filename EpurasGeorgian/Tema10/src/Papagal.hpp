#include "Pasare.hpp"

class Papagal: public Pasare{
	private:
		std::vector<std::string> cuvinte;
	public:
		void zboara();
		void sunet();
		void adaugaCuvant(const std::string& cuv);
		void afiseazaCuvinte();
	
}; 
