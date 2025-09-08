@2B7 @#include<bits/stdc++.h>
@    @
@F79 @#define pll pair<long long, long long>
@0C1 @#define vi vector<int>
@358 @#define vll vector<long long>
@    @
@AD1 @typedef long long ll;
@    @
@359 @const int N = 2e5+7;
@81E @const int LIM = 1e4 + 10;
@    @
@5B7 @vector<ll> seg(4*N,0);
@532 @vector<ll> lazy(4*N,0); // o valor inicial da lazy varia tambem de acordo com o problema,
@6F7 @vll ar;
@21C @vi maxp(LIM,-1);
@A31 @vi sump(LIM,0);
@4C3 @vll original(N,0);
@4DE @ll n;
@    @
@A35 @void build(int l=1, int r = n, int no =1){
@893 @  if (l == r){
@446 @    seg[no] = original[l];
@505 @    return;
@43A @  }
@3E3 @  ll m = (l + r) / 2;
@CBD @  ll left = no * 2 ;
@E81 @  ll right = no * 2 + 1 ;
@84F @  build (l, m, left);
@C3B @  build (m +1,r, right);
@    @
@80C @  seg[no] = seg[left] + seg[right];
@041 @}
@    @
@072 @void update_lazy(int no, int l, int r, ll v){
@8D9 @  lazy[no] += v;  // essa atualizacao varia de acordo com o problema
@5E1 @  seg[no] += ((r-l +1) * v);
@C87 @}
@    @
@3B4 @void propagate(int no, int l, int r) {
@54D @  if (lazy[no]  == 0) return;
@    @
@579 @  if(l!=r){
@EE4 @    int m = (l + r) / 2;
@65B @    update_lazy(2 * no, l, m, lazy[no]);
@8D5 @    update_lazy(2 * no + 1, m + 1, r, lazy[no]);
@AFE @  }
@    @
@099 @  lazy[no] = 0;
@626 @}
@    @
@B5B @void update( int ul, int ur, ll v, int no =1, int l=1, int r=n){
@    @
@90C @  if (r < ul || l > ur) return;
@619 @  if (ul <= l && r <= ur) {
@E30 @    update_lazy(no, l, r, v);
@505 @    return;
@DCD @  }
@    @
@483 @  propagate(no, l, r);
@    @
@EE4 @  int m = (l + r) / 2;
@C91 @  update( ul, ur, v,2 * no, l, m);
@3C9 @  update( ul, ur, v, 2 * no + 1, m + 1, r);
@    @
@027 @  seg[no] = seg[2 * no] + seg[2 * no + 1];
@D23 @}
@    @
@    @
@    @
@A6C @ll query(int L, int R,int l = 1, int r = n, int no = 1){
@    @
@483 @  propagate(no,l,r);
@1BA @  if(R < l || L > r) return 0;
@761 @  if(L <= l && r <=R){
@B4F @    return seg[no];
@CA6 @  }
@EE4 @  int m = (l+r)/2;
@1F2 @  int left = 2*no;
@176 @	int right = 2*no+1;
@15D @  ll saida  =query(L,R,l,m,left) + query(L,R,m+1,r,right);
@B89 @  return saida;
@69B @}
@    @
@    @
@E8D @int main(){
@52E @  ios::sync_with_stdio(0);
@C97 @  cin.tie(NULL);
@3AA @  cout.tie(NULL);
@45F @  int q;
@55A @  cin >>n>>q;
@78A @  for(int i = 1; i<= n;i++){
@EA4 @    cin>>original[i];
@85F @  }
@6F2 @  build();
@    @
@ABF @  for(int i = 0; i < q;i++){
@E19 @    int ti; cin>>ti;
@42D @    if(ti == 1){
@42C @      ll a,b,x; cin >>a>>b>>x;
@BD3 @      update(a,b,x);
@095 @    }else{
@3FE @      int k; cin >>k;
@A51 @      cout <<query(k,k)<<'\n';
@8FA @    }
@C94 @  }
@    @
@    @
@    @
@    @
@BB3 @  return 0;
@65C @}
