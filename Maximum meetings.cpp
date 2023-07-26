bool sortbysec(pair<int, int> &a, pair<int, int> &b)
{
    return a.second<b.second;
}
int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    int n=start.size();
    vector<pair<int, int>> full(n);
    for(int i=0;i<n;i++)
    {
        full[i]={start[i], end[i]};
    }
    sort(full.begin(), full.end(), sortbysec);
    int ans=0;
    int prev=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(prev<full[i].first)
        {
            ans++;
            prev=full[i].second;
        }
    }
    return ans;
}