#include <iostream>

using namespace std;

void wypisz(int *tablica, int n){
    int i;
    for( i = 0; i < n; i++){
        cout << tablica[i];
    }
}

 int main(){

     int k, n, x;
     cout << "Podaj dlugosc ciagu k: ";
     cin >> k;
     cout << "Podaj zakres n: " ;
     cin >> n;
     cout << endl;

     int T[k];
     for(int i = 0; i < k; i++){
         T[i] = 1;
     }
     int pom = k-1, r=0;

     do{
         while(T[r] < T[r+1] && r < k-1){
             r++;
         }
         if(r == k-1){
             wypisz(T,k);
             cout << endl;
         }
         r = 0;

         for (pom; pom >= 0; pom--){
             if(T[pom] < n){
                 T[pom]++;
                 x = pom+1;
                 pom = k-1;
                 break;
             }
         }

         for (x; x < k; x++) {
             T[x] = 1;
         }

     } while (pom > 0);

     return 0;
 }

