//
//  main.cpp
//  dfs
//
//  Created by ChengnanHu on 12/18/20.
//

#include <iostream>
#include <vector>
#include <list>
#include "../graph/graph.h"

#define MAX_STEP 100

using namespace std;
void dfs(int src, int dest, vector<int> &result, vector<bool> &visited, list<int> *adj);


int main(int argc, const char * argv[])
{
    graph g = graph(8);
    g.add_edge(0, 1);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(1, 4);
    g.add_edge(3, 4);
    g.add_edge(2, 5);
    g.add_edge(4, 5);
    g.add_edge(4, 6);
    g.add_edge(5, 7);
    g.add_edge(6, 7);
    
    vector<int> result = vector<int> (MAX_STEP, -1);
    vector<bool> visited = vector<bool>(g.get_nnodes(), false);
    /* buggy */
//    std::vector<std::list<int>> adj = g.get_adj();
    /* fixed */
    list<int> *adj = g.get_adj();
    dfs(0, 7, result, visited, adj);
    return 0;
}

void dfs(int src, int dest, vector<int> &result, vector<bool> &visited, list<int> *adj)
{
    /* Recursion exit (when found a path)*/
    if (src == dest)
    {
        /* print the result */
        for (int i=0; i<result.size(); i++)
        {
            cout << result[i] << ' ';
        }
        cout << endl;
    }
    
    for (list<int>::iterator it = adj[src].begin(); it!=adj[src].end(); it++)
    {
        /* if not visited, searching at the next node */
        if (!visited[*it])
        {
            result[*it] = src;
            visited[*it] = true;
            dfs(*it, dest, result, visited, adj);
        }
    }
}
