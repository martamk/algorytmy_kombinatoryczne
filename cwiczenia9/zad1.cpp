#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, k;
    cout << "Podaj n: ";
    cin >> n;
    cout << "Podaj k: ";
    cin >> k;

    vector<vector<int>> P;
    for (int i = 0; i <= n; i++) {
        vector<int> temp;
        for (int j = 0; j <= k; j++) {
            temp.push_back(0);
        }
        P.push_back(temp);
    }
    P[0][0] = 1;

    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            if (i >= j) {
                P[i][j] = P[i-1][j-1] + P[i-j][j];
            }
        }
    }

    cout << "Liczba podzialow: " << P[n][k] << endl;

    return 0;
}