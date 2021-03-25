#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Podaj n: ";
    cin >> n;
    int G[n+1][n+1];
    int d[n+1];

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            G[i][j] = 0;
        }
    }

    // uzupelnieie macierzy G - przyległości wierzchołków
    int temp, sasiad;
    for(int i = 1; i < n+1; i++){
        cout << "podaj ile wierzcholek " << i << " bedzie mial sasiadow: ";
        cin >> temp;
        d[i] = temp;
        cout << "Podaj tych sasiadow " << endl;
        for (int j = 0; j < temp; j++){
            cin >> sasiad;
            //cout << "Podstawiam... i = "<< i << " sasiad = " << sasiad << endl;
            G[i][sasiad] = 1;
            G[sasiad][i] = 1;
        }
    }
    cout << endl;
    /*for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            cout << G[i][j] << " ";
        }
        cout << endl;
    }*/
    vector <int> L;
    int x;
    int y;
    while(L.size() < n-2){
        x = n;
        while(d[x] != 1){   //szukam największego wierzchołka o stopniu 1
            x--;
        }
        y = 1;
        while(G[x][y] != 1){    //szukam sąsiada wierzchołka x w tablicy G
            y++;
        }
        //cout << "do L wrzucam " << y << endl;
        L.push_back(y);
        d[x]--;
        d[y]--;
        G[x][y] = 0;
        G[y][x] = 0;
    }

    cout << "L = ";
    for(int i : L){
        cout << i << " ";
    }

    return 0;
}