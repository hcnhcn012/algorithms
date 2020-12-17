//
//  main.cpp
//  graph
//
//  Created by ChengnanHu on 12/15/20.
//

#include <iostream>
#include "graph.h"

graph::graph(int _nnodes)
{
    this->nnodes = _nnodes;
    for (int i=0; i<MAX_NODES; i++)
    {
        this->__adj_list[i] = std::list<int> (MAX_NODES-1, INT_MIN);
    }
}

void graph::add_edge(int node1_idx, int node2_idx)
{
    this->__adj_list[node1_idx].push_back(node2_idx);
    this->__adj_list[node2_idx].push_back(node1_idx);
}

const std::array<std::list<int>, MAX_NODES>& graph::get_adj() const
{
    return this->__adj_list;
}

int graph::get_nnodes() const
{
    return this->nnodes;
}
