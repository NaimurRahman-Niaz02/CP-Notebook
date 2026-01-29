int fa[N], invfa[N];
int power(int a, int n, int mod){
	int ans = 1;
	while(n){
		if(n&1)
			ans = (ans*a)%mod;
		a = (a*a)%mod;
		n/=2;
	}
	return ans;
}
void factorial(){
	fa[0]=1;
	for(int i=1; i<N; i++)
		fa[i]=(fa[i-1]*i)%M;
	invfa[N-1]=power(fa[N-1], M-2, M);
	for(int i=N-2; i>=0; i--)
		invfa[i]=(invfa[i+1]*(i+1))%M;
}
int ncr(int n, int r){
	if(n<r) return 0;
	return (fa[n]*invfa[r]%M)*invfa[n-r]%M;
}
int npr(int n, int r){
	if(n<r) return 0;
	return (fa[n]*invfa[n-r])%M;
}
