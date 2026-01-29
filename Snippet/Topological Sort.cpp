
vector<int>z, ord;
for(i=1; i<=n; i++)
	if(ind[i]==0){
		z.push_back(i);
		vis[i]=1;
	}
while(ord.size()<n){
	if(z.size()==0)
		return void(cout<<"IMPOSSIBLE");
	int cur = z.back();
	z.pop_back();
	ord.push_back(cur);
	for(auto v:gr[cur]){
		ind[v]--;
		if(vis[v]==0 and ind[v]==0){
			z.push_back(v);
			vis[v]=1;
		}
	}
}

