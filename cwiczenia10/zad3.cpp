#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cout << "Podaj n: ";
    cin >> n;
    cout << "Podaj elementy L: ";

    int L[n-2];
    int temp;
    for( int i = 0; i < n-2; i++){
        cin >> temp;
        temp--;
        L[i] = temp;
    }

    int r = 0;
    int p = n-3;

    for(int i = 0; i < n-2; i++){
        r = r + L[i] * pow(n, p);
        p--;
    }

    cout << "r = " << r << endl;

    return 0;
}
