#include <iostream>
#include <vector>

using namespace std;

vector<int> p;

void podzial(int n, int b, int m) {
    if (n == 0) {
        cout << "( ";
        for (int i = 1; i <= m; i++) {
            cout << p[i] << " ";
        }
        cout << ")" << endl;
    }
    else {
        for (int i = 1; i <= min(b, n); i++) {
            p[m + 1] = i;
            podzial(n-i, i, m+1);
        }
    }
}

int main() {

    int n;
    cout << "Podaj n: ";
    cin >> n;

    for (int i = 0; i <= n; i++) {
        p.push_back(0);
    }
    podzial(n, n, 0);

    return 0;
}