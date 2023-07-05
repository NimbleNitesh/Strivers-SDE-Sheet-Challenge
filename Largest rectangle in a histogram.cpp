#include <vector>
#include <algorithm>
struct SegmentTree{
  int n, size=1;
  vector<int> seg;
  SegmentTree(int n)
  {
    this->n=n;
    while(size<n)
      size*=2;
    seg.assign(2*size, 0);
  }
  void set(int i, int v)
  {
    set(i, v, 0, 0, size);
  }
  void set(int i, int v, int x, int lx, int rx)
  {
    if(rx-lx==1)
    {
      seg[x]=v;
      return;
    }
    int mx=(lx+rx)/2;
    if(i<mx)
      set(i, v, 2*x+1, lx, mx);
    else
      set(i, v, 2*x+2, mx, rx);
    seg[x]=min(seg[2*x+1], seg[2*x+2]);
  }
  int query1(int l, int r, int v)
  {
    return query1(l, r, v, 0, 0, size);
  }
  int query1(int l, int r, int v, int x, int lx, int rx)
  {
    if(l>=rx||lx>=r)
      return -1;
    if(seg[x]>v)
      return -1;
    if(rx-lx==1)
      return lx;
    int mx=(lx+rx)/2;
    int res=query1(l, r, v, 2*x+1, lx, mx);
    if(res==-1)
      return query1(l, r, v, 2*x+2, mx, rx);
    return res;
  }
  int query2(int l, int r, int v)
  {
    return query2(l, r, v, 0, 0, size);
  }
  int query2(int l, int r, int v, int x, int lx, int rx)
  {
    if(l>=rx||lx>=r)
      return -1;
    if(seg[x]>v)
      return -1;
    if(rx-lx==1)
      return lx;
    int mx=(lx+rx)/2;
    int res=query2(l, r, v, 2*x+2, mx, rx);
    if(res==-1)
      return query2(l, r, v, 2*x+1, lx, mx);
    return res;
  }
};

 int largestRectangle(vector <int> &heights) {
   // Write your code here.
    //q1(l, r, v): first index whose value is atmost v
    //q2(l, r, v): last index whose value is atmost v
    int n=heights.size();
    SegmentTree st(n);
    for(int i=0;i<n;i++)
      st.set(i, heights[i]);
    int ans=0;
    for(int i=0;i<n;i++)
    {
      int i1=i>0?st.query2(0, i, heights[i]-1):-1;
      int i2=i<(n-1)?st.query1(i+1, n, heights[i]-1):-1;
      int cur=1;
      if(i1!=-1)
        cur+=(i-i1-1);
      else
        cur+=i;
      if(i2!=-1)
        cur+=(i2-i-1);
      else
        cur+=(n-1-i);
      // cout << heights[i] << ' ' << i1 << ' ' << i2 << endl;
      cur*=heights[i];
      ans=max(ans, cur);
    }
    return ans;
 }