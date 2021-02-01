//
//  main.cpp
//  mid_num_heap
//
//  Created by ChengnanHu on 2/1/21.
//

#include <iostream>
#include <queue>

using namespace std;

void Insert(int num);
double GetMiddle();


priority_queue<int> max_heap;
priority_queue<int, vector<int >, greater<int >> min_heap;
int n = 0;

int main(int argc, const char * argv[])
{
    vector<int> v = {5,2,3,4,1,6,7,0,8};
    for (int i=0; i<v.size(); i++)
    {
        Insert(v[i]);
    }
    cout << GetMiddle() << endl;
    return 0;
}
    
void Insert(int num)
{
    ++n;
    if (n == 1) max_heap.push(num);
    if (n == 2) min_heap.push(num);
    
    if (n % 2 == 0)
    {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();
    }
    
    else
    {
        min_heap.push(num);
        max_heap.push(min_heap.top());
        min_heap.pop();
    }
}

double GetMiddle()
{
    if (n % 2 == 0)
        return (double)((min_heap.top() + max_heap.top() + 0.0) / 2);
    else
        return (double)min_heap.top();
}
