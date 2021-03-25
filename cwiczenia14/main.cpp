// algorytm Bellmana- Forda znajdowania najkrotszych sciezek ze zrodlowego
// wierzcholka do kazdego innego
#include <iostream>
#include <limits>

using namespace std;

static int INF = numeric_limits<int>::max();

// struktura reprezentujaca wazona krawedz
struct Edge {
    int src, dest, weight;
};

// klasa grafu
class Graph{
public:
    int V, E;
    struct Edge* edge;      // reprezentacja grafu jako tablicy krawedzi

public:
    Graph(int V, int E){
        this-> V = V;
        this-> E = E;
        this->edge = new Edge[E];
    }
};


/* wypisywanie wyniku - sciezki
void printArr(int dist[], int parent[], int n)
{
    cout << "wierzcholek \t  laczna waga " << endl;
    for (int i = 0; i < n; ++i){
        cout << i+1 << "\t\t" << dist[i] << endl;
    }
}*/

void printPath(int parent[], int j)
{
    if (parent[j] == - 1){
        return;
    }
    printPath(parent, parent[j]);
    cout << " - " << j+1;
}

void printSolution(int dist[], int parent[], int V)
{
    int src = 0;
    for (int i = 1; i < V; i++) {
        if (dist[i] < 0) {
            cout << "graf zawiera ujemny cykl" << endl;
        } else {
            for (int i = 1; i < V; i++) {
                cout << src + 1 << " do " << i + 1 << "\t waga sciezki: " << dist[i] << "\t sciezka: " << src + 1;
                printPath(parent, i);
                cout << endl;
            }
        }
    }
}

void BellmanFord(Graph graph, int src)
{
    int V = graph.V;
    int E = graph.E;
    int dist[V];
    int parent[V];

    // Inicjacja wszystich odleglosci na INF
    for (int i = 0; i < V; i++){
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph.edge[j].src;
            int v = graph.edge[j].dest;
            int weight = graph.edge[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < E; i++) {
        int u = graph.edge[i].src;
        int v = graph.edge[i].dest;
        int weight = graph.edge[i].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            cout << "Graf zawiera ujemny cykl!" << endl;
            return;
        }
    }
    printSolution(dist, parent, V);
}

int main()
{

    int n, k;
    cout << "Podaj ilosc wierzcholkow: " ;
    cin >> n;
    cout << "Podaj ilosc krawedzi: " ;
    cin >> k;

    Graph g(n, k);
    int x, y, w;
    cout << "---------------" << endl;
    cout << "Podawaj krawedzie w formacie " << endl;
    cout << "x - 'zrodlo' krawedzi " << endl;
    cout << "y - 'cel' krawedzi " << endl;
    cout << "w - waga tej krawedzi " << endl;
    cout << "---------------" << endl;
    for(int i = 0; i < k; i++){
        cout << "Podaj " << i+1 << " krawedz " << endl;
        cin >> x;
        x--;
        cin >> y;
        y--;
        cin >> w;
        g.edge[i].src = x;
        g.edge[i].dest = y;
        g.edge[i].weight = w;
    }
    BellmanFord(g, 0);

    return 0;
}