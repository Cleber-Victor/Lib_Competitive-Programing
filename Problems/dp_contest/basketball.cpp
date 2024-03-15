#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

typedef long long ll;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<vll>dp(3,vll(n+1,0));
  vll t1(n+1);
  vll t2(n+1);
  for(int i = 1; i <= n; i++){
    cin >>t1[i];
  }

  for(int i = 1; i <= n; i++){
    cin >>t2[i];   
  }

  for(int i = 1; i <= n; i++){

    if(i > 1){
      dp[1][i] =  max(dp[2][i-1] + t1[i], dp[2][i-2] + t1[i]);
      dp[2][i] = max(dp[1][i-1] + t2[i], dp[1][i-2] + t2[i]);
    }else{
      dp[1][i] = dp[2][i-1] + t1[i];
      dp[2][i] = dp[1][i-1] + t2[i];
    }   
  }
  ll ans = max({dp[1][n],dp[2][n],dp[1][n-1],dp[2][n-1] });

  cout << ans;


  return 0;
}

