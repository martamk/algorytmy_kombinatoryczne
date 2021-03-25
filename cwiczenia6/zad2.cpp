#include <iostream>

using namespace std;

int S(int n, int k){        //liczby Stirlinga 1. rodzaju
    int T[n+1][k+1];
    T[0][0] = 1;
    for(int i = 1; i <= n; i++){
        T[i][0] = 0;
    }
    /*for(int i = 0; i < n+1; i++){
        for(int j = 0; j < k+1; j++){
            cout << T[i][j] << "    ";
        }
        cout << endl;
    }*/
    cout << endl << endl;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            //cout << "i = " << i << "  j = " << j;
            if(j == i){
                //cout << " podstawiam 1 " << endl;
                T[i][j] = 1;
            }
            else {
                //cout << " podstawiam " << T[i-1][j-1] - (i-1) * T[i-1][j] << endl;
                T[i][j] = T[i-1][j-1] - (i-1) * T[i-1][j];
            }
        }
    }

    /*for(int i = 0; i < n+1; i++){
        for(int j = 0; j < k+1; j++){
            cout << T[i][j] << "    ";
        }
        cout << endl;
    }
    cout << endl;*/
    return T[n][k];

}


int main() {
    int n, k;
    cout << "Podaj n: ";
    cin >> n;
    cout << "Podaj k: ";
    cin >> k;

    cout << S(n,k);

    return 0;
}


