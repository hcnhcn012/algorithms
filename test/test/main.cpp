//
//  main.cpp
//  test
//
//  Created by ChengnanHu on 11/12/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

int step(int n);
int step2(int n);

using namespace std;

int main(int argc, const char * argv[])
{
    cout << step(20) << endl;
    cout << step2(20) << endl;
}

int step(int n)
{
    if (n == 1 || n == 0) return 1;
    return step(n-1)+step(n-2);
}

int step2(int n)
{
    if (n == 1)
        return 1;
    
    if (n == 2)
        return 2;
    
    return step(n-1)+step(n-2);
}
