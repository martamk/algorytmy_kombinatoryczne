#include <iostream>
#include <set>

using namespace std;

int max(const int* tab, int roz){
    int m = tab[1];
    for(int j = 1; j <= roz; j++){
        if(tab[j] >= m) m = tab[j];
    }
    return m;
}

int main(){
    int n;
    cout << "Podaj n: " <<endl;
    cin >> n;
    int F[n+1];
    cout << "Podaj elementy tablicy f: ";
    for( int i = 1; i <= n; i++){
        cin >> F[i];
    }
    int maksimum = max(F, n);
    set <int> B[maksimum];

    for( int i = 1; i <= maksimum; i++){
        set <int> b;
        for( int j = 1; j <= n; j++){
            if(F[j] == i){
                b.insert(j);
            }
        }
        B[i-1] = b;
    }

    for( int i = 0; i < maksimum; i++){
        cout << "{";
        for(int elem : B[i]){
            cout << " " << elem;
        }
        cout <<" }" << endl;
    }

    return 0;
}

