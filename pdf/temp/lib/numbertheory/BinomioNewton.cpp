@197 @long long MOD = 1e9 + 7;
@    @
@97E @vll fact(2e5 +1,0);
@E78 @vll ifact(2e5 +1,0);
@    @
@8D8 @ll fexpll(ll a, ll n){
@D54 @  ll ans = 1;
@02A @  while(n){
@94A @    if(n & 1) ans = (ans * a) % MOD;
@49B @    a = (a*a) % MOD;
@9D3 @    n >>= 1;
@ABB @  }
@BA7 @  return ans;
@5DC @}
@    @
@1E0 @ll mul(ll a, ll b){
@568 @  return (a*b)%MOD;
@142 @}
@    @
@FC9 @ll bc(int n, int k){ // N choose K
@ED2 @  if(n < k) return 0;
@024 @  return fact[n] *ifact[k] % MOD * ifact[n-k] %MOD;
@B9C @}
@    @
@342 @div = fexpll(div,MOD-2);  <- inverso modular div
@    @
@E8D @int main(){
@886 @  ios::sync_with_stdio(false);
@B95 @  cin.tie(0);
@0C0 @  fact[0] =1;
@2E1 @  fact[1] = 1;
@908 @  ifact[0] = fexpll(1,MOD-2);
@306 @  for(int i =1; i <= 200000;i++){
@DA2 @    fact[i] = (fact[i-1] * i) %MOD;
@DBB @    ifact[i] = fexpll(fact[i],MOD-2);
@2C0 @  }
@BB3 @  return 0;
@D19 @}
