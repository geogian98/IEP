 #include <iostream> 
using namespace std; 
#include <mutex>
#include <thread>


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

  std::string getNume()
  {
    return nume;
  }
  private :
  std::string nume;
};

class Copil
{
public:
  explicit Copil(Parinte *parinte,const std::string &nume):
  parinte(parinte),
  nume(nume),
  isAdult(false),
  varsta(0)
  {
      std::cout<<"S-a nascut "<<nume<<"\n";
  }

  ~Copil()
  {
    std::cout<<"Copilul "<<nume<<" dispare(destructor) \n";
  }

  Parinte* getParinte(){ return parinte.get();}

  void adaugaAni(int ani_param)
  {
      varsta += ani_param;
       if(varsta > 70)
      {
        std::cout<<nume<<" este batran/a \n";
        return;
      }
      if(varsta >= 18)
      {
            std::cout<<"Copilul "<<nume<<" este major \n";
            return;
      }
     
  }

  void afiseazaNumeParinte()
  {
    parinte->afiseazaNume();
  }

  std::string getNumeParinte()
  {
    return parinte->getNume();
  }

  int getVarsta()
  {
    return varsta;
  }

  std::string getNume()
  {
    return nume;
  }

  private :
  int varsta;
  bool isAdult;
  std::unique_ptr<Parinte> parinte;
  std::string nume;
};

void afiseazaInfo(Copil& copil)
{
  std::string numeCopil = copil.getNume();
  std::string numeParinte = copil.getNumeParinte();
  int varstaCopil = copil.getVarsta();
  std::cout<<numeCopil<<" are varsta de  "<<varstaCopil<<" si este fiul lui "<<numeParinte<<"\n";
}

int main() 
{ 
   
    Copil copil1(new Parinte("ION"),"Gogu");
    copil1.adaugaAni(5);
    copil1.afiseazaNumeParinte();//am facut aceasta metoda pentru a fi mai usor de folosit,
    //in locul acesteia se putea folosii copil1.getParinte()->afiseazaNume();

    afiseazaInfo(copil1);
   
    return 0;

} 





