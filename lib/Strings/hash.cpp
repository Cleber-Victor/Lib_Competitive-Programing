#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

typedef long long ll;

const ll MOD1 = 131'807'699;
const ll MOD2 =127'065'427;
const ll base = 127; //127
const int MAXN = 1e5 + 5; // tamanho da string
/*
Some Big Prime Numbers:
37'139'213
127'065'427
131'807'699
*/
 
ll expBase1[MAXN];
ll expBase2[MAXN];
 
void precalc(){
  expBase1[0]=expBase2[0]=1;
  for(int i=1;i<MAXN;i++){
    expBase1[i] = (expBase1[i-1]*base)%MOD1;
    expBase2[i] = (expBase2[i-1]*base)%MOD2;
  }
}
 
struct PolyHash{
  vector<pair<ll,ll>> hsh;
 
  PolyHash(string& s){
    hsh = vector<pair<ll,ll>> (s.size()+1,{0LL,0LL});
    for(int i=0;i<s.size();i++){
      hsh[i+1].first = ( (hsh[i].first *base) % MOD1 + s[i] ) % MOD1;
      hsh[i+1].second =( (hsh[i].second*base) % MOD2 + s[i] ) % MOD2;
    }
  }
 
  ll gethash(int a, int b){
    ll h1 = (MOD1 + hsh[b+1].first  - ( hsh[a].first *expBase1[b-a+1] ) % MOD1) % MOD1;
    ll h2 = (MOD2 + hsh[b+1].second - ( hsh[a].second*expBase2[b-a+1] ) % MOD2) % MOD2;
    return (h1<<32LL) | h2;
  }
};
 
