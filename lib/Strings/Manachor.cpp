#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

typedef long long ll;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  string a;
  cin >> a;
  int n = a.size();
  vi d1(n);
  vi d2(n);
  for(int i = 0, l = 0, r = -1; i < n; i++){
    int k;
    if (i > r){
      k = 1;
    }else{
      k = min (d1[l + r -i], r - i + 1);
    }
    while(0 <= i - k && i + k < n && a[i-k] == a[i + k]){
      k++;
    }
    d1[i] = k--;
    if(i + k > r){
      l = i - k;
      r = i + k;
    }
  }

  for(int i = 0, l = 0, r = -1; i < n; i++){
    int k;
    if (i > r){
      k = 0;
    }else{
      k = min (d2[l + r -i + 1], r - i + 1);
    }
    while(0 <= i - k -1 && i + k < n && a[i-k - 1] == a[i + k]){
      k++;
    }
    d2[i] = k--;
    if(i + k > r){
      l = i - k -1;
      r = i + k;
    }
  }
  int max_par = 0;
  int max_impar = 0;
  int max_indice_par;
  int max_indice_impar;
  for(int i = 0; i < d1.size();i++){
    if(d1[i] >max_impar ){
      max_indice_impar = i;
    }
    if(d2[i] >max_par ){
      max_indice_par = i;
    }
    max_impar = max (max_impar,d1[i]);
    max_par = max (max_par,d2[i]);
  }
  string ans;
  if(max_par >= max_impar){
    ans = a.substr(max_indice_par - max_par, max_par * 2);
  }else{
    ans = a.substr(max_indice_impar - (max_impar-1),max_impar * 2 -1 );
  }

  cout << ans;
 
  return 0;
}

