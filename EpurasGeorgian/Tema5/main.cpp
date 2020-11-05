 #include <iostream> 
using namespace std; 
  
class Eveniment { 

public: 
     
     std::string name;

     Eveniment(const std::string& name);

     virtual ~Eveniment()
     {
        std::cout<<"Eveniment destructor\n";
     }

    Eveniment(const Eveniment& event);

    Eveniment& operator=(const Eveniment& event);

    virtual void print() 
    { 
        std::cout << "Evenimentul se numeste "<<name << "\n"; 
    } 

   
}; 

  Eveniment::Eveniment(const std::string& name_param):
    name(name_param)
    {
            std::cout<<"Eveniment "<<name<<" constructor\n";
     }

  Eveniment::Eveniment(const Eveniment& event)
    :name(event.name)
    {
    std::cout <<"eveniment copy constructor \n";
    }

  Eveniment& Eveniment::operator=(const Eveniment& event)
  {  
    std::cout <<"Eveniment copy operator \n";
    name = event.name;
    return *this;
    }

class SubPetrecere
{
    //this class is empty
    public:
     void print()
    {
      std::cout <<"SubPetrecere print\n";
    }
};

class Petrecere : public Eveniment { 
public: 

     int membri;
     SubPetrecere* subPetrecere;

     Petrecere(const std::string& name,const int membri,SubPetrecere* sub);

    virtual ~Petrecere()
     {
        std::cout<<"Petrecere "<<name<<" destructor\n";
     }

    Petrecere(const Petrecere& petrecere);
    Petrecere& operator=(const Petrecere& petrecere);

    void print() 
    { 
        std::cout<<"Petrecerea "<<name<<" are "<<membri<<"membri" << "\n"; 
    } 
  
}; 

  
  Petrecere::Petrecere(const std::string& name,const int membri_param,SubPetrecere *subPetrecere_param):
  Eveniment(name),
  membri(membri_param),
  subPetrecere(subPetrecere_param)
  {
    std::cout<<"Constructor petrecere "<< name<<"\n";
  }

 Petrecere::Petrecere(const Petrecere& petrecere )
  :Eveniment(petrecere),
  membri(petrecere.membri),
  subPetrecere(petrecere.subPetrecere)
  { 
    std::cout <<"Petrecere copy constructor \n";
  }

  Petrecere& Petrecere::operator=(const Petrecere& petrecere)
  {
    if(this == &petrecere) return *this;

    delete subPetrecere;
    subPetrecere = new SubPetrecere(*petrecere.subPetrecere);

    Eveniment::operator=(petrecere); // asign base class
    membri = petrecere.membri;
    subPetrecere = petrecere.subPetrecere;
      std::cout <<"Petrecere copy operator "<<name<<"\n";
    return *this;
 }


int main() 
{ 
    Petrecere petrecere("Party1",20,NULL); 
    Petrecere petrecere2("Party2",220,NULL); 
    petrecere2.print();

    petrecere2 = petrecere;

    Eveniment* event; 
    event = &petrecere; 
    event->print(); 

  } 

