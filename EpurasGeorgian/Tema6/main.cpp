 #include <iostream> 
using namespace std; 

class Parinte
{

public:
  Parinte(const std::string &nume):
  nume(nume)
  {
  }
  void afiseazaNume()
  {
    std::cout << " Numele parintelui: "<< nume << "\n";
  }

  private :
  std::string nume;
};

class Copil
{
public:
  explicit Copil(Parinte *parinte,const std::string &nume):
  parinte(parinte),
  nume(nume)
  {

  }

  private :
  std::unique_ptr<Parinte> parinte;
  std::string nume;
};

int main() 
{ 
    std::unique_ptr<Parinte> parinte1( new Parinte("Parinte1"));
    std::unique_ptr<Parinte> parinte2( new Parinte("Parinte2"));
    //parinte2 = parinte1; da eroare,ii unique pointer,deci nu se poate copia
    parinte2->afiseazaNume();
    return 0;


} 

