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
#include <vector>

#define MAX_NODES 50

typedef unsigned char byte;

class graph
{
private:
    int nnodes;
    /* using a vector of lists from STL as a adjacency list (buggy)*/
    /* buggy decleration when using iterator of list object */
//    std::vector<std::list<int>> __adj_list;
    /* fixed */
    std::list<int> *__adj_list;
    
public:
    graph(int _nnodes);
    ~graph();
    
    void add_edge(int node1_idx, int node2_idx);
    /* buggy get_adj when using iterator of list object */
//    const std::vector<std::list<int>>& get_adj() const;
    /* fixed */
    std::list<int> *get_adj();
    int get_nnodes() const;
};


#endif /* graph_h */
