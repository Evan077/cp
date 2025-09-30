for(int i=0;i<n;i++){
		for(int j=0;j<primes.size()&&primes[j]*primes[j]<=a[i];j++){
			if(a[i]%primes[j]==0){
				ll cnt=1;
				while(a[i]%primes[j]==0){
					cnt*=primes[j];
					a[i]/=primes[j];
				}
				m[primes[j]]=max(m[primes[j]],cnt);
			}
		}
		if(a[i]!=1){
			m[a[i]]=max(m[a[i]],a[i]);
		}
	}
//use sieve snippets with it
