@F79 @#define pll pair<long long, long long>
@0C1 @#define vi vector<int>
@358 @#define vll vector<long long>
@    @
@AD1 @typedef long long ll;
@    @
@D41 @//const int MAXN = 3001;
@D41 @//int dp[MAXN][MAXN];
@    @
@E8D @int main(){
@52E @  ios::sync_with_stdio(0);
@C97 @  cin.tie(NULL);
@949 @  int n, w;
@DE5 @  cin >> n >> w;
@    @
@6B8 @  vector<pii> entrada;
@603 @  for(int i = 0 ; i < n; i++){
@BA2 @    int a,b;
@0A8 @    cin >> a >> b;
@EB8 @    entrada.push_back(make_pair(a,b));
@6E6 @  }
@    @
@    @
@926 @  vector<vll>dp(n + 1,vll(w+1,0));
@    @
@603 @  for(int i = 0 ; i < n; i++){
@    @
@B55 @    int peso = entrada[i].first;
@6EC @    int valor = entrada[i].second;
@940 @    if(i > 0){
@D0F @    for (int x = 0; x < w; x++){
@864 @        dp[i+1][x+1] = dp[i][x+1];
@9E3 @    }
@3CE @    }
@    @
@7B7 @    for(int j = 0; j < w ; j++){
@7B6 @      if(j+1>= peso){
@599 @        dp[i+1][j+1] = max(dp[i][j+1], dp[i][j-peso +1]+ valor );
@AD8 @      }
@    @
@    @
@C78 @    }
@    @
@89F @  }
@    @
@CB3 @  cout << dp[n][w];
@    @
@    @
@    @
@BB3 @  return 0;
@4DB @}
