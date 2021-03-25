// algorytm Prima (z wykorzystaniem kolejki priorytetowej) znajdujący minimalne drzewo rozpinające
// oblicza też wagę końcowego MST

#include <iostream>
#include <utility>
#include <list>
#include <limits>
#include <queue>
using namespace std;

static int INF = numeric_limits<int>::max();
static int NIL = -1;
typedef pair<int, int> intPair;

class Graph
{
    int V;
    list< pair<int, int> > *adj;

public:
    Graph(int V){
        this->V = V;
        adj = new list<intPair> [V];
    }

    void addEdge(int u, int v, int w){
        // 1. elememnt pary: waga;
        // 2. element pary: wierzchołek
        // po prostu tak, żeby było jednolicie z kolejką Q
        adj[u].push_back(make_pair(w, v));
        adj[v].push_back(make_pair(w, u));
    }

    void primMST(){
        // każdy elem w kolejce priorytetowej jest przechowywany jako para: waga i wierzchołek
        // waga musi być pierwsza bo po niej sortowana jest kolejka priorytetowa!
        priority_queue<intPair, vector<intPair>, greater<> > Q;

        // ustalenie wierzchołka startowego
        int root = 0;

        //inicjacja parametrów "key" wierzchołków na INF
        vector<int> key(V, INF);

        // inicjacja parametów "parent" wierzchołków na NIL (-1)
        vector<int> parent(V, NIL);

        // pomocniczy wektor trzymający informację czy wierzchołek znajduje się w MST
        vector<bool> inMST(V, false);


        //dodanie korzenia MST do kolejki priorytetowej
        Q.push(make_pair(0, root));
        key[root] = 0;

        int totalWeight = 0;

        while(!Q.empty()){
            // "najlżejszy wagowo" wierzchołek znajduje się na początku kolejki Q
            // przypomnienie: 1. elem to waga; 2. elem wierzchołek
            // wzięcie tego wierzchołka i usunięcie go z kolejki
            int u = Q.top().second;
            Q.pop();
            inMST[u] = true;    // dodanie wierzchołka do MST

            // i będzie służyło do przejścia po wszystkich parach stanowiących sąsiadów u
            list< pair<int, int> >::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i) {
                int v = (*i).second;
                int weight = (*i).first;

                if(inMST[v] == false && key[v] > weight){
                    key[v] = weight;
                    Q.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }
        for(int i = 1; i < V; i++){
            totalWeight += key[i];
            cout << parent[i]+1 << " - " << i+1 << endl;
        }
        cout << "Waga MST: " << totalWeight;
    }
};

int main() {
    int n, x, y, w, k;
    cout << "Podaj ilosc wierzcholkow: ";
    cin >> n;
    cout << "Podaj ile krawedzi bedzie mial graf: ";
    cin >> k;

    Graph g(n);

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

    g.primMST();

    return 0;
}
