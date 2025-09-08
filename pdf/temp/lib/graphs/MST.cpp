@2B7 @#include<bits/stdc++.h>
@    @
@F79 @#define pll pair<long long, long long>
@0C1 @#define vi vector<int>
@358 @#define vll vector<long long>
@    @
@AD1 @typedef long long ll;
@    @
@    @
@4C9 @vi liga;
@607 @vi tam;
@    @
@57B @int find(int x){
@924 @  if(x == liga[x]){
@EA5 @    return x;
@2EF @  }
@AB5 @  return liga[x] = find(liga[x]);
@D68 @}
@    @
@    @
@3D2 @bool same(int a,int b){
@C0A @    return find(a) == find(b);
@B5D @}
@    @
@440 @void unite(int a, int b){
@BCA @    a = find(a);
@B88 @    b = find(b);
@226 @    if (tam[a] < tam[b]) swap(a,b);
@AD6 @    tam[a]+= tam[b];
@10D @    liga[b]=a;
@F33 @}
@    @
@    @
@    @
@    @
@E8D @int main(){
@96E @    ios::sync_with_stdio(NULL);
@B95 @    cin.tie(0);
@221 @    int t; cin >> t;
@    @
@EE2 @    while(t--){
@8AD @        int p,n,m;cin >> p >> n >> m;
@53A @        int peso = 0;
@FB0 @        liga.resize(n+1);
@DE6 @        tam.resize(n+1);
@78A @        for (int i = 1; i <= n; i++){
@CD6 @            liga[i] = i;
@8A8 @            tam[i] = 1;
@EFB @        }
@508 @        vector<pair<int,pii>>arestas;
@DD5 @        for(int i = 0; i < m; i++){
@684 @            int a,b,w;
@060 @            cin >> a >> b >>w;
@C65 @            arestas.push_back(make_pair(w,make_pair(a,b)));
@7DE @        }
@DA0 @        sort(arestas.begin(),arestas.end());
@    @
@DD5 @        for(int i = 0; i < m; i++){
@6DE @            if(!same(arestas[i].second.first,arestas[i].second.second)){
@854 @                unite(arestas[i].second.first,arestas[i].second.second);
@E0E @                peso+= arestas[i].first;
@3B9 @            }
@78B @        }
@74C @        cout << p * peso << '\n';
@    @
@696 @    }
@    @
@    @
@BB3 @    return 0;
@C35 @}
