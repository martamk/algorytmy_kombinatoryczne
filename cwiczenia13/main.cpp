// algorytm Djikstry znajdowania najkrótszych ścieżek ze źródła do wierzchołków
// z wykorzystaniem kolejki prorytetowej

#include <utility>
#include <list>
#include <limits>
#include <queue>
#include <iostream>
using namespace std;

static int INF = numeric_limits<int>::max();
static int NIL = -1;

typedef pair<int, int> iPair;

class Graph
{
    int V;
    list < pair<int, int> > *adj;

public:
    Graph(int V){
        this->V = V;
        adj = new list<iPair> [V];
    }

    void addEdge(int u, int v, int w){
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // pomocnicze funkcje do wypisuwani rozwiązania(ścieżek)
    void printPath(vector<int> parent, int j)
    {
        if (parent[j] == - 1){
            return;
        }
        printPath(parent, parent[j]);
        cout << " - " << j+1;
    }

    void printSolution(vector<int> dist, int n, vector<int> parent)
    {
        int src = 0;
        for (int i = 1; i < V; i++)
        {
            if(dist[i] == INF){
                cout << src+1 << " do " << i+1 << "\t brak sciezki \t\t  -" << endl;
            }
            else{
                cout << src+1 << " do " << i+1 << "\t waga sciezki: " << dist[i] << "\t sciezka: " << src+1;
                printPath(parent, i);
                cout << endl;
            }

        }
    }
    // ------- //

    void shortestPath(int src){

        priority_queue< iPair, vector <iPair> , greater<iPair> > Q;
        vector<int> dist(V, INF);
        vector<int> parent(V, NIL);

        // w parach dodawanych do kolejki Q na 1. miejscu muszą być odległości
        // bo kolejka sortuje po 1. elemencie pary
        Q.push(make_pair(0, src));
        dist[src] = 0;
        parent[src] = NIL;

        // dopóki kolejka priorytetowa nie jest pusta
        while (!Q.empty())
        {
            int u = Q.top().second;
            Q.pop();

            // przejście po wrzystkich wierzchołkach sąsiadujących z u
            list< pair<int, int> >::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                // v - aktualny sąsiad u i waga przejścia do niego
                int v = (*i).first;
                int weight = (*i).second;

                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    Q.push(make_pair(dist[v], v));
                }
            }
        }
        printSolution(dist, V, parent);
    }
};


int main()
{
    int n, k;
    cout << "Podaj ilosc wierzcholkow: " ;
    cin >> n;
    cout << "Podaj ilosc krawedzi: " ;
    cin >> k;

    Graph g(n);
    int x, y, w;
    cout << "---------------" << endl;
    cout << "Podawaj krawedzie w formacie " << endl;
    cout << "x - pierwszy koniec krawedzi " << endl;
    cout << "y - drugi koniec krawedzi " << endl;
    cout << "w - waga tej krawedzi " << endl;
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
    g.shortestPath(0);

    return 0;
}