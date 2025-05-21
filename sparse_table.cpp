 struct spr
{
  ll n;
  int b=20;
    vector<vector<ll>>v;
    void in_it(ll _n){
       this->n=_n;
       v.resize(n+1);
       for(int i=0;i<=n;i++){
         v[i].resize(b+1,0);
       }
    }
    void build(ll a[]){
       for(int i=1;i<=n;i++){v[i][0]=a[i];}
      for(int k=1;k<=b;k++){
          for(int i=1;i+(1<<k)-1<=n;i++){
              v[i][k]=min(v[i][k-1],v[i+(1<<(k-1))][k-1]);
          }
      }
}
  ll Rmnq(ll l,ll r){
     int k=31-__builtin_clz(r-l+1);
     return min(v[l][k],v[r-(1<<k)+1][k]);
  }
};
