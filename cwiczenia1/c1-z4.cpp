#include <iostream>

using namespace std;

void wypisz(int *tablica, int n){
    int i;
    for( i = 0; i < n; i++){
        if(tablica[i] == 1){
            cout << i+1;
        }
    }
}

int main() {

    int k, x;
    cout << "Podaj dlugosc ciagu k: ";
    cin >> k;
    cout << endl;

    int T[k];
    for (int i = 0; i < k; i++) {
        T[i] = 0;
    }

    int pom = k-1;

    do{
        wypisz(T,k);
        cout << endl;

        for(pom; pom >= 0; pom--){
            if(T[pom] < 1){
                T[pom]++;
                x = pom+1;
                pom = k-1;
                break;
            }
        }

        for (x; x < k; x++) {
            T[x] = 0;
        }

    } while (pom > 0);


    return 0;
}
