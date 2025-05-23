struct segmenttree {
    int n;
    vector<int> st, lazy;

    void init(int _n) {
        this->n = _n;
        st.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }
   inline void push(ll node ,ll start ,ll ending){
        if(lazy[node]==0) return;
        st[node]=st[node]+lazy[node]*(ending-start+1);
        if(start!=ending){
            lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
   }
   inline void uthao(ll node){
    st[node] = st[node * 2 + 1] + st[node * 2 + 2];
   }
   inline ll milao(ll x,ll y){
       return x+y;
   }
    void build(int start, int ending, int node, vector<int> &v) {
        // leaf node base case
        if (start == ending) {
            st[node] = v[start];
            return;
        }

        int mid = (start + ending) / 2;

        // left subtree is (start,mid)
        build(start, mid, 2 * node + 1, v);

        // right subtree is (mid+1,ending)
        build(mid + 1, ending, 2 * node + 2, v);

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }

    int query(int start, int ending, int l, int r, int node) {
        // non overlapping case
        push(node,start,ending);
        if (start > r || ending < l) {
            return 0;
        }

        // lazy propagation / clear the lazy update
        push(node,start,ending);
        // complete overlap
        if (start >= l && ending <= r) {
            return st[node];
        }

        // partial case
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return milao(q1,q2);
    }

    void update(int start, int ending, int node, int l, int r, int value) {
        // non overlapping case
        push(node,start,ending);
        if (start > r || ending < l) {
            return ;
        }

        // lazy propagation / clear the lazy update
        // complete overlap
        if (start >= l && ending <= r) {
            lazy[node]=value;
           push(node,start,ending);
            return;
        }

        // partial case
        int mid = (start + ending) / 2;

        update(start, mid, 2 * node + 1, l, r, value);

        update(mid + 1, ending, 2 * node + 2, l, r, value);

        uthao(node);

        return;
    }

    void build(vector<int> &v) {
        build(0, n - 1, 0, v);
    }

    int query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }

    void update(int l, int r, int x) {
        update(0, n - 1, 0, l, r, x);
    }
};
