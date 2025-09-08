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
@AC1 @  string s,t;
@FEE @  cin >> s >>t;
@F3F @  vector<vi>dp(s.size() + 1,vi(t.size()+1,0));
@CA5 @  int max_sub = 0;
@BAC @  int pos_s;
@E42 @  for (int i = 1; i <=s.size();i++ ){
@F69 @    dp[i][0] = 0;
@631 @    for (int j = 1; j <= t.size();j++){
@CC3 @      if(t[j-1] == s[i-1]){
@0F6 @        dp[i][j] = 1 + dp[i-1][j-1] ;
@DF7 @      }else{
@398 @        dp[i][j] = max (dp[i-1][j], dp[i][j-1]);
@A96 @      }
@    @
@3E9 @    }
@93F @  }
@34C @  int aux = 0;
@E29 @  int v = 0;
@163 @  int n = s.size();
@FA8 @  int m = t.size();
@0BD @  string ans;
@E55 @  while(n > 0 && m > 0){
@060 @    if (dp[n][m] == dp[n][m-1]){
@76B @      m--;
@BF4 @    }else if(dp[n][m] == dp[n-1][m]){
@15A @      n--;
@074 @    }else{
@15A @      n--;
@4F1 @      ans = ans + s[n];
@76B @      m--;
@7E6 @    }
@F21 @  }
@    @
@459 @  reverse(ans.begin(),ans.end());
@    @
@F21 @  cout << ans;
@    @
@    @
@BB3 @  return 0;
@05A @}
