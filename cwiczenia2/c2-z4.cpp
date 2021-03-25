//zajecia 2 zadanie 4

#include <iostream>
#include <vector>
using namespace std;

void generuj(int n, int k, vector<int> ciag) {
    vector<int> nowy_ciag;

    for (int i = 0; i < n; i++){
        nowy_ciag = ciag;
        nowy_ciag.push_back(i+1);

        if (nowy_ciag.size() == k) {
            for (int j = 0; j < k; j++) {
                cout << nowy_ciag[j];
            }
            cout << endl;
        }
        else {
            generuj(n, k, nowy_ciag);
        }
    }
}

int main() {

    int n, k;
    vector<int> ciag;

    cout << "Podaj dlugosc k: ";
    cin >> k;
    cout << "Podaj zakres n: ";
    cin >> n;

    generuj(n, k, ciag);

    return 0;
}

