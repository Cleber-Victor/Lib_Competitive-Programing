#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

typedef long long ll;

//const int MAXN = 3001;
//int dp[MAXN][MAXN];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  string s,t;
  cin >> s >>t;
  vector<vi>dp(s.size() + 1,vi(t.size()+1,0));
  int max_sub = 0;
  int pos_s;
  for (int i = 1; i <=s.size();i++ ){
    dp[i][0] = 0;
    for (int j = 1; j <= t.size();j++){
      if(t[j-1] == s[i-1]){
        dp[i][j] = 1 + dp[i-1][j-1] ;
      }else{
        dp[i][j] = max (dp[i-1][j], dp[i][j-1]);
      }

    }
  }
  int aux = 0;
  int v = 0;
  int n = s.size();
  int m = t.size();
  string ans;
  while(n > 0 && m > 0){
    if (dp[n][m] == dp[n][m-1]){
      m--;
    }else if(dp[n][m] == dp[n-1][m]){
      n--;
    }else{
      n--;
      ans = ans + s[n];
      m--;
    }
  }

  reverse(ans.begin(),ans.end());

  cout << ans;


  return 0;
}

