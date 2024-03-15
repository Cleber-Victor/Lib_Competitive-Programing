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
  int n, w;
  cin >> n >> w;

  vector<pii> entrada;
  for(int i = 0 ; i < n; i++){
    int a,b;
    cin >> a >> b;
    entrada.push_back(make_pair(a,b));
  }


  vector<vll>dp(n + 1,vll(w+1,0));
  
  for(int i = 0 ; i < n; i++){
    
    int peso = entrada[i].first;
    int valor = entrada[i].second;
    if(i > 0){
    for (int x = 0; x < w; x++){
        dp[i+1][x+1] = dp[i][x+1];
    }
    }

    for(int j = 0; j < w ; j++){
      if(j+1>= peso){
        dp[i+1][j+1] = max(dp[i][j+1], dp[i][j-peso +1]+ valor );
      }


    }

  }

  cout << dp[n][w];



  return 0;
}

