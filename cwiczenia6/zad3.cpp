#include <iostream>

using namespace std;

int Newton(int n, int k)
{
    int Wynik = 1;

    for (int i = 1; i <= k; i++)
    {
        Wynik = Wynik * ( n - i + 1 ) / i;
    }

    return Wynik;
}
int Bell (int h){
    int B[h+1];
    int suma = 0;
    B[0] = 1;
    for (int i = 1; i <= h; i++){
        for (int j = 0; j <= i; j++){
            suma = suma + Newton(i-1,j) * B[j];
            //cout << suma << " ";
        }
        //cout << endl;
        B[i] = suma;
        suma = 0;
    }
    cout << endl;
    return B[h];
}

int main() {
    int n;
    cout << "Podaj n: ";
    cin >> n;

    cout << Bell(n);

    return 0;
}

