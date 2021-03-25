#include <iostream>
using namespace std;

double Newton(int n, int k)
{
    double Wynik = 1;
    unsigned int i;

    for(i = 1; i <= k; i++)
    {
        Wynik = Wynik * ( n - i + 1 ) / i;
    }

    //cout << Wynik << endl;
    return Wynik;
}


int main() {
    int n, k;
    double r;
    cout << "Podaj zakres n: ";
    cin >> n;
    cout << "Podaj dlugosc ciagu k: ";
    cin >> k;

    int T[k+1];
    T[0] = 0;
    for (int i = 1; i < k+1; i++){
        cin >> T[i];
    }

    r = 0;
    double N = 0;
    for (int i = 1; i < k+1; i++){
        if(T[i-1]+1 <= T[i]-1){
            for(int j = T[i-1]+1; j <= T[i]-1; j++){
                N = Newton(n-j, k-i);
                r = r + N;
            }
        }
    }
    cout << r;

    return 0;
}
