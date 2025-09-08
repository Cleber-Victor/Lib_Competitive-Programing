@450 @vis[x] = 1;
@336 @dist[x] = 0;
@E7C @q.push(x);
@14D @while(!q.empty()){
@D15 @  int s = q.front(); q.pop();
@    @
@942 @  for (auto u : adj[s]){
@497 @    if(vis[u]) continue;
@B9C @    vis[u] = true;
@408 @    dist[u] = dist[s] + 1;
@F73 @    q.push(u);
@173 @  }
@84D @}
