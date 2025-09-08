#include<bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

typedef long long ll;

const int N = 2e5+7;
const int LIM = 1e4 + 10;

vector<ll> seg(4*N,0);
vector<ll> lazy(4*N,0); // o valor inicial da lazy varia tambem de acordo com o problema, 
vll ar;
vi maxp(LIM,-1);
vi sump(LIM,0);
vll original(N,0);
ll n;

void build(int l=1, int r = n, int no =1){
  if (l == r){
    seg[no] = original[l];
    return;
  }
  ll m = (l + r) / 2;
  ll left = no * 2 ;
  ll right = no * 2 + 1 ;
  build (l, m, left);
  build (m +1,r, right);
  
  seg[no] = seg[left] + seg[right];  
}

void update_lazy(int no, int l, int r, ll v){
  lazy[no] += v;  // essa atualização varia de acordo com o problema
  seg[no] += ((r-l +1) * v);
}

void propagate(int no, int l, int r) {
  if (lazy[no]  == 0) return;

  if(l!=r){
    int m = (l + r) / 2;
    update_lazy(2 * no, l, m, lazy[no]);
    update_lazy(2 * no + 1, m + 1, r, lazy[no]);
  }

  lazy[no] = 0;
}

void update( int ul, int ur, ll v, int no =1, int l=1, int r=n){

  if (r < ul || l > ur) return;
  if (ul <= l && r <= ur) {
    update_lazy(no, l, r, v);
    return;
  }

  propagate(no, l, r);

  int m = (l + r) / 2;
  update( ul, ur, v,2 * no, l, m);
  update( ul, ur, v, 2 * no + 1, m + 1, r);

  seg[no] = seg[2 * no] + seg[2 * no + 1];  
}



ll query(int L, int R,int l = 1, int r = n, int no = 1){

  propagate(no,l,r);
  if(R < l || L > r) return 0;
  if(L <= l && r <=R){
    return seg[no];
  }
  int m = (l+r)/2;
  int left = 2*no;
	int right = 2*no+1;
  ll saida  =query(L,R,l,m,left) + query(L,R,m+1,r,right);
  return saida;
}


int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int q;
  cin >>n>>q;
  for(int i = 1; i<= n;i++){
    cin>>original[i];
  }
  build();

  for(int i = 0; i < q;i++){
    int ti; cin>>ti;
    if(ti == 1){
      ll a,b,x; cin >>a>>b>>x;
      update(a,b,x);
    }else{
      int k; cin >>k;
      cout <<query(k,k)<<'\n';
    }
  }




  return 0;
}
