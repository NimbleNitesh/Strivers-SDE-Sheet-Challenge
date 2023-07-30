int NthRoot(int n, int m) {
  // Write your code here.
  double ans=pow(m*1.0, 1.0/n);
  int cur=(int)round(ans);
  // cout << "imp=" << pow(m*1.0, 1.0/n) << endl;
  // cout << ans << ' ' << cur << endl;
  if(pow(cur*1ll, n*1ll)==m)
    return cur;
  return -1;

}