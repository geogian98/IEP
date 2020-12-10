#include "Papagal.hpp"

#include <vector>


Papagal::Papagal(){  std::cout << "Constructor papagal \n "; }

void Papagal::adaugaCuvant(const std::string& str){   cuvinte.push_back(str); }

void Papagal::afiseazaCuvinte(){
	std::cout << "Acest papagal stie urmatoarele cuvinte: "; 
	for(size_t i = 0; i < cuvinte.size() ; i++){
		std::cout << cuvinte[i] << " ";
		}
	std::cout << "\n";			
	}

void Papagal::zboara(){ std::cout << "papagalul zboara \n" << "\n"; }

std::string Papagal::sunet(){ 	return "sunt un papagal" ;}

