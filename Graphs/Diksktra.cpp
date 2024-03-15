#include <bits/stdc++.h>

using namespace std;
const ll MAXN = 1e5+5;
const ll INF = LLONG_MAX;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

vector<ll> dist(MXN,INF);

vector<pii> graph[MAXN];

void dikstra(int x,int n,vector<bool>vis){

    dist[x] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,x}); //uma especia de bfs só que com pq
    while(!pq.empty()){
        int a = pq.top().second;
        int b = pq.top().first; 
        pq.pop();
        if(b >dist[out] ) continue;
        for([cost, nb] : graph[a]){
            ll currD = dist[out] + cost;
            if(currD < dist[nb]){
              dist[nb] = currD;
              parent[nb] = out;
              pq.push({currD,nb})
            }
        }
    }
}
