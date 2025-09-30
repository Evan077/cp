ll rais_to_power(ll a,ll n){
	ll res=1;
	while(n){
		if(n%2!=0){
			res=(res*a)%mod;
			n--;
		}
		else{
			a=(a*a)%mod;
			n/=2;
		}
	}
	return res;
}
