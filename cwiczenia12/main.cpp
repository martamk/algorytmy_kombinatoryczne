#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> intPair;

// klasa reprezentujaca zbiory rozlaczne
class DisjoinedSets{
    int *parent, *rank;
    int n;

public:
    DisjoinedSets(int n){
        this->n = n;
        parent = new int[n+1];
        rank = new int[n+1];

        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u){	// funkcja znajdujaca reprezentanta zbioru
        if(parent[u] != u ){
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unionSet(int x, int y){	// funkcja laczenia zbiorow
        int xr = find(x);
        int yr = find(y);

		// drzewo o mniejszej randze zostaje dolaczone do tego o wiekszej
        if(rank[xr] > rank[yr]){
            parent[yr] = xr;
        }
        else{
            parent[xr] = yr;
        }

        if(rank[xr] == rank[yr]){
            rank[yr]++;
        }
    }
};

class Graph{
    int V, E;
    vector <pair<int, intPair>> edges;

public:
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

	// funkcja dodajaca krawedz w postaci {(waga), x, y}
    void addEdge(int u, int v, int w)
    {
        edges.push_back(make_pair(w, make_pair(u,v)));
    }

    int kruskalMST(){

        int weightMST = 0;

        sort(edges.begin(), edges.end());

        DisjoinedSets S(V);

		// iterowanie po posortowanych wagowo krawedziach
        vector<pair<int, intPair>>::iterator it;
        for(it = edges.begin(); it != edges.end(); ++it){
            int u = (*it).second.first;		// 1. wierzch. kraw.
            int v = (*it).second.second;	// 2. wierzch. kraw.
            int uSet = S.find(u);	// znalzezienie reprezent. zbioru do jakiego nalezy u
            int vSet = S.find(v);

            if(uSet != vSet){
                cout << u+1 << " - " << v+1 << endl;
                weightMST += (*it).first;
                S.unionSet(uSet, vSet);		// zlaczenie zbiorow(podgrafow) w wiekszy graf
            }
        }
        return weightMST;
    }
};


int main() {
    int n, k;
    cout << "Podaj ilosc wierzcholkow: " ;
    cin >> n;
    cout << "Podaj ilosc krawedzi: " ;
    cin >> k;

    Graph g(n, k);
    int x, y, w;
    cout << "---------------" << endl;
    cout << "Podawaj krawedzie w formacie " << endl;
    cout << "x - pierwszy koniec krawedzi " << endl;
    cout << "y - drugi koniec krawedzi " << endl;
    cout << "w - waga tej krawedzi " << endl;
    //cout << "Numeruj wierzcholki od 0!" << endl;
    cout << "---------------" << endl;
    for(int i = 0; i < k; i++){
        cout << "Podaj " << i+1 << " krawedz " << endl;
        cin >> x;
        x--;
        cin >> y;
        y--;
        cin >> w;
        g.addEdge(x, y, w);
    }

    w = g.kruskalMST();
    cout << "Waga MST: " << w;


    return 0;
}
