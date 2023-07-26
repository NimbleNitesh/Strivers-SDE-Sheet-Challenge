#include <set>
#include <algorithm>
bool customsort(vector<int> &a, vector<int> &b)
{
    return a[2]>b[2];
}
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    // sort(jobs.begin(), jobs.end(), customsort);
    int n=jobs.size();
    vector<int> logs(2, 0);
    set<int> time_slots;
    for(int i=1;i<=n;i++)
        time_slots.insert(i);
    sort(jobs.begin(), jobs.end(), customsort);
    for(int i=0;i<n;i++)
    {
        int deadline=jobs[i][1];
        auto it=time_slots.upper_bound(deadline);
        if(it==time_slots.begin())
            continue;
        it--;
        logs[1]+=jobs[i][2];
        logs[0]++;
        time_slots.erase(it);
    }
    return logs;
}