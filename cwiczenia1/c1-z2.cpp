#include <iostream>

using namespace std;

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

    int pom = k-1;

    do{
        for (int i = 0; i < k; i++){
            cout << T[i];
        }
        cout << endl;

        for (pom; pom >= 0; pom--){
            if(T[pom] < n && T[pom] <= pom){
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