#include <iostream>
#include <vector>
using namespace std;

double Newton(int n, int k)
{
    double Wynik = 1;
    unsigned int i;

    for(i = 1; i <= k; i++)
    {
        Wynik = Wynik * ( n - i + 1 ) / i;
    }

    //cout <<"N wynosi " << Wynik << endl;
    return Wynik;
}

int main() {
    int n, k;
    double r;
    cout << "Podaj zakres n: ";
    cin >> n;
    cout << "Podaj range r: ";
    cin >> r;
    cout << "Podaj dlugosc ciagu k: ";
    cin >> k;

    vector <int> v;
    int x = 1;
    double N;

    for (int i = 1; i <= k; i++){
        //N = Newton(n-x, k-i);
        while (Newton(n-x, k-i) <= r){
            r = r - Newton(n-x, k-i);
            x = x + 1;
        }
        v.push_back(x);
        //cout << "dodaje element " << x << endl;
        x = x + 1;
    }

    //cout << v.size() << endl;
    for (int i : v){
        cout << i << " ";
    }

    return 0;
}
