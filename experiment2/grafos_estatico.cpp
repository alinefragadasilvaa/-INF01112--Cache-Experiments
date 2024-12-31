#include <iostream>
#include <limits>
#include <time.h>
#define NODES 50000
#define INF std::numeric_limits<int>::max()

using namespace std;

class Graph {
    int adjmatrix[NODES][NODES];
public:
    Graph(){
        for (int i=0;i<NODES;i++){
            for(int j=0;j<NODES;j++){
                if (i==j) adjmatrix[i][j] = 0;
                else adjmatrix[i][j]= -1;
            }
        }
    }
    void add_edge(int i, int j, int weight) {
        adjmatrix[i][j] = weight;
        adjmatrix[j][i] = weight; 
    }
    void random_graph() {
        srand(time(0));
        for (int i = 0; i < NODES; i++) {
            for (int j = i + 1; j < NODES; j++) { 
                if (rand() % 10 >= 5) { 
                    int weight = rand() % 100 + 1; 
                    add_edge(i, j, weight);
                }
            }
        }
    }
    void print() {
        for (int i = 0; i < NODES; ++i) {
            for (int j = 0; j < NODES; ++j) {
                cout << adjmatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    void dijkstra(int src) {
        int dist[NODES];       
        bool visited[NODES]; 
        for (int i = 0; i < NODES; i++) {
            dist[i] = INF;
        }
        dist[src] = 0;
        for (int i = 0; i < NODES - 1; i++) {
            int min = INF;
            int u = -1;
            for (int v = 0; v < NODES; v++) {
                if (!visited[v] && dist[v]!= -1 && dist[v] <= min) {
                    min = dist[v];
                    u = v;
                }
            }
            if (u == -1) break; 
            visited[u] = true;
            for (int v = 0; v < NODES; v++) {
                if (!visited[v] && adjmatrix[u][v] != -1 && dist[u] + adjmatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjmatrix[u][v];
                }
            }
        }
    }
};

int main() {
    Graph grafo;
    grafo.random_graph();
    grafo.dijkstra(0);
    return 0;
}
