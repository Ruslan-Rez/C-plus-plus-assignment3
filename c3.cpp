#include <iostream>
using namespace std;
class Frac{
private:
    int num;
    int den;
public:
   Frac(){
       num = 0;
       den = 0;
   }
   Frac(int n){
       num = n;
       den = 1;
   }
   Frac( int n , int d){
       if( n == 0){
           d = 1;
       }else
           num = n;
           den = d;
   }
   
   friend ostream& operator<<(ostream& os, const Frac& x);
   friend Frac operator+(Frac x , Frac y);
   friend Frac operator-(Frac x , Frac y);
   friend Frac operator*(Frac x , Frac y);
   friend Frac operator/(Frac x , Frac y);
};
int gcd(int n, int d){
       int rem;
       while(d != 0){
           rem = n%d;
           n =d;
           d = rem;
       }
       return n;
   }
ostream& operator<<(ostream& os, const Frac& x){
    if (x.den == 1)
      os<<x.num;
    else
    os<<x.num<<"/"<<x.den;
    return os;
}
Frac operator+(Frac x ,  Frac y){
    int k = x.num*y.den + y.num*x.den;
   int m = x.den*y.den;
return Frac(k/gcd(k,m) , m/gcd(k,m));
}
Frac operator-(Frac x ,  Frac y){
    int k = x.num*y.den - y.num*x.den;
   int m = x.den*y.den;
return Frac(k/gcd(k,m) , m/gcd(k,m));
}
Frac operator*(Frac x ,  Frac y){
    int k = x.num*y.num;
   int m = x.den*y.den;
return Frac(k/gcd(k,m) , m/gcd(k,m));
}
Frac operator/(Frac x ,  Frac y){
    int k = x.num*y.den;
   int m = x.den*y.num;
return Frac(k/gcd(k,m) , m/gcd(k,m));
}

int main() {
    Frac a(2), b(4,10), c(24,-15), x(1,-3), y(2,6);
    std::cout << -2*((a+b)*5-4)/c     << " "
    << (7 + x + y*1114/111) << std::endl;
    }