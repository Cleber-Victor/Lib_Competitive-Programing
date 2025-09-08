#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

typedef long long ll;

const int MAXN = 1000001;
//int dp[MAXN][MAXN];
const int MODULO = 1e9 + 7;

vll coins;
ll dp[MAXN];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  ll n, x;
  cin >> n >> x;
  memset(dp,0, sizeof dp);
  coins.resize(n);
  for (int i = 0; i < n; i++){
    cin >> coins[i];
  }
  dp[0] = 1;

for (int i = 1; i <= x; i++){
  for(auto c: coins){
    if (i >= c){
      dp[i] = dp[i] + dp[i-c];
      dp[i] = dp[i] % MODULO;
    }
  }
}
  cout << dp[x];
  return 0;
}

