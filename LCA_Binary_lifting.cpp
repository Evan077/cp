void dfs(vector<vector<ll>>&g,vector<vector<ll>>&up ,ll ver,ll par,ll depth[]){
	// vector<vector<ll>>up(n+1,vector<ll>(20,0));
	depth[ver]=depth[par]+1;
	for(auto it:g[ver]){
		if(it!=par){
			up[it][0]=ver;
			for(ll i=1;i<20;i++){
				up[it][i]=up[up[it][i-1]][i-1];
			}
			dfs(g,up,it,ver,depth);
		}
	}

}
ll get_lca(ll a,ll b,vector<vector<ll>>&up,ll depth[]){
	if(a==b)return a;
	if(depth[a]<depth[b])swap(a,b);
	ll diff=depth[a]-depth[b];
	for(ll i=19;i>=0;i--){
		if(diff&(1<<i)){
			a=up[a][i];
		}
	}
	if(a==b)return a;
	for(ll i=19;i>=0;i--){
		if(up[a][i]!=up[b][i]){
			a=up[a][i];
			b=up[b][i];
		}
	}
	
	return up[a][0];

}
