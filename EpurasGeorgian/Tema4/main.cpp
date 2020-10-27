#include<string>
#include<iostream>

class Uncopyable 
{
	protected: // allow construction
		Uncopyable() {} // and destruction of
		~Uncopyable() {} // derived objects...
	private:
		Uncopyable(const Uncopyable&); // ...but prevent copying
		Uncopyable& operator=(const Uncopyable&);
};

class Persoana : private Uncopyable
{
	public : Persoana(const std::string& Nume,const std::string& Prenume,const std::string& CNP);
	 ~Persoana();
	 void afisareDate();

	 private :  std::string Nume;
	 			std::string Prenume;
	 			std::string CNP;

};

Persoana::Persoana(const std::string& nume,const std::string& prenume,const std::string& cnp):
	Nume(nume),
	Prenume(prenume),
	CNP(cnp)
{}
Persoana::~Persoana()
{
	std::cout<<"O persoana a fost stearsa";
}

void Persoana::afisareDate()
{
	std::cout<<Nume+" "+Prenume+" "+CNP+"\n";
}

int main()
{
	 Persoana p1("Epuras","Georgian","12345");
	 p1.afisareDate();
	 return 0;
}

