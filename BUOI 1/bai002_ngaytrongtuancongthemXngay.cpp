#include<iostream>
#include<cmath>
using namespace std;

struct day{
   int dd, mm, yy, mathang, manam, matheky, thu; string strthu;

};

string xuatthu(int thu){
   string week;
   switch (thu){
       case 0: week = "chu nhat"; break;
       case 1: week = "thu hai";  break;
       case 2: week = "thu ba";   break;
       case 3: week = "thu tu";   break;
       case 4: week = "thu nam";  break;
       case 5: week = "thu sau";  break;
       case 6: week = "thu bay";  break;
       default: week = "khong xac dinh"; break;
   };
   return week;
}

int xuatmatheky(int yy){
   int ma = (3 - (yy/100) % 4) * 2;
   return ma;
}

int xuatmanam(int yy){
   int socuoi = yy%100;
   int manam = (socuoi + socuoi/4);
   return manam;
}

int xuatmathang(int mm){
   int mathang;
    switch(mm){
   case 1:
   case 10: mathang = 0; break;
   case 2:
   case 3:
   case 11: mathang = 3; break;
   case 4:
   case 7: mathang = 6; break;
   case 5: mathang = 1; break;
   case 6: mathang = 4; break;
   case 8: mathang = 2; break;
   case 9:
   case 12: mathang = 5; break;
   }
   return mathang;
}

bool lanamnhuan(int yy){
   return (yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0);
}


void nhap(day &a, int &x){
   cin >> x;
   cin >> a.dd >> a.mm >> a.yy;

   a.mathang = xuatmathang(a.mm);
   if (lanamnhuan(a.yy)) {
        if (a.mm == 1 || a.mm == 2) {
            a.mathang -= 1;
        }
   }

   a.manam = xuatmanam(a.yy);
   a.matheky = xuatmatheky(a.yy);
   a.thu = (a.dd + a.mathang + a.manam + a.matheky) % 7;
   a.strthu = xuatthu(a.thu);
}

int tinhsongaytrongthang(int mm, int yy){
   switch(mm){
   case 4: case 6: case 9: case 11: return 30;
   case 2: return lanamnhuan(yy) ? 29 : 28;
   default: return 31;
   }
}

void congngay(day &a, int x){
   a.dd += x;
   while (a.dd > tinhsongaytrongthang(a.mm, a.yy)){
      a.dd -= tinhsongaytrongthang(a.mm, a.yy);
      a.mm++;
      if(a.mm > 12){
         a.mm = 1;
         a.yy++;
      }
   }

   a.mathang = xuatmathang(a.mm);
   if (lanamnhuan(a.yy)) {
        if (a.mm == 1 || a.mm == 2) {
            a.mathang -= 1;
        }
   }

   a.manam = xuatmanam(a.yy);
   a.matheky = xuatmatheky(a.yy);
   a.thu = (a.dd + a.mathang + a.manam + a.matheky) % 7;
   a.strthu = xuatthu(a.thu);
}

void xuat(day a){
   cout << a.strthu << " " << a.dd << "/" << a.mm << "/" << a.yy;
}



int main(){
   int x; day a;
   nhap(a, x);
   congngay(a, x);
   xuat(a);
   return 0;
}