#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;    //NÃºmero de vertices

    // Ponteiro para uma vetor contendo listas de adjacÃªncias
    list<int> *adj;
     // Vector to store indegree of vertices
    vector<int> indegree;

    // A function used by alltopologicalSort
    void alltopologicalSortUtil(vector<int> &res, bool visited[]);

public:
    Graph(int V);   // Constructor

    // FunÃ§Ã£o que adiciona aresta ao grafo
    void addEdge(int u, int v);

    // Prints all Topological Sorts
    void alltopologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    // Initialising all indegree with 0
    for (int i = 0; i < V; i++)
        indegree.push_back(0);
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    // increasing inner degree of w by 1
    indegree[v]++;
}

//  Main recursive function to print all possible
//  topological sorts
void Graph::alltopologicalSortUtil(vector<int> &res, bool visited[])
{
    // To indicate whether all topological are found
    // or not
    bool flag = false;

    for (int i = 0; i < V; i++)
    {
        //  If indegree is 0 and not yet visited then
        //  only choose that vertex
        if (indegree[i] == 0 && !visited[i])
        {
            //  reducing indegree of adjacent vertices
            list<int>:: iterator j;
            for (j = adj[i].begin(); j != adj[i].end(); j++)
                indegree[*j]--;

            //  including in result
            res.push_back(i);
            visited[i] = true;
            alltopologicalSortUtil(res, visited);

            // resetting visited, res and indegree for
            // backtracking
            visited[i] = false;
            res.erase(res.end() - 1);
            for (j = adj[i].begin(); j != adj[i].end(); j++)
                indegree[*j]++;

            flag = true;
        }
    }

    //  We reach here if all vertices are visited.
    //  So we print the solution here
    if (!flag)
    {
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}

//  The function does all Topological Sort.
//  It uses recursive alltopologicalSortUtil()
void Graph::alltopologicalSort()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    vector<int> res;
    alltopologicalSortUtil(res, visited);
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

    printf("Todas as ordenaÃ§Ãµes Topologica do grafo:\n");
    g.alltopologicalSort();

    return 0;
}
