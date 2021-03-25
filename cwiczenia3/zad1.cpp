#include <iostream>

using namespace std;

bool even(const int *tab, int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum = sum + tab[i];
    }
    return sum % 2 == 0;
}

int main() {

    int n, j;
    cout << "Podaj n: ";
    cin >> n;
    int T[n];
    for (int i = 0; i < n; i++){
        T[i] = 0;
    }

    int wart = 1;
    while(wart != 0){
        cout << "{";
        for (int i = 0; i < n; i++){
            if(T[i] == 1) {
                cout << i + 1 << " ";
            }
        }
        cout << "}" << endl;
        if(even(T,n)){
            if(T[n-1] == 0) {
                T[n - 1] = 1;
            }
            else T[n-1] = 0;
        }
        else{
            j = n-1;
            while(T[j] != 1){
                j--;
            }
            if(T[j-1] == 0) {
                T[j-1] = 1;
            }
            else if(T[j-1] == 1){
                T[j-1] = 0;
            }
            else wart = 0;
        }
    }

    return 0;
}
