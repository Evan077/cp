void z_function(string s,ll z[]) {
	ll n = s.size();
	ll l = 0, r = 0;
	for(int i = 1; i < n; i++) {
		if(i < r) {
			z[i] = min(r - i, z[i - l]);
		}
		while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}
		if(i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}
}
