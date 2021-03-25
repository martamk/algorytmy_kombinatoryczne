#include <iostream>
#include <vector>

using namespace std;

vector<int> p;
vector<int> p_sp;
int k, g_n;

void podzial_sp(int m) {
    int n_prim = p[1];
    for (int i = 1; i <= n_prim; i++) {
        p_sp[i] = 1;
    }
    for (int i = 2; i <= g_n; i++) {
        if (i <= m) {
            for (int j = 1; j <= p[i]; j++) {
                p_sp[j] += 1;
            }
        }
        else {
            break;
        }
    }
}

void podzial(int n, int b, int m) {
    if ((n == 0) && (p[1] == k)){
        podzial_sp(m);
        cout << endl << "( ";
        for (int i = 1; i <= k; i++) {
            cout << p_sp[i] << " ";
        }
        cout << ")";

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
    cout << "Podaj k: ";
    cin >> k;

    g_n = n;
    for (int i = 0; i <= n; i++) {
        p.push_back(0);
        p_sp.push_back(0);
    }
    podzial(n, k, 0);

    return 0;
}