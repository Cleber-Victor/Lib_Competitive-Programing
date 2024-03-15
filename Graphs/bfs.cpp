vis[x] = 1;
dist[x] = 0;
q.push(x);
while(!q.empty()){
  int s = q.front(); q.pop();

  for (auto u : adj[s]){
    if(vis[u]) continue;
    vis[u] = true;
    dist[u] = dist[s] + 1;
    q.push(u);
  }
}