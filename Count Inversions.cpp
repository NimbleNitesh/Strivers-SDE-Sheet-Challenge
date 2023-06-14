#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

//find_by_order(k)  returns iterator to kth element starting from 0;
//order_of_key(k) returns count of elements strictly smaller than k;
long long getInversions(long long *arr, int n){
    // Write your code here.
    long long ans=0;
    ordered_set<int> full;
    for(int i=0;i<n;i++)
        full.insert(arr[i]);
    for(int i=0;i<n;i++)
    {
        int cur=full.order_of_key(arr[i]);
        ans+=cur;
        full.erase(full.find(arr[i]));
    }
    return ans;
    
}