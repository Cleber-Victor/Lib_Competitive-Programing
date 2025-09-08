@F79 @#define pll pair<long long, long long>
@0C1 @#define vi vector<int>
@358 @#define vll vector<long long>
@531 @const int ms = 10e5 + 1;
@0E4 @vector <vi>graph(ms);
@0D3 @vector <bool> vis(ms,0);
@712 @bool auxi = 0; // 0 - 1    1 - 2
@578 @bool pssibe = 1;
@4DB @void dfs(int raiz, vector<int>&team,bool aux ){
@2B9 @  vis[raiz] = 1;
@A0D @  if (!aux){
@1A9 @    team[raiz] = 1;
@417 @  }else{
@1A4 @    team[raiz] = 2;
@6CF @  }
@5E1 @  for (int v : graph[raiz]){
@D90 @    if(!vis[v]){
@818 @      dfs(v,team,!aux);
@028 @    }else if (team[v] == team[raiz]){
@3E9 @      pssibe = 0;
@801 @    }
@D04 @  }
@    @
@F42 @}
@    @
@E8D @int main(){
@52E @  ios::sync_with_stdio(0);
@C97 @  cin.tie(NULL);
@B5C @  int m,n;
@712 @  bool auxi = 0;
@2DE @  cin >> m >> n;
@603 @  for (int i = 0; i < n ; i++){
@BA2 @    int a,b;
@0A8 @    cin >> a >>b;
@8FA @    graph[a].push_back(b);
@4C6 @    graph[b].push_back(a);
@9A3 @  }
@71E @  vector<int>team(m+1,0);
@F61 @  for(int i = 1 ; i< m;i++){
@A2B @    if (vis[i] == 0){
@7DC @      dfs(i,team,auxi);
@F7B @    }
@813 @  }
@    @
@17A @  if(!pssibe ){
@1A3 @    cout << "IMPOSSIBLE";
@F09 @  }else{
@8EA @    for (int i = 1; i <= m; i++)
@F95 @    {
@268 @      cout << team[i] << " ";
@E58 @    }
@    @
@B46 @  }
@BB3 @  return 0;
@44E @}
