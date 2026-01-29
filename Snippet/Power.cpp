
int power(int a, int n, int mod){
	//for (a^n)%mod
	int ans = 1;
	while(n){
		if(n&1)
			ans = (ans*a)%mod;
		a = (a*a)%mod;
		n/=2;
	}
	return ans;
}
