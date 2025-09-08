@F79 @#define pll pair<long long, long long>
@0C1 @#define vi vector<int>
@358 @#define vll vector<long long>
@    @
@AD1 @typedef long long ll;
@    @
@F53 @const int MAXN = 1000001;
@D41 @//int dp[MAXN][MAXN];
@2C3 @const int MODULO = 1e9 + 7;
@    @
@C08 @vll coins;
@1A6 @ll dp[MAXN];
@    @
@E8D @int main(){
@52E @  ios::sync_with_stdio(0);
@C97 @  cin.tie(NULL);
@CBB @  ll n, x;
@B8A @  cin >> n >> x;
@F0D @  memset(dp,0, sizeof dp);
@619 @  coins.resize(n);
@603 @  for (int i = 0; i < n; i++){
@283 @    cin >> coins[i];
@84D @  }
@0EC @  dp[0] = 1;
@    @
@218 @for (int i = 1; i <= x; i++){
@6B9 @  for(auto c: coins){
@D4C @    if (i >= c){
@C70 @      dp[i] = dp[i] + dp[i-c];
@01B @      dp[i] = dp[i] % MODULO;
@B63 @    }
@5DD @  }
@D6C @}
@1D5 @  cout << dp[x];
@BB3 @  return 0;
@681 @}
