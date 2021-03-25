#include <iostream>

using namespace std;

void wypisz(int* tab, int roz){
    for(int i = 1; i <= roz; i++){
        cout << tab[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cout << "podaj n: ";
    cin >> n;
    int f[n+1];
    int F[n+1];
    for(int i = 1; i <= n; i++){
        f[i] = 1;
        F[i] = 2;
    }
    bool koniec = false;
    int j;
    while(!koniec){
        wypisz(f, n);
        int j = n;
        while (f[j] == F[j]) {
            j--;
        }
        if(j > 1){
            f[j] = f[j] + 1;
            for( int i = j+1; i <= n; i++){
                f[i] = 1;
                if(f[j] == F[j]){
                    F[i] = F[j] + 1;
                }
                else{
                    F[i] = F[j];
                }
            }
        }
        else{
            koniec = true;
        }
    }
    return 0;
}