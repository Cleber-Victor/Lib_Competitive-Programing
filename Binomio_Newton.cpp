
long long MOD = 1e9 + 7;

vll fact(2e5 +1,0);
vll ifact(2e5 +1,0);

ll fexpll(ll a, ll n){
  ll ans = 1;
  while(n){
    if(n & 1) ans = (ans * a) % MOD;
    a = (a*a) % MOD;
    n >>= 1;
  }
  return ans;
}

ll mul(ll a, ll b){
  return (a*b)%MOD;
}

ll bc(int n, int k){ // N choose K
  if(n < k) return 0;
  return fact[n] *ifact[k] % MOD * ifact[n-k] %MOD;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  fact[0] =1;
  fact[1] = 1;
  ifact[0] = fexpll(1,MOD-2);
  for(int i =1; i <= 200000;i++){
    fact[i] = (fact[i-1] * i) %MOD;
    ifact[i] = fexpll(fact[i],MOD-2);
  }
  return 0;
}
