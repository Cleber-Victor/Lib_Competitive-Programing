#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
const int ms = 10e5 + 1;
vector <vi>graph(ms);
vector <int> vis(ms,0);
vector <int> dist(ms,0);
bool auxi = 0; // 0 - 1    1 - 2
bool pssibe = 1;
int diam = 0;
void dfs(int raiz, vector<int>&dist){
  vis[raiz] = 1;
  for(auto v : graph[raiz]){
    if(!vis[v]){
      dist[v] = dist[raiz] + 1;
      dfs(v,dist);
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  bool auxi = 0;
  cin >> n;
  if(n == 1){
    cout << 0;
    return 0;
  }
  for (int i = 2; i <= n ; i++){
    int a,b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  dfs(1,dist);
  int maximo = 0;
  int idx = -1;

  for(int i = 1; i <=n; i++){
    if(dist[i] > maximo) idx = i;
    maximo = max(maximo,dist[i]); 
  }
  vis.resize(n+1,0);
  dist.resize(n+1,0);
  vi dist_aux(n+1,0);
  vi vis_aux (n+1,0);
  vis = vis_aux;
  dfs(idx,dist_aux);
  for(int i = 1; i <=n; i++){
    if(dist_aux[i] > maximo) idx = i;
    maximo = max(maximo,dist_aux[i]); 
  }

  cout << maximo;

 
  return 0;
}