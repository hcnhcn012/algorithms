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
    /* buggy decleration when using iterator of list object */
//    this->__adj_list = std::vector<std::list<int>> (MAX_NODES);
    /* fixed */
    this->__adj_list = new std::list<int>[MAX_NODES]();
}

graph::~graph()
{
    delete [] this->__adj_list;
}

void graph::add_edge(int node1_idx, int node2_idx)
{
    this->__adj_list[node1_idx].push_back(node2_idx);
    this->__adj_list[node2_idx].push_back(node1_idx);
}

/* buggy get_adj when using iterator of list object */
//const std::vector<std::list<int>>& graph::get_adj() const
//{
//    return this->__adj_list;
//}

/* fixed */
std::list<int> *graph::get_adj()
{
    return this->__adj_list;
}

int graph::get_nnodes() const
{
    return this->nnodes;
}
