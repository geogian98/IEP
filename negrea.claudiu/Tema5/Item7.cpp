#include <string>
#include <iostream>


class Polygon{ 
    protected:
                int *values; //
                std::string name;
    
    public: Polygon(const std::string& type, int *array);
    
            //virtual destructor because we intend to use this class as polymorphic base class and it has a virtual function
            virtual ~Polygon();
            
            Polygon(const Polygon& rhs);
            Polygon& operator=(const Polygon& rhs);
            
            void virtual print(){
                std::cout << "Print from base class" << name;
            }
};


Polygon::Polygon(const std::string& type, int *array )
    :name(type),
    values(array)
    {
    
    }


Polygon::~Polygon(){
  std::cout << name << " object destroyed " << "\n";
}

Polygon::Polygon(const Polygon& rhs )
:name(rhs.name),
values(rhs.values){
    
    std::cout <<"Polygon copy constructor \n";
}

Polygon& Polygon::operator=(const Polygon& rhs){
    
    std::cout <<"Polygon copy assignement operator \n";
    name = rhs.name;
    values = rhs.values;
    return *this;
}



class Square : public Polygon{
    
    public : 
            Square(int array[]) : Polygon("square", array) {};
            Square(const Square& rhs);
            Square& operator=(const Square& rhs);
            void print(){
                std::cout << "Print from derived class " << name<<  "\n" ;
                std::cout << "Print edges : ";
                for(int i = 0; i<4; i++){
                    std::cout << values[i] << " " ;
                }
                std::cout << "\n";
            }
    
};


Square::Square(const Square& rhs )
:Polygon(rhs){ //invoke base class constructor
    
    std::cout <<"Square copy constructor \n";
}

Square& Square::operator=(const Square& rhs){
    
    Polygon::operator=(rhs); // asign base class
      std::cout <<"Square copy assignement operator \n";
    return *this;
}


class Rectangle : public Polygon{
    public : Rectangle(int array[]) : Polygon("rectangle", array) {};
            void print(){
                std::cout << "Print from derived class " << name <<  "\n" ;
                std::cout << "Print edges : ";
                for(int i = 0; i<4; i++){
                    std::cout << values[i] << " ";
                }
                std::cout << "\n";
            }
    
};

int main(){
    
  int array[4] = {2, 2, 2, 2};
  int array1[4] = {4, 2, 4, 2};
  int array2[4] = {4, 4, 4, 4};
  
  Square sq(array);
  Square sq2(array2);
  Rectangle rect(array1);
  
  sq2 = sq;
   // out: 
   // Polygon copy assignement operator 
   //  "Square copy assignement operator 
  
  Polygon * p;
  p = &sq;
  p->print();
  
  p = &rect;
  p->print();

    return 0;
}
