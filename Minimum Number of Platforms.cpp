int convert_to_min(int x)
{
    int res=(x/100)*60+(x%100)%60;
    return res;
}
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    int ans=0;
    //(l, r) pe ho to tumhe wo line chahiye hogi jinka l<=lx<=r ya phir lx<l aur rx>=l
    //kuch aisa keh skte hai ki wo 
    sort(at, at+n);
    sort(dt, dt+n);
    int cur=0;
    int l1=0, l2=0;
    while(l1<n)
    {
        while(l2<n&&dt[l2]<at[l1])
        {
            l2++;
            cur--;
        }
        cur++;
        l1++;
        ans=max(ans, cur);
    }
    return ans;
}