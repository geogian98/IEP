#include "Papagal.hpp"

#include <vector>


void Papagal::adaugaCuvant(const std::string& str)
	{ 
		cuvinte.push_back(str);
	}

void Papagal::afiseazaCuvinte(){

	std::cout << "cuvintele stiute de papagal: "; 

	for(size_t i = 0; i < cuvinte.size() ; i++)	
	{
		
		std::cout << cuvinte[i] << " ";
	}

	std::cout << "\n";			
	}

void Papagal::zboara(){ std::cout << "papagalul zboara \n" << "\n"; }

void Papagal::sunet(){ 	std::cout << "papagal...cra cra...ham ham...miau miau" << "\n";}

