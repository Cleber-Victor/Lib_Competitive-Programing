#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
const int ms = 10e5 + 1;
vector <vi>graph(ms);
vector <bool> vis(ms,0);
bool auxi = 0; // 0 - 1    1 - 2
bool pssibe = 1;
void dfs(int raiz, vector<int>&team,bool aux ){
  vis[raiz] = 1;
  if (!aux){
    team[raiz] = 1;
  }else{
    team[raiz] = 2;
  }
  for (int v : graph[raiz]){
    if(!vis[v]){
      dfs(v,team,!aux);
    }else if (team[v] == team[raiz]){
      pssibe = 0;
    }
  }

}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int m,n;
  bool auxi = 0;
  cin >> m >> n;
  for (int i = 0; i < n ; i++){
    int a,b;
    cin >> a >>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  vector<int>team(m+1,0);
  for(int i = 1 ; i< m;i++){
    if (vis[i] == 0){
      dfs(i,team,auxi);
    }     
  }
  
  if(!pssibe ){
    cout << "IMPOSSIBLE"; 
  }else{
    for (int i = 1; i <= m; i++)
    {
      cout << team[i] << " ";
    }
    
  }
  return 0;
}