#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

typedef long long ll;

vector<int> z(string &s){
  int n= s.size();
  vector<int>zf(n,0);
  int r = 0;
  int l = 0;
  for(int i = 1; i < n; i++){
    if(i <= r){
      zf[i] = min(zf[i-l], r - i + 1);
    }

    while(s[zf[i]] == s[i + zf[i]] && i + zf[i] < n){
      zf[i]++;
    }
    
    if (i + zf[i] -1 > r){ // o intervalo q eu olhei passou de r, eu atualizo o r pois ele maraca ate quando olhei
      r = i + zf[i] -1;
      l = i;
    } 
  }
  return zf;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  string n,m;
  cin >> n >> m;
  string nova = m + '$';
  nova += n;
  vi ans = z(nova);
  int resp = 0;
  for(int i = 0; i < ans.size();i++){
    if (ans[i] == m.size()){
      resp++;
    }
  }
  cout << resp;


  return 0;
}

