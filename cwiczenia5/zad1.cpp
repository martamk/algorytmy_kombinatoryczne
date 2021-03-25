#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Podaj n: ";
    cin >> n;

    int p[n];
    p[0] = -1;
    cout << "Podaj elementy permutacji: " << endl;
    for (int i = 1; i <= n; i++){
        cin >> p[i];
    }
    /*for (int i = 1; i <= n; i++){
        cout << p[i] << " ";
    }*/
    int i = n-1;
    while (p[i+1] < p[i]){
        i = i-1;
    }
    if (i == 0){
        cout << "nie ma";
        return 1;
    }
    int j = n;
    while (p[j] < p[i]){
        j = j - 1;
    }

    int pom = p[i];
    p[i] = p[j];
    p[j] = pom;

    int perm[n];
    for (int h = i+1; h <= n; h++){
        perm[h] = p[h];
    }
    for (int h = i+1; h <= n; h++){
        p[h] = perm[n+i+1-h];
    }
    for (int g = 1; g <= n; g++){
        cout << p[g] << " ";
    }

    return 0;
}
