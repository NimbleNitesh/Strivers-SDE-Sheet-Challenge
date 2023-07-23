vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    set<pair<int, int>> full;
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        while(j<n&&arr[j]==arr[i])
            j++;
        full.insert({j-i, arr[i]});
        int fs=full.size();
        if(fs>k)
            full.erase(full.begin());
        i=j-1;
    }
    for(auto i: full)
        res.push_back(i.second);
    return res;
}