struct segtre {
  ll n;
  vector<vector<ll>>st;

  void init(ll _n) {
    this->n = _n;
    st.resize(4 * n);
  }

  void build(ll start, ll ending, ll node, vector<ll> &v) {
    // leaf node base case
    if (start == ending) {
      st[node].push_back(v[start]);
      return;
    }
    ll mid = (start + ending) / 2;
    // left subtree is (start,mid)
    build(start, mid, 2 * node + 1, v);
    // right subtree is (mid+1,ending)
    build(mid + 1, ending, 2 * node + 2, v);
     ll i=0;
     ll j=0;
     while(i<st[2*node+1].size()&&j<st[2*node+2].size()){
       if(st[2*node+1][i]<=st[2*node+2][j]){
            st[node].push_back(st[2*node+1][i]);i++;
       }
       else {
         st[node].push_back(st[2*node+2][j]);j++;
       }
     }
     while(i<st[2*node+1].size()){
       st[node].push_back(st[2*node+1][i]);i++;
     }
     while(j<st[2*node+2].size()){
       st[node].push_back(st[2*node+2][j]);j++;
     }
  }

  ll query(ll start, ll ending, ll l, ll r, ll node,ll ter) {
    // non overlapping case
    if (start > r || ending < l) {
      return 0;
    }
    // complete overlap
    if (start >= l && ending <= r) {
      return bs(st[node],ter);
    }

    // partial case
    ll mid = (start + ending) / 2;
    ll q1 = query(start, mid, l, r, 2 * node + 1,ter);
    ll q2 = query(mid + 1, ending, l, r, 2 * node + 2,ter);
    return q1 + q2;
  }

  void build(vector<ll> &v) {
    build(0, n - 1, 0, v);
  }

  ll query(ll l, ll r,ll ter) {
    return query(0, n - 1, l, r, 0,ter);
  }

};
