#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
const int ms = 10e5 + 1;
vector <vi>graph(ms);
vector <bool> vis(ms,0);
vector <int> emp(ms,0);
bool auxi = 0; // 0 - 1    1 - 2
bool pssibe = 1;

int dfs(int raiz, vector<int>&emp){
  vis[raiz] = 1;
  for(auto v : graph[raiz]){
    if(!vis[v]){
      emp[raiz] += (dfs(v, emp) + 1);
    }
  }

  return emp[raiz];
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  bool auxi = 0;
  cin >> n;
  for (int i = 2; i <= n ; i++){
    int a;
    cin >> a;
    graph[a].push_back(i);
  }

  dfs(1,emp);
  for(int i =1; i <=n; i++){
    cout <<emp[i] << " ";
  }
 
  return 0;
}