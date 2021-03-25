#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool contains(int elem, const set<int>& blok){
    return blok.count(elem) >= 1;
}

int main() {
    int n, k, l, pom, kluska;
    cout << "Podaj n: " <<endl;
    cin >> n;
    int F[n+1];
    cout << "Podaj liczbe blokow k: " <<endl;
    cin >> k;
    vector <set <int>> B;
    for(int i = 1; i <= k; i++){
        cout << "Podaj liczbe elementow " << i << " bloku: " << endl;
        cin >> pom;
        set <int> s;
        cout << "podaj elementy bloku " << i << endl;
        for (int j = 0; j < pom; j++){
            cin >> l;
            s.insert(l);
        }
        B.push_back(s);
    }
    /*for(int i = 0 ; i < B.size(); i++){
        set <int, greater <> > :: iterator itr;
        for (itr = B[i].begin(); itr != B[i].end(); ++itr)
        {
            cout << " " << *itr;
        }
        cout << endl;
    }*/

    for(int i = 1; i <= n; i++){
        F[i] = 0;
    }
    int j = 1, h;
    int ktory_blok = 1;
    for (int i = 1; i <= k; i++){
        while(F[j] != 0){
            j++;
        }
        h = 0;
        //cout << "szukam elem " << j << endl;
        while(!contains(j, B[h])){
            h++;
        }
        //cout << "znalazle elem " << j << " w bloku " << h << endl;
        set <int, greater <> > :: iterator itr;
        for (itr = B[h].begin(); itr != B[h].end(); ++itr)
        {
            kluska = *itr;
            F[kluska] = ktory_blok;
        }
        //cout << endl;
        ktory_blok++;
    }
    for(int i = 1; i <= n; i++){
        cout << F[i] << " ";
    }

    return 0;
}
