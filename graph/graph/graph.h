//
//  graph.h
//  graph
//
//  Created by ChengnanHu on 12/15/20.
//

#ifndef graph_h
#define graph_h

#include <iostream>
#include <list>
#include <array>

#define MAX_NODES 50

typedef unsigned char byte;

class graph
{
private:
    int nnodes;
    /* using array and list from STL as a adjacency list */
    std::array<std::list<int>, MAX_NODES> __adj_list;
    
public:
    graph(int _nnodes);
    
    void add_edge(int node1_idx, int node2_idx);
    const std::array<std::list<int>, MAX_NODES>& get_adj() const;
    int get_nnodes() const;
};


#endif /* graph_h */
