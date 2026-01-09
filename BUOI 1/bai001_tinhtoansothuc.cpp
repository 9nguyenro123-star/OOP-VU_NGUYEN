#include<iostream>
#include<cmath>
using namespace std;

inline double cong(double a, double b){
   return a + b;
}

inline double tru(double a, double b){
   return a - b;
}

inline double nhan(double a, double b){
   return a * b;
}

inline double chia(double a, double b){
   return a / b;
}

int main(){
   double a, b;
   cout << "nhap a: "; cin >> a;
   cout << "nhap b: "; cin >> b;
   cout << "a + b = " << cong(a, b) << endl;
   cout << "a - b = " << tru(a, b) << endl;
   cout << "a * b = " << nhan(a, b) << endl;
   cout << "a / b = " << chia(a, b);

   return 0;
}

