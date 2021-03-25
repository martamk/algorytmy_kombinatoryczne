#include <iostream>
using namespace std;

int main(){

    int n, k;
    cout << "Podaj zakres n: ";
    cin >> n;
    cout << "Podaj dlugosc ciagu k: ";
    cin >> k;

    int T[k];
    for (int i = 0; i < k; i++){
        cin >> T[i];
    }

    int MAX[k];
    int pom = k;
    for(int i = 0; i < k; i++){
        MAX[i] = n - pom + 1;
        pom--;
    }

    int j = k-1;
    while(T[j] == MAX[j] && j >= 0){
        j--;
    }
    if(T[j] < n && j >= 0){
        T[j]++;
    }
    else{
        cout << "to chyba ostatni ciag" << endl;
        return 0;
    }
    for(int i = 0; i < k; i++){
        cout << T[i] << " ";
    }
    cout << endl;
    pom = T[j]+1;
    for (int i = j+1; i < k; i++){
        T[i] = pom;
        pom++;
    }

    for(int i = 0; i < k; i++){
        cout << T[i] << " ";
    }

    return 0;
}

