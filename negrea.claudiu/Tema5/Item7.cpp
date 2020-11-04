  
#include <string>
#include <iostream>


class Polygon{ 
    protected:
                int *values; //
                std::string name;
    
    public: Polygon(const std::string& type, int *array);
    
            //virtual destructor because we intend to use this class as polymorphic base class and it has a virtual function
            virtual ~Polygon();
            
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


class Square : public Polygon{
    public : Square(int array[]) : Polygon("square", array) {};
            void print(){
                std::cout << "Print from derived class " << name<<  "\n" ;
                std::cout << "Print edges : ";
                for(int i = 0; i<4; i++){
                    std::cout << values[i] << " " ;
                }
                std::cout << "\n";
            }
    
};

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
  Square sq(array);
  Rectangle rect(array1);
  
  Polygon * p;
  p = &sq;
  p->print();
  
  p = &rect;
  p->print();

    return 0;
}



