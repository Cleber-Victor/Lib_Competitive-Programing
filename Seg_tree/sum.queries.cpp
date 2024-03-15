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


void build (int l,  int r,  int idx){
  if (l == r){
    seg[idx] = original[l];
    return;
  }
  int m = (l + r) / 2;
  int left = idx * 2 ;
  int right = idx * 2 + 1 ;
  build (l, m, left);
  build (m +1,r, right);
  
  seg[idx] = seg[left] + seg[right];
}

long long query(int ql,int qr,int l, int r, int idx){
  if (ql > r || qr < l) return 0;

  if (ql <= l && qr >= r){ // o l,r tem que estar obrigatoriamente dentro do range da query para poder contribuir, se tiver duvida irei desehar o que contribui
    return seg[idx];
  }

  int m = (l + r) / 2;
  int left = idx * 2 ;
  int right = idx * 2 + 1 ;

  return query(ql,qr,l,m,left) + query(ql,qr,m+1,r,right);

}

void update (int l, int r, int idx, int pos, long long val){

  if (l == r){
    seg[idx] = val;
    return;
  }

  int m = (l + r) / 2;
  int left = idx * 2 ;
  int right = idx * 2 + 1;

  if (pos <= m){
    update(l,m,left,pos,val);
  }else{
    update(m+1,r,right,pos,val);
  }

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
    long long x,a,b;
    cin >> x >> a >>b;
    if (x == 1){
      update(1,n,1,a,b);
    }else{
      cout << query(a,b, 1,n, 1) << '\n';
    }
  }
  return 0;
}