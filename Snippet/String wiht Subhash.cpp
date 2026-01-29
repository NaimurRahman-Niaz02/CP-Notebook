
const int p1=137, p2=277, mod1=1e9+7, mod2=987654319;
pair<int, int> pw[N], ipw[N], pre[N];
int power(int a, int n, int mod){
	int ans = 1;
	while(n){
		if(n&1) ans = (ans*a)%mod;
		a = (a*a)%mod;
		n/=2;
	}
	return ans;
}
void pwr(){
	pw[0]={1, 1};
	for(int i=1; i<N; i++){
		pw[i].first=(pw[i-1].first*p1)%mod1;
		pw[i].second= (pw[i-1].second*p2)%mod2;
	}
	int ip1= power(p1, mod1-2, mod1);
	int ip2= power(p2, mod2-2, mod2);
	ipw[0]={1, 1};
	for(int i=1; i<N; i++){
		ipw[i].first= (ipw[i-1].first*ip1)%mod1;
		ipw[i].second= (ipw[i-1].second*ip2)%mod2;
	}
}
pair<int, int> str_hash(string a){
	int n=a.size();
	pair<int, int> hash={0, 0};
	for(int i=0; i<n; i++){
		hash.first += (pw[i].first*a[i])%mod1;
		hash.first %= mod1;
		hash.second += (pw[i].second*a[i])%mod2;
		hash.second %= mod2;
	}
	return hash;
}
void build(string a){
	int n=a.size();
	for(int i=0; i<n; i++){
		pre[i].first= (pw[i].first*a[i])%mod1;
		if(i) pre[i].first= (pre[i].first+ pre[i-1].first)%mod1;
		pre[i].second= (pw[i].second * a[i])%mod2;
		if(i) pre[i].second= (pre[i].second + pre[i-1].second)%mod2;
	}
}
pair<int, int> sub_hash(int i, int j){
	pair<int, int>hash;
	hash.first= pre[j].first;
	if(i) hash.first= (hash.first- pre[i-1].first + mod1)%mod1;
	hash.first= (hash.first*ipw[i].first) %mod1;
	hash.second= pre[j].second;
	if(i) hash.second= (hash.second- pre[i-1].second + mod2)%mod2;
	hash.second= (hash.second*ipw[i].second) %mod2;
	return hash;
}


