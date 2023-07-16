#include <bits/stdc++.h>
void findMedian(int *arr, int n)
{
    // Write your code here
    multiset<int> r;
    multiset<int, greater<int>> l;
    for(int i=0;i<n;i++)
    {
        int l_size=l.size();
        int r_size=r.size();
        if(l_size==r_size)
        {
            if(l.empty())
            {
                l.insert(arr[i]);
                cout << arr[i] << ' ';
                continue;
            }
            int val=(*r.begin());
            if(arr[i]<=val)
            {
                l.insert(arr[i]);
                cout << (*l.begin()) << ' ';
            }
            else
            {
                r.insert(arr[i]);
                cout << (*r.begin()) << ' ';
            }
        }
        else if(l_size>r_size)
        {
            l.insert(arr[i]);
            while(l_size>r_size)
            {
                r.insert(*l.begin());
                l.erase(l.begin());
                l_size--;
                r_size++;
            }
            int val=(*l.begin()+*r.begin())/2;
            cout << val << ' ';
        }
        else
        {
            r.insert(arr[i]);
            while(l_size<r_size)
            {
                l.insert(*r.begin());
                r.erase(r.begin());
                l_size++;
                r_size--;
            }
            int val=(*l.begin()+*r.begin())/2;
            cout << val << ' ';
        }
    }
    cout << endl;
}