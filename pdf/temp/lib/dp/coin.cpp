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
@CBB @  ll n, x;
@B8A @  cin >> n >> x;
@C08 @  vll coins;
@    @
@603 @  for (int i = 0; i < n; i++){
@40A @    ll a; cin >> a;
@541 @    coins.push_back(a);
@6A3 @  }
@    @
@7E0 @  vll dp (x+1,1e9);
@076 @  dp[0] = 0;
@6B9 @  for (auto c : coins){
@D55 @    for (int i = c; i <= x; i++){
@314 @      dp[i] = min (dp[i],dp[i-c] +1 );
@BEC @    }
@51A @  }
@15E @  if (dp[x]==1e9 ){
@866 @    cout << -1;
@ECB @  }else{
@1D5 @    cout << dp[x];
@FAD @  }
@    @
@    @
@BB3 @  return 0;
@C9B @}
