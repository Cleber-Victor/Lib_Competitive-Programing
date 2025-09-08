#include<bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

typedef long long ll;


vi liga;
vi tam;

int find(int x){
  if(x == liga[x]){
    return x;
  }
  return liga[x] = find(liga[x]);
}


bool same(int a,int b){
    return find(a) == find(b);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if (tam[a] < tam[b]) swap(a,b);
    tam[a]+= tam[b];
    liga[b]=a;
}




int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    int t; cin >> t;

    while(t--){
        int p,n,m;cin >> p >> n >> m;
        int peso = 0;
        liga.resize(n+1);
        tam.resize(n+1);
        for (int i = 1; i <= n; i++){
            liga[i] = i;
            tam[i] = 1;
        }
        vector<pair<int,pii>>arestas;
        for(int i = 0; i < m; i++){
            int a,b,w;
            cin >> a >> b >>w;
            arestas.push_back(make_pair(w,make_pair(a,b)));
        }
        sort(arestas.begin(),arestas.end());
        
        for(int i = 0; i < m; i++){
            if(!same(arestas[i].second.first,arestas[i].second.second)){
                unite(arestas[i].second.first,arestas[i].second.second);
                peso+= arestas[i].first;
            }
        }
        cout << p * peso << '\n';
        
    }
 
 
    return 0;
}
