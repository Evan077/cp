string multi(string s,ll a){
		ll cary=0;
		string ans;
		for(int i=s.size()-1;i>=0;i--){
			cary=((s[i]-'0')*a)+cary;
			string ss=to_string(cary%10);
			ans=ss+ans;
			cary/=10;
		}
		while(cary!=0){
			string ss=to_string(cary%10);
			ans=ss+ans;
			cary/=10;
		}
		return ans;
	}
