#include <iostream>
using namespace std;

int silnia(int m){      // zakładam, że nie będzie tu żadnych dużych liczb
    int wynik = 1;
    for (int i = 1; i <= m; i++){
        wynik = wynik * i;
    }
    return wynik;
}

int main() {
    int n;
    int r = 0;
    cout << "Podaj n: ";
    cin >> n;

    int p[n];
    cout << "Podaj elementy permutacji: ";
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int j = 1; j <= n; j++){
        r = r + (p[j]-1) * silnia(n-j);
        for (int h = j+1; h<= n; h++){
            if(p[h] > p[j]){
                p[h] = p[h] - 1;
            }
        }
    }
    cout << "Ranga wynosi: " << r << endl;

    return 0;
}
