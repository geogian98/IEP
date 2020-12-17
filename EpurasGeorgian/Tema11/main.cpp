#include <iostream>
#include <math.h>


class Punct {
    
    private : float x;
              float y;
    
    public: Punct(float xp, float yp):x(xp),y(yp){};
            Punct():x(0.0), y(0.0){};
            float getX(){ return x;}
            float getY(){ return y;}
            void setX(float newX){x = newX;}
            void setY(float newY){y = newY;}
            void printeaza(){std::cout << "Punct (" << x << ", " << y << ") \n";}
};

class Figura{
    
    float virtual perimetru() = 0;
    Punct virtual getPunct(int i) = 0;
    //Punct* virtual getPuncte() = 0;
   
};

class Triunghi:public Figura{
    
    public:
        int dim;
        Punct puncte[3];
        Triunghi(Punct a, Punct b, Punct c): dim(3){
            puncte[0] = a ;
            puncte[1] = b;
            puncte[2] = c;
        };
        int getDim(){return dim;}
        float perimetru(){ 
            float ab = sqrt(pow(puncte[0].getX() - puncte[1].getX(), 2) + pow(puncte[0].getY() - puncte[1].getY(), 2));
            float bc =sqrt(pow(puncte[1].getX()  -  puncte[2].getX(), 2) + pow(puncte[1].getY() - puncte[2].getY(), 2));
            float ca = sqrt(pow( puncte[2].getX() - puncte[0].getX(), 2) + pow(puncte[2].getY() - puncte[0].getY(), 2));
            return ab+bc+ca;
        };
        Punct getPunct(int i){ return puncte[i];};
        Punct* getPuncte(){ return puncte;};
};
class Patrat:public Figura{
    
    public:
        int dim;
        Punct puncte[4];
        Patrat(Punct a, Punct b, Punct c, Punct d):dim(4){
            puncte[0] = a ;
            puncte[1] = b;
            puncte[2] = c;
            puncte[3] = d;
        };
        
        int getDim(){return dim;}
        float perimetru(){
            float lung = sqrt(pow(puncte[0].getX() - puncte[1].getX(), 2) + pow(puncte[0].getY() - puncte[1].getY(), 2));
            float lat =sqrt(pow(puncte[1].getX()  -  puncte[2].getX(), 2) + pow(puncte[1].getY() - puncte[2].getY(), 2));
            return 2 * (lung + lat);
        };
        Punct getPunct(int i){ return puncte[i];};
        Punct* getPuncte(){ return puncte;};
    
};



template <class Figura> float panta(Figura fig){
    float x1 = fig.getPunct(0).getX();
    float y1 = fig.getPunct(0).getY();
    float x2 = fig.getPunct(1).getX();
    float y2 = fig.getPunct(1).getY();
    
    return (y2-y1) / (x2-x1);
}

class Cerc{
    
    private:
        Punct origine;
        float raza;
        static Cerc *cerc;
        Cerc(Punct o, float r):origine(o), raza(r){};
        void operator=(Cerc const&);
        
    public:
       
        static Cerc* creareCerc(Punct o, float r){ 
            if (cerc){
                throw -1;
            }
            else

            {
                cerc = new Cerc(o, r);
            }
            return cerc;
            
        };
        float getRaza(){ return raza;};
        Punct getOrigine(){ return origine;};
    
};

template <class Figura, class Cerc> int intersectie(Figura fig, Cerc cerc){
    int intersectie = 0;
    float o_x = cerc.getOrigine().getX();
    float o_y = cerc.getOrigine().getY();
    float r = cerc.getRaza();
    
    Punct * puncte = fig.getPuncte();
    for( size_t i = 0; i < fig.getDim(); i++){
        float x = fig.getPunct(i).getX();
        float y = fig.getPunct(i).getY();
        
        float distanta = sqrt((o_x -x)* (o_x -x) + (o_y -y)* (o_y - y));
        if (distanta <= r){
            intersectie++;
        }
    }
    if (intersectie > 0)
        return 1;
    return 0;
}


 Cerc* Cerc::cerc = nullptr;
 
int main(){
    
    Punct p1 = Punct(20, 20);
    p1.printeaza();
    p1.setX(25);
    p1.printeaza();
    
    Triunghi t1 = Triunghi(  Punct(10, 10),  Punct(11, 11),  Punct(12,10));
    
    std::cout << "Panta triung. este: " << panta(t1) << "\n";
    std::cout << "Perimetru triung. este: " << t1.perimetru() << "\n";
    
    Patrat patrat = Patrat(  Punct(0, 0),  Punct(2, 0), Punct(2,2), Punct(0,2));
    
    std::cout << "Panta patrat este: " << panta(patrat) << "\n";
     std::cout << "Perimetru patrat. este: " << patrat.perimetru() << "\n";
  
    Cerc* c1 = Cerc::creareCerc( Punct(0, 0), 5);
    
    try
    {
        Cerc* c2 = Cerc::creareCerc( Punct(0, 0), 5);
    }
    catch(int i)
    {
        std::cout << "Doar un cerc poate exista: " << i << "\n";
    }
    int inters = intersectie(patrat, *c1);
    std::cout << "Intersectia dintre patrat si cerc: " << inters << "\n";
    
    int inters1 = intersectie(t1, *c1);
    std::cout << "Intersectia dintre triunghi si cerc: " << inters1 << "\n";
    
 return 0;   
}