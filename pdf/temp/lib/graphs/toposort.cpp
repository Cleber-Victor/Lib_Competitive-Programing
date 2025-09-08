@F79 @#define pll pair<long long, long long>
@0C1 @#define vi vector<int>
@358 @#define vll vector<long long>
@    @
@468 @#define ms 10001
@    @
@0C5 @void bfs(vector<vi>&graph,vector<int>indegree,int n,vector<int>&topo){
@451 @  priority_queue<int, vector<int>,greater<int>>PQ;
@    @
@78A @  for (int i = 1; i <= n; i++){
@D9F @    if(indegree[i] == 0){
@704 @      PQ.push(i);
@784 @    }
@14F @  }
@    @
@849 @  while(!PQ.empty()){
@16E @    int u = PQ.top();
@41B @    PQ.pop();
@AB4 @    topo.push_back(u);
@577 @    for (int v : graph[u]){
@35C @      if(--indegree[v] == 0){
@27C @        PQ.push(v);
@01A @      }
@EA7 @    }
@2B1 @  }
@5C4 @}
@    @
@    @
@    @
@E8D @int main(){
@52E @  ios::sync_with_stdio(0);
@C97 @  cin.tie(NULL);
@14E @  int n,m;
@0E4 @  vector<vi>graph(ms);
@E32 @  vector<int>topo;
@AA3 @  cin >> n >> m;
@7EC @  vector <int> indegree (n+1,0);
@DD5 @  for(int i = 0; i < m ; i++){
@BA2 @    int a,b;
@0A8 @    cin >> a >>b;
@163 @    indegree[b]++;
@8FA @    graph[a].push_back(b);
@397 @  }
@    @
@8AE @  bfs(graph,indegree,n,topo);
@    @
@677 @  if(topo.size() != n){
@8D7 @    cout <<"Sandro fails.";
@A8F @  }else{
@603 @    for (int i = 0; i < n; i++){
@3D6 @      cout << topo[i] << " ";
@DD0 @    }
@E5B @  }
@    @
@BB3 @  return 0;
@B7A @}
