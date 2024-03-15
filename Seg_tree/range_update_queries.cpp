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
ll lazy[4*N];
bool has[4*N];

void propagate (ll no, ll i, ll j){
  if (has[no]){
    seg[no] += lazy[no] * (j - i + 1);
    if(i != j){
      has[2*no] = 1;
      has[2*no +1] = 1;
      lazy[2*no] += lazy[no];
      lazy[2*no +1] += lazy[no];      
    }
    has[no] = 0;
    lazy[no] = 0;
  }
}


void build (ll l,  ll r,  ll idx){
  if (l == r){
    seg[idx] = original[l];
    return;
  }
  ll m = (l + r) / 2;
  ll left = idx * 2 ;
  ll right = idx * 2 + 1 ;
  build (l, m, left);
  build (m +1,r, right);
  
  seg[idx] = seg[left] + seg[right];
}

long long query(ll ql,ll qr,ll l, ll r, ll idx){

  propagate(idx,l,r);
  if (ql > r || qr < l) return 0;

  if (ql <= l && qr >= r){ // o l,r tem que estar obrigatoriamente dentro do range da query para poder contribuir, se tiver duvida irei desehar o que contribui

    return seg[idx];
  }

  ll m = (l + r) / 2;
  ll left = idx * 2 ;
  ll right = idx * 2 + 1 ;

  return query(ql,qr,l,m,left) + query(ql,qr,m+1,r,right);

}

void update (ll idx, ll tl, ll tr,ll ul,ll ur, ll val){

  if (ul > tr || ur < tl) return;

  if (ul <= tl && ur >= tr){
    has[idx] = 1;
    lazy[idx] += val;
    propagate(idx,tl,tr);
     // o l,r tem que estar obrigatoriamente dentro do range da query para poder contribuir, se tiver duvida irei desehar o que contribui
    return;
  }

  ll m = (tl + tr) / 2;
  ll left = idx * 2 ;
  ll right = idx * 2 + 1;

  update(left,tl, m,ul, ur, val);
  update(right,m+1, tr,ul, ur, val);
  
  seg[idx] = seg[left] + seg[right];
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  long long n,q; cin >> n >> q;
  for(long long i = 1; i <= n; i++){
    cin >> original[i];  
  }

  build(1,n,1);

  for(long long i = 1; i <= q; i++){
    long long x,a,b,u,k;
    cin >> x;
    if (x == 1){
      cin >> a >> b >>u;
      update(1,1,n,a,b,u);
    }else{
      cin >> k;
      long long aux = query(k,k, 1,n, 1);
      cout << query(k,k, 1,n, 1) << '\n';
    }
  }
  return 0;
}