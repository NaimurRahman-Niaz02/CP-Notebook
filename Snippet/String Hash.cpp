
const int p1=137, p2=277, mod1=1e9+7, mod2=987654319;
pair<int, int> pw[N];
void pwr(){
	pw[0].first=1;
	pw[0].second=1;
	for(int i=1; i<N; i++){
		pw[i].first=(pw[i-1].first*p1)%mod1;
		pw[i].second=(pw[i-1].second*p2)%mod2;
	}
}
pair<int, int> get_hash(string a){
	int n=a.size();
	pair<int, int>hash={0, 0};
	for(int i=0; i<n; i++){
		hash.first += (pw[i].first*a[i])%mod1;
		hash.first %= mod1;
		hash.second += (pw[i].second*a[i])%mod2;
		hash.second %= mod2;
	}
	return hash;
}
