//
//  main.cpp
//  activity_arrange_problem
//
//  Created by ChengnanHu on 12/28/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define ACTI_SZ 6

using namespace std;

struct activity_s
{
    int start_time;
    int end_time;
};

vector<bool> activity_select(vector<activity_s> &activities);
bool acti_cmp(const struct activity_s &ac1, const struct activity_s &ac2);

int main(int argc, const char * argv[])
{
    vector<activity_s> activities = vector<activity_s>();
    struct activity_s a1 = {
        .start_time = 6,
        .end_time = 8
    };
    struct activity_s a2 = {
        .start_time = 2,
        .end_time = 4
    };
    struct activity_s a3 = {
        .start_time = 3,
        .end_time = 5
    };
    struct activity_s a4 = {
        .start_time = 1,
        .end_time = 5
    };
    struct activity_s a5 = {
        .start_time = 5,
        .end_time = 9
    };
    struct activity_s a6 = {
        .start_time = 8,
        .end_time = 10
    };
    activities.push_back(a1);
    activities.push_back(a2);
    activities.push_back(a3);
    activities.push_back(a4);
    activities.push_back(a5);
    activities.push_back(a6);
    
    vector<bool> ans = activity_select(activities);
    for (int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
    
    
    return 0;
}

bool acti_cmp(const struct activity_s &ac1, const struct activity_s &ac2)
{
    return ac1.end_time < ac2.end_time;
}

vector<bool> activity_select(vector<activity_s> &activities)
{
    vector<bool> ans = vector<bool>(activities.size(), false);
    /* sort by end_time */
    sort(activities.begin(), activities.end(), acti_cmp);
    ans[0] = true;
    int last_end = activities[0].end_time;
    for (int i=1; i<activities.size(); i++)
    {
        if (activities[i].start_time >= last_end)
        {
            ans[i] = true;
            last_end = activities[i].end_time;
        }
    }
    return ans;
}

