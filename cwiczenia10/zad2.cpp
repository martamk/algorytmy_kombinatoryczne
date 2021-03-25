#include <iostream>
#include <vector>

using namespace std;

int policzElem(vector <int> l, int n, int elem){
    int ile = 0;
    for(int i = 0; i < n; i++){
        if(l[i] == elem){
            ile++;
        }
    }
    return ile;
}


int main(){
    int n;
    int temp;
    cout << "Podaj n: ";
    cin >> n;
    vector <int> L;
    int d[n+1];
    int G[n+1][n+1];

    cout << "Podaj elementy L: "<< endl;    //uzupełnienie tablicy reprezentującej kod Prufera
    for(int i = 1; i < n-1; i++){
        cin >> temp;
        L.push_back(temp);
    }

    cout << " d = [ ";        // obliczenie tablicy ze stopniami wierzchołków
    for(int i = 1; i < n+1; i++){
        temp = policzElem(L, n, i);
        temp++;
        d[i] = temp;
        cout << d[i] << " ";
    }
    cout << "]" << endl;

    for(int i = 1; i < n+1; i++){       // inicjacja macierzy sasiedztwa - pusty zbiór krawędzi
        for(int j = 1; j < n+1; j++){
            G[i][j] = 0;
        }
    }

    L.push_back(1);

    int x;
    int y;
    int krok = 1;
    while (krok < n){
        x = n;
        while(d[x] != 1){   //szukam największego wierzchołka o stopniu 1
            x--;
        }
        y = L[krok-1];
        //cout << "Krok: " << krok << " x=" << x << " y=" << y << endl;
        G[x][y] = 1;
        G[y][x] = 1;
        d[x]--;
        d[y]--;
        krok++;
    }
    cout << endl;

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            cout << G[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}