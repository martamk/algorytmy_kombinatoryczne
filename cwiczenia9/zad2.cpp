#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, k;
    cout << "Podaj liczbe n: ";
    cin >> n;
    cout << "Podaj dlugosc podzialu: ";
    cin >> k;

    vector<int> podzial;
    vector<int> podzial_sp;
    podzial.push_back(0);
    podzial_sp.push_back(0);

    cout << "Podaj elementy podzialu: " << endl;
    for (int i = 1; i <= k; i++) {
        int a;
        cin >> a;
        podzial.push_back(a);
    }

    int n_prim = podzial[1];
    for (int i = 1; i <= n_prim; i++) {
        podzial_sp.push_back(1);
    }
    for (int i = 2; i <= n; i++) {
        if (i <= k) {
            for (int j = 1; j <= podzial[i]; j++) {
                podzial_sp[j] += 1;
            }
        }
        else {
            break;
        }
    }

    cout << endl;
    cout << "( ";
    for (int i = 1; i <= n_prim; i++) {
        cout << podzial_sp[i] << " ";
    }
    cout << ")";

    return 0;
}