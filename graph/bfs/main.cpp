//
//  main.cpp
//  bfs
//
//  Created by ChengnanHu on 12/17/20.
//

#include <iostream>
#include <queue>
#include <vector>
#include "../graph/graph.h"

void bfs(graph &g, int src, int dest);

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
    
    bfs(g, 0, 7);
    return 0;
}

void bfs(graph &g, int src, int dest)
{
    /* First create a queue and a vector
     * restoring paths and visited nodes
     */
    std::list<int> *adj = g.get_adj();
    std::list<int>::iterator it;
    std::queue<std::vector<int> > q;
    int nnodes = g.get_nnodes();
    std::vector<bool> visited = std::vector<bool> (nnodes, false);
    
    /* add first path */
    std::vector<int> init_path = std::vector<int> ();
    visited[src] = true;
    init_path.push_back(src);
    q.push(init_path);
    
    while(!q.empty())
    {
        std::vector<int> path = std::vector<int> (q.front());
        q.pop();
        int last = path[path.size()-1];
        visited[last] = true;
        /* search paths in adjacent list
         * if last is the distnation, print the path out
         */
        if (last == dest)
        {
            for (int i=0; i<path.size(); i++)
            {
                std::cout << path[i] << ' ';
            }
            std::cout << std::endl;
        }
        
        it = adj[last].begin();
        for (; it!=adj[last].end(); ++it)
        {
            if (visited[*it] == false)
            {
                std::vector<int> new_path(path);
                new_path.push_back(*it);
                q.push(new_path);
            }
        }
    }
}
