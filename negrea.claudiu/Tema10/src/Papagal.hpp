#include "Pasare.hpp"

class Papagal: public Pasare{
	private:
		std::vector<std::string> cuvinte;
	public:
		Papagal();
		void adaugaCuvant(const std::string& cuvant);
		void afiseazaCuvinte();
		void zboara();
		std::string sunet();
}; 
