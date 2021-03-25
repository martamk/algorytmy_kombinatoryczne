#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, d;
    cout << "Podaj zakres n: ";
    cin >> n;
    cout << "Podaj dlugosc podzbioru: ";
    cin >> d;

    int T[d];
    for (int i = 0; i < d; i++){
        cin >> T[i];
    }
    int Pom[n];
    for (int i = 0; i < n; i++){
        Pom[i] = 0;
    }
    for (int i = 0; i < d; i++){
        Pom[T[i]-1] = 1;
    }
    /*for (int i = 0; i < n; i++){
        cout << Pom[i] << " ";
    }*/
    int r = 0;
    int Rank[n+1];
    for (int i = 0; i < n+1; i++){
        Rank[i] = 0;
    }
    for (int i = 0; i < n; i++){
        if(Pom[i] == Rank[i]){
            Rank[i+1] = 0;
        }
        else Rank[i+1] = 1;
    }
    for (int i = n; i > 0; i--){
        r = r + Rank[i] * pow(2,n-i);
    }
    cout << r;

    return 0;
}

