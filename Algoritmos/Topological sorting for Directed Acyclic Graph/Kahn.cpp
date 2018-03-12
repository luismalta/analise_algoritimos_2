#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;    //NÃºmero de vertices

    // Ponteiro para uma vetor contendo listas de adjacÃªncias
    list<int> *adj;

public:
    Graph(int V);   // Constructor

    // FunÃ§Ã£o que adiciona aresta ao grafo
    void addEdge(int u, int v);

    // Imprimi um grafo Topologico ordenado do grafo completo
    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

// A funÃ§Ã£o do Grafo Topologico Ordenado
void Graph::topologicalSort()
{
    // Cria um vetor para armazenar todos os vÃ©rtices indevidos.
    // Inicialize todos os indevidos como 0.
    vector<int> in_degree(V, 0);

    // Atravessa a listas de adjacÃªncia para preencher os vÃ©rtices
    // indevidos. Este passo leva o tempo de O (V + E).
    for (int u=0; u<V; u++)
    {
        list<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
             in_degree[*itr]++;
    }

    // Crie uma fila e em fila todos os vÃ©rtices indevidos com 0
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            q.push(i);

    // Inicializa contagem de vÃ©rtices visitados
    int cnt = 0;

    // Cria um vetor para armazenar o resultado
    // (Uma ordenaÃ§Ã£o topolÃ³gica dos vÃ©rtices)
    vector <int> top_order;

    // One by one dequeue vertices from queue and enqueue
    // adjacents if indegree of adjacent becomes 0
    while (!q.empty())
    {
        // Extract front of queue (or perform dequeue)
        // and add it to topological order
        int u = q.front();
        q.pop();
        top_order.push_back(u);

        // Iterate through all its neighbouring nodes
        // of dequeued node u and decrease their in-degree
        // by 1
        list<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++)

            // If in-degree becomes zero, add it to queue
            if (--in_degree[*itr] == 0)
                q.push(*itr);

        cnt++;
    }

    // Checa se tem um ciclo no grafo
    if (cnt != V)
    {
        printf("Existe um ciclo no grafo\n");
        return;
    }

    // Imprime a ordenaÃ§Ã£o topologica do grafo
    for (int i=0; i<top_order.size(); i++)
        printf("%d  ", top_order[i]);
    printf("\n");
}

int main()
{
    int n, a, b;
    scanf("%d", &n);
    Graph g(n); // Tamanho do Grafo
    for (int i = 0; i < n; i++)
    {
    // O grafo Ã© direcionado do nÃ³ a para o nÃ³ b
		scanf("%d %d", &a, &b);
		g.addEdge(a, b);
    }

    printf("A seguir uma ordenaÃ§Ã£o Topologica do grafo:\n");
    g.topologicalSort();

    return 0;
}
