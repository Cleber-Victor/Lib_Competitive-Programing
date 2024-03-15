#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

#define ms 10001

void bfs(vector<vi>&graph,vector<int>indegree,int n,vector<int>&topo){
  priority_queue<int, vector<int>,greater<int>>PQ;

  for (int i = 1; i <= n; i++){
    if(indegree[i] == 0){
      PQ.push(i);
    }
  }

  while(!PQ.empty()){
    int u = PQ.top();
    PQ.pop();
    topo.push_back(u);
    for (int v : graph[u]){
      if(--indegree[v] == 0){
        PQ.push(v);
      }
    }
  }
}



int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n,m;
  vector<vi>graph(ms);
  vector<int>topo;
  cin >> n >> m;
  vector <int> indegree (n+1,0);
  for(int i = 0; i < m ; i++){
    int a,b;
    cin >> a >>b;
    indegree[b]++;
    graph[a].push_back(b);
  }

  bfs(graph,indegree,n,topo);

  if(topo.size() != n){
    cout <<"Sandro fails.";
  }else{
    for (int i = 0; i < n; i++){
      cout << topo[i] << " ";
    }
  }

  return 0;
}