vector<int> dijkstra(int src){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	vector<int>dis(N, M);
	vector<bool>vis(N, false);
	pq.push({0, src});
	dis[src]=0;
	while(pq.size()){
		auto x= pq.top();
		pq.pop();
		int u= x.second;
		if(vis[u])
			continue;
		vis[u]=true;
		for(auto it:gr[u]){
			int v= it.first;
			int w= it.second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				pq.push({dis[v], v});
			}
		}
	}	
	return dis;
}