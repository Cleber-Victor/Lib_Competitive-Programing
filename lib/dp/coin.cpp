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
  ll n, x;
  cin >> n >> x;
  vll coins;

  for (int i = 0; i < n; i++){
    ll a; cin >> a;
    coins.push_back(a);
  }

  vll dp (x+1,1e9);
  dp[0] = 0;
  for (auto c : coins){
    for (int i = c; i <= x; i++){
      dp[i] = min (dp[i],dp[i-c] +1 );
    }
  }
  if (dp[x]==1e9 ){
    cout << -1;
  }else{
    cout << dp[x];
  }
  

  return 0;
}

