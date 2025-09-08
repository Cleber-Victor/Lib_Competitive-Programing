@EF9 @const int ms = 501;
@F50 @bool vis[ms][ms];
@14E @int n,m;
@A75 @int grid[ms][ms];
@7CC @int dist[ms][ms];
@    @
@89C @bool inRange(int x, int y){
@8E7 @  return x>=0 && x < n && y>=0 && y <m;
@6C4 @}
@495 @int dx[] = {0,0,1,-1};
@B0A @int dy[] = {1,-1,0,0};
@D53 @int bfs(){
@8C1 @  priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>>pq;
@606 @  memset(vis,false,sizeof(vis));
@6AD @  for(int i = 0; i < ms; i++) {
@850 @    for(int j = 0; j < ms; j++) {
@AE8 @        dist[i][j] = 1000000;
@39D @    }
@D66 @}
@    @
@72E @  vis[0][0] = 1;
@8E7 @  dist[0][0]= 0;
@C8C @  pq.push({0,{0,0}});
@669 @  int d = 0;
@502 @  while(!pq.empty()){
@557 @    int sz = pq.size();
@2F9 @    while(sz--){
@52A @      int d =pq.top().first;
@9F3 @      int x = pq.top().second.first;
@B8D @      int y = pq.top().second.second;
@716 @      pq.pop();
@11E @      if(x == n-1 && y == m-1) return dist[n-1][m-1];
@1CD @      for(int i = 0; i < 4; i++){
@6EB @        int ax = x + dx[i], ay = y +dy[i];
@A3A @        if(inRange(ax,ay) && !vis[ax][ay]){
@078 @          int camim = 1-grid[ax][ay];
@2C6 @          if(dist[x][y] + camim < dist[ax][ay]){
@8CE @            vis[ax][ay] =1;
@F97 @            dist[ax][ay] = dist[x][y] + camim;
@EC5 @            pq.push({dist[ax][ay],{ax,ay}});
@57D @          }
@0E0 @        }
@B45 @      }
@12E @    }
@D74 @  }
@7F7 @}
