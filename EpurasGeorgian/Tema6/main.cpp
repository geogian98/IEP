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

  int getVarsta()
  {
    return varsta;
  }
  private :
  int varsta;
  bool isAdult;
  std::unique_ptr<Parinte> parinte;
  std::string nume;
};

int main() 
{ 
    std::unique_ptr<Parinte> parinte1( new Parinte("Parinte1"));
    std::unique_ptr<Parinte> parinte2( new Parinte("Parinte2"));
    //parinte2 = parinte1; da eroare,ii unique pointer,deci nu se poate copia
    parinte2->afiseazaNume();

    Copil copil1(new Parinte("padre"),"Gogu");
    copil1.getParinte() -> afiseazaNume();

    std::cout<<copil1.getVarsta()<<"\n";
    copil1.adaugaAni(19);
    std::cout<<copil1.getVarsta()<<"\n";
    copil1.adaugaAni(79);
    std::cout<<copil1.getVarsta()<<"\n";
    return 0;


} 

