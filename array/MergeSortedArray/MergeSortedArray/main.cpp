//
//  main.cpp
//  MergeSortedArray
//
//  Created by ChengnanHu on 10/19/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void MergeSortedArray(vector<int>& nums1, int m, vector<int>& nums2, int n);

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    unsigned int m = 3;
    unsigned int n = 3;

    std::cout << "nums1: ";
    for (int i=0; i<m; i++)
        std::cout << nums1[i] << ' ';
    std::cout << endl;
    std::cout << "nums2: ";
    for (int j=0; j<n; j++)
        std::cout << nums2[j] << ' ';
    std::cout << endl;
    
    MergeSortedArray(nums1, m, nums2, n);
    std::cout << "nums1(After merge): ";
    for (int k=0; k<6; k++)
        std::cout << nums1[k] << ' ';
    std::cout << endl;
    
    return 0;
}


void MergeSortedArray(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i;
    for (i=0; i<n; i++)
        nums1[m+i] = nums2[i];
    sort(nums1.begin(), nums1.end());
}
