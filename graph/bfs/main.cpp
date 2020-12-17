//
//  main.cpp
//  bfs
//
//  Created by ChengnanHu on 12/17/20.
//

#include <iostream>
#include <queue>
#include <vector>
#include <array>
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
    std::array<std::list<int>, MAX_NODES> adj = g.get_adj();
    std::queue<std::vector<int>> q;
    /* add first path */
    std::vector<int> init_path = std::vector<int> (1);
    init_path.push_back(src);
    q.push(init_path);
    while (!q.empty())
    {
        std::vector<int> path = q.front();
        q.pop();
        int last = path[path.size()-1];
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
        std::list<int>::iterator it;
        for (it=adj[last].begin(); it!=adj[last].end(); it++)
        {
            std::vector<int> new_path = std::vector<int> (path);
            new_path.push_back(*it);
        }
    }
}
