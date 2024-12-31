#include <iostream>
#include <vector>
#include <memory> 
#include <queue>
#include <limits>
#include <time.h>

using namespace std;

#define INF numeric_limits<int>::max()

struct node {
    int chave;
    vector<pair<shared_ptr<node>, int>> arestas; 
};

class graph {
    vector<shared_ptr<node>> list_nodes;

    shared_ptr<node> find_node(int chave) {
        for (auto& aux : list_nodes) {
            if (aux->chave == chave) return aux;
        }
        return nullptr; 
    }

    size_t find_index(shared_ptr<node> n) {
        for (size_t i = 0; i < list_nodes.size(); ++i) {
            if (list_nodes[i] == n) return i;
        }
        throw runtime_error("Nodo nao encontrado");
    }

public:
    void add_node(int chave) {
        if (find_node(chave) != nullptr) return;
        auto new_node = make_shared<node>();
        new_node->chave = chave;
        list_nodes.push_back(new_node);
    }

    void add_edge(int chave1, int chave2, int weight) {
        if (weight < 0) throw invalid_argument("peso não pode ser negativo");
        auto node1 = find_node(chave1);
        auto node2 = find_node(chave2);
        if (node1 == nullptr || node2 == nullptr) return;
        node1->arestas.push_back({node2, weight});
        node2->arestas.push_back({node1, weight}); // Grafo não direcionado
    }

    void print() {
        for (auto& aux : list_nodes) {
            cout << aux->chave << endl;
        }
    }

    void print_edges() {
        for (auto& aux : list_nodes) {
            cout << aux->chave << ": ";
            for (auto& aresta : aux->arestas) {
                cout << "(" << aresta.first->chave << ", " << aresta.second << ") ";
            }
            cout << endl;
        }
    }

    void random_graph(int n_nodes) {
        srand(time(0));
        int i=0;
        while(i!=n_nodes){
            int j = rand() % n_nodes + 1; 
            if (find_node(j) == nullptr) {
                add_node(j);
                i++;
            }
        }
        for (int i = 0; i < n_nodes; ++i) {
            int from = rand() % list_nodes.size(); 
            int to = rand() % list_nodes.size();   
            int weight = rand() % 100 + 1;        
            if (from != to) {
                auto from_node = list_nodes[from];
                auto to_node = list_nodes[to];
                add_edge(from_node->chave, to_node->chave, weight);
            }
        }
    }
    
    
    vector<int> djikstra(int ini_key) {
        auto inicio = find_node(ini_key);
        if (inicio == nullptr) {
            cout << "Nodo inicial não encontrado!" << endl;
            return vector<int>();
        }

        vector<int> dist(list_nodes.size(), INF);
        vector<bool> visitados(list_nodes.size(), false);
        priority_queue<pair<int, size_t>, vector<pair<int, size_t>>, greater<pair<int, size_t>>> pq;

        size_t inicio_idx = find_index(inicio);
        dist[inicio_idx] = 0;
        pq.push({0, inicio_idx});

        while (!pq.empty()) {
            size_t menor_idx = pq.top().second;
            pq.pop();

            if (visitados[menor_idx]) continue;
            visitados[menor_idx] = true;

            auto& node_atual = list_nodes[menor_idx];
            for (auto& aresta : node_atual->arestas) {
                size_t vizinho_idx = find_index(aresta.first);
                int peso = aresta.second;

                if (!visitados[vizinho_idx] && dist[menor_idx] + peso < dist[vizinho_idx]) {
                    dist[vizinho_idx] = dist[menor_idx] + peso;
                    pq.push({dist[vizinho_idx], vizinho_idx});
                }
            }
        }
        return dist;
    }


};

int main() {
    graph grafo;
    grafo.random_graph(50000);
    //grafo.print_edges();
    grafo.djikstra(1);

    return 0;
}
