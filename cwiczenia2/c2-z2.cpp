//zajecia 2 zadanie 2

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, d;
    cout << "Podaj n: ";
    cin >> n;
    cout << "Jak dlugi bedzie podzbior? ";
    cin >> d;

    int T[d];
    cout << "Podaj elem. podzbioru (MNIEJSZE OD N)" << endl << "I zeby sie nie powtarzaly!!" << endl;
    for (int i = 0; i < d; i++){
        cin >> T[i];
    }

    cout << "{";
    for(int i = 0; i < d; i++){
        cout << T[i];
    }
    cout << "}" << endl;

    int A[n];
    for (int i = 0; i < n; i++){
        A[i] = 0;
    }

    int p = 0;
    for (int i = 0; i < d; i++){
        p = T[i];
        A[p-1] = 1;
    }

    cout << "[";
    for (int i = 0; i < n; i++){
        cout << A[i];
    }
    cout << "]" << endl;

    int r = 0, pot = 0;
    for(int i = 0; i < n; i++){
        if(A[i] == 1){
            pot = n-1-i;
            //cout << pot << " ";
            r = r + pow(2,pot);
        }
    }

    cout << endl << "r = " << r << endl;





}

