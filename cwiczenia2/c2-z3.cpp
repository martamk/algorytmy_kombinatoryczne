//zajecia 2 zadanie 3

#include <iostream>

using namespace std;

int main(){

    int n, r;
    cout << "Podaj zakres n: ";
    cin >> n;
    cout << "Podaj r: ";
    cin >> r;

    int T[n];
    for(int i = 0; i < n; i++){
        T[i] = 0;
    }

    int pom = 0;
    for (int i = n-1; i >= 0; i--){
        T[i] = r % 2;
        r = r / 2;
    }

    int jed = 0;
    for(int i = 0; i < n; i++){
        //cout << T[i];
        jed = jed + T[i];
    }
    cout << endl;

    int A[jed];
    pom = jed;
    for (int i = n-1; i >= 0; i--){
        if(T[i] == 1){
            A[jed-1] = i+1;
            jed--;
        }
    }

    cout << "{";
    for(int i = 0; i < pom; i++){
        cout << A[i];
    }
    cout << "}";

    return 0;
}