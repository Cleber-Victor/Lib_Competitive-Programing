#include<bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

typedef long long ll;

const int N = 2e5+7;
int original[N];
ll seg[4*N];

const int inf = 2147483647;


bool can (vi needed, vi have, int k, ll cookies){ // linear; determinar se é possível com esse numero de fatias n = estudantes k = pizzas
    
  bool flag = 1;
  int aux = 0;

  int n = needed.size();

  for (int i = 0 ; i < n ; i++){
    int s =  have[i]- needed[i] * cookies;
    if (s < 0) aux += s;
  }
  if(k < -aux){
    flag = 0;
  }
  
  return flag;
    
}


int main(){
  ios::sync_with_stdio(NULL);
  cin.tie(0);
  int n,k;
  cin >> n >> k;

  vi needed(n);
  vi have(n);

  for (int i = 0; i < n; i++){
    cin >> needed[i];
  }

  for (int i = 0; i < n; i++){
    cin >> have[i];
  }

  int r = 3000; // limite alto  nessa questrão eu quero saber o máximo que eu consigo, observar o que ele pede
  int l = 0; // buscando o menornumero de segundos possiveis
 
  ll ans= 0;
  while (l <= r){
    ll m = (l + r) / 2;

    if (can(needed,have,k,m)){
      l = m +1;
      ans = m; 
    }else{
      r = m-1;  
    }

  }

  cout << ans;
    
  return 0;
}