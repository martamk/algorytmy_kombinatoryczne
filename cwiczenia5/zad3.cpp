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
    int n, r;
    cout << "Podaj n: ";
    cin >> n;
    cout << "Podaj range: ";
    cin >> r;

    int p[n];
    p[n] = 1;
    int d;
    for (int j = 1; j <= n-1; j++){
        d = (r % silnia(j+1)) / silnia(j);
        r = r - (d * silnia(j));
        p[n-j] = d + 1;
        for (int i = n - j + 1; i <= n; i++){
            if (p[i] >= d+1){
                p[i] += 1;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        cout << p[i] << " ";
    }

    return 0;
}
