struct dsu{
   vector<ll>parent;
   vector<ll>size;
    dsu(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=1;i<=n;i++){
          parent[i]=i;
          size[i]=1;
        }
   }
   ll find(ll v){
     if(parent[v]==v) return v;
     return parent[v]=find(parent[v]);
}
void Union(ll a,ll b){
    a=find(a);
     b=find(b);
     if(a!=b){
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b]=a;
        size[a]+=size[b];
     }
}  
};
