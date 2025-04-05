#include<bits/stdc++.h>
 
using namespace std;
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
 
typedef long long ll;

const ll MOD = 1e9 +7;



int main(){
  ios::sync_with_stdio(0);
	cin.tie(0);
  string s; cin >>s;
  vi prf(s.size()+1,0);
  for(int i =0; i <s.size();i++){
    if(i==s.size()-1){
      prf[i+1] = prf[i];
    }else if (s[i+1] ==s[i]){
      prf[i+1]= prf[i]+1;
    }else{
      prf[i+1]=prf[i];
    }
  }
  int q; cin >>q;
  for(int i =0; i <q;i++){
    int l,r; cin >>l>>r;
    l--;
    r--;
    int ans = prf[r]-prf[l];
    cout <<ans<<'\n';
  }
	return 0;
}
