#include <iostream>
#include <sstream>
#include <set>
using namespace std;

void wypisz (int* tab, int roz){
    set<int> bloki;
    for (int i = 1; i <= roz; i++) {
        bloki.insert(tab[i]);
    }
    for (int i : bloki) {
        cout << "{ ";
        for (int j = 1; j <= roz; j++) {
            if (tab[j] == i) {
                cout << j << " ";
            }
        }
        cout << "} ";
    }
    cout << endl;
}

int main() {
    int n, elem_akt, nr_bloku;
    cout << "Podaj n: ";
    cin >> n;

    bool PR[n+1];      //jezeli T to w prawo; F to w lewo
    int P[n+1], N[n+1], B[n+1];

    for (int i = 1; i < n+1; i++){
        B[i] = 1;
        PR[i] = true;
        N[i] = i;
    }
    N[1] = 0;
    elem_akt = n;

    wypisz(B, n);

    while(elem_akt != 1){
        //cout << "elem akt = " << elem_akt << endl;
        nr_bloku = B[elem_akt];
        if(PR[elem_akt]){       // elem_akt bedzie poruszal sie w prawo
            if(N[nr_bloku] == 0){
                N[nr_bloku] = elem_akt;
                N[elem_akt] = 0;
                P[elem_akt] = nr_bloku;
            }
            else if (N[nr_bloku] > elem_akt){
                P[elem_akt] = nr_bloku;
                N[elem_akt] = N[nr_bloku];
                P[N[elem_akt]] = elem_akt;
                N[nr_bloku] = elem_akt;
            }
            B[elem_akt] = N[nr_bloku];
        }
        else{   //elem_akt bedzie poruszal sie w lewo
            if(elem_akt == nr_bloku && N[nr_bloku] == 0){
                B[elem_akt] = P[nr_bloku];
                if(N[nr_bloku] == 0) N[P[nr_bloku]] = 0;
            }
            else if(elem_akt == nr_bloku && N[nr_bloku] != 0){
                B[elem_akt] = P[nr_bloku];
                if(N[elem_akt] != 0){
                    N[P[nr_bloku]] = N[nr_bloku];
                    P[N[nr_bloku]] = P[nr_bloku];
                }
            }
            else{
                B[elem_akt] = P[nr_bloku];
            }
        }
        //wyznacz nowy elem_akt
        elem_akt = n;
        while(elem_akt > 1 && ((PR[elem_akt] && B[elem_akt] == elem_akt) || (!PR[elem_akt] && B[elem_akt] == 1))){
            PR[elem_akt] = !PR[elem_akt];
            elem_akt = elem_akt-1;
        }
        wypisz(B, n);
    }
    return 0;
}
