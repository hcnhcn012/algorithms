//
//  main.cpp
//  Toposort
//
//  Created by ChengnanHu on 3/3/21.
//

#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>

using namespace std;

class graph
{
private:
    list<char> *__adj_list;
    int __size;
    int __max_node_idx;
    
public:
    graph(int size);
    void add_node(char a);
    void link_node(char a, char b);
    void topo_sort();
};

graph::graph(int size)
{
    this->__size = size;
    this->__max_node_idx = -1;
    this->__adj_list = new list<char>[size];
    
}

void graph::add_node(char a)
{
    this->__adj_list[++__max_node_idx].push_back(a);
}

void graph::link_node(char a, char b)
{
    /* a->b */
    for (int i=0; i<__size; i++)
    {
        if (__adj_list[i].front() == a) __adj_list[i].push_back(b);
    }
}

void graph::topo_sort()
{
    unordered_map<char, int> umap;
    queue<char> q;
    
    /* find nodes whose indegree is 0 */
    for (int i=0; i<__size; i++)
    {
        auto it = __adj_list[i].begin();
        /* start at second value, first is self */
        if (umap.find(*it) == umap.end()) umap[*it] = 0;
        while (++it !=__adj_list[i].end())
        {
            umap[*it]++;
        }
    }
    for (int i=0; i<__size; i++)
    {
        if (umap[this->__adj_list[i].front()] == 0)
            q.push(this->__adj_list[i].front());
    }
    while (!q.empty())
    {
        char a = q.front(); q.pop();
        cout << a << "->";
        for (int i=0; i<__size; i++)
        {
            if (this->__adj_list[i].front() == a)
            {
                for (auto it=__adj_list[i].begin(); it != __adj_list[i].end(); it++)
                {
                    umap[*it]--;
                    if (umap[*it] == 0) q.push(*it);
                }
            }
            
        }
    }
}

int main(int argc, const char * argv[])
{
    graph g = graph(6);
    g.add_node('a');
    g.add_node('b');
    g.add_node('c');
    g.add_node('d');
    g.add_node('e');
    g.add_node('f');
    
    g.link_node('b', 'a');
    g.link_node('b', 'd');
    g.link_node('c', 'b');
    g.link_node('c', 'f');
    g.link_node('e', 'b');
    g.link_node('f', 'b');
    
    g.topo_sort();
}
