@6F1 @for (int i = 1; i <= n; i++) distance[i] = INF;
@BB0 @distance[x] = 0;
@FFB @q.push({0,x});
@14D @while (!q.empty()) {
@A44 @  int a = q.top().second; q.pop();
@48E @  if (processed[a]) continue;
@DA9 @  processed[a] = true;
@A32 @  for (auto u : adj[a]) {
@D5D @    int b = u.first, w = u.second;
@803 @    if (distance[a]+w < distance[b]) {
@C49 @      distance[b] = distance[a]+w;
@CF7 @      q.push({-distance[b],b}); // peso negativo pq e uma maxheap, se for fazer com min_heap colocar positivo
@8A5 @    }
@B4E @  }
@724 @}
