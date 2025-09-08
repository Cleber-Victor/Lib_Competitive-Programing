@2B7 @#include<bits/stdc++.h>
@    @
@F79 @#define pll pair<long long, long long>
@0C1 @#define vi vector<int>
@358 @#define vll vector<long long>
@    @
@AD1 @typedef long long ll;
@    @
@359 @const int N = 2e5+7;
@C8E @int original[N];
@0BB @ll seg[4*N];
@1A8 @int n;
@    @
@317 @void build (int l =1,  int r = n, int idx=1){
@893 @  if (l == r){
@A0E @    seg[idx] = original[l];
@505 @    return;
@98F @  }
@EE4 @  int m = (l + r) / 2;
@B77 @  int left = idx * 2 ;
@0E8 @  int right = idx * 2 + 1 ;
@84F @  build (l, m, left);
@C3B @  build (m +1,r, right);
@    @
@5B2 @  seg[idx] = seg[left] + seg[right];
@134 @}
@    @
@62A @long long query(int ql,int qr,int l = 1, int r = n, int idx=1){
@BDD @  if (ql > r || qr < l) return 0;
@    @
@E07 @  if (ql <= l && qr >= r){ // o l,r tem que estar obrigatoriamente dentro do range da query para poder contribuir, se tiver duvida irei desehar o que contribui
@A9D @    return seg[idx];
@A78 @  }
@    @
@EE4 @  int m = (l + r) / 2;
@B77 @  int left = idx * 2 ;
@0E8 @  int right = idx * 2 + 1 ;
@    @
@496 @  return query(ql,qr,l,m,left) + query(ql,qr,m+1,r,right);
@    @
@753 @}
@    @
@406 @void update (int pos, ll val, int l=1, int r=n, int idx=1){
@    @
@893 @  if (l == r){
@873 @    seg[idx] = val;
@505 @    return;
@741 @  }
@    @
@EE4 @  int m = (l + r) / 2;
@B77 @  int left = idx * 2 ;
@0E8 @  int right = idx * 2 + 1;
@    @
@E09 @  if (pos <= m){
@3A1 @    update(pos,val,l,m,left);
@896 @  }else{
@8AD @    update(pos,val,m+1,r,right);
@7B0 @  }
@    @
@5B2 @  seg[idx] = seg[left] + seg[right];
@B5E @}
@    @
@E8D @int main(){
@52E @  ios::sync_with_stdio(0);
@C97 @  cin.tie(NULL);
@    @
@834 @  int q; cin >> n >> q;
@    @
@78A @  for(int i = 1; i <= n; i++){
@EA4 @    cin >> original[i];
@85F @  }
@    @
@6F2 @  build();
@    @
@646 @  for(int i = 1; i <= q; i++){
@4C1 @    long long x,a,b;
@6AA @    cin >> x >> a >>b;
@C91 @    if (x == 1){
@E72 @      update(a,b);
@FD6 @    }else{
@E94 @      cout << query(a,b) << '\n';
@CEB @    }
@6CC @  }
@BB3 @  return 0;
@491 @}
