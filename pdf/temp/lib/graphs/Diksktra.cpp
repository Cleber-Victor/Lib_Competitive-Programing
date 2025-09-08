@CF0 @const ll MAXN = 1e5+5;
@B6E @const ll INF = LLONG_MAX;
@    @
@F79 @#define pll pair<long long, long long>
@0C1 @#define vi vector<int>
@358 @#define vll vector<long long>
@    @
@EB6 @vector<ll> dist(MXN,INF);
@    @
@9BC @vector<pii> graph[MAXN];
@    @
@C6B @void dikstra(int x,int n,vector<bool>vis){
@    @
@336 @    dist[x] = 0;
@F37 @    priority_queue<pii, vector<pii>, greater<pii>> pq;
@E63 @    pq.push({0,x}); //uma especia de bfs so que com pq
@502 @    while(!pq.empty()){
@A5B @        int a = pq.top().second;
@A3C @        int b = pq.top().first;
@716 @        pq.pop();
@9F6 @        if(b >dist[out] ) continue;
@721 @        for([cost, nb] : graph[a]){
@C1A @            ll currD = dist[out] + cost;
@BE5 @            if(currD < dist[nb]){
@2FF @              dist[nb] = currD;
@F64 @              parent[nb] = out;
@A33 @              pq.push({currD,nb})
@CD7 @            }
@0EA @        }
@2FA @    }
@E1C @}
