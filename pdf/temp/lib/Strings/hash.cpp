@F79 @#define pll pair<long long, long long>
@0C1 @#define vi vector<int>
@358 @#define vll vector<long long>
@    @
@AD1 @typedef long long ll;
@    @
@E8E @const ll MOD1 = 131'807'699;
@0B3 @const ll MOD2 =127'065'427;
@0C8 @const ll base = 127; //127
@80E @const int MAXN = 1e5 + 5; // tamanho da string
@D41 @/*
@097 @Some Big Prime Numbers:
@E47 @37'139'213
@99A @127'065'427
@56A @131'807'699
@C4C @*/
@    @
@651 @ll expBase1[MAXN];
@1B2 @ll expBase2[MAXN];
@    @
@FE8 @void precalc(){
@243 @  expBase1[0]=expBase2[0]=1;
@B74 @  for(int i=1;i<MAXN;i++){
@F7C @    expBase1[i] = (expBase1[i-1]*base)%MOD1;
@26F @    expBase2[i] = (expBase2[i-1]*base)%MOD2;
@FF9 @  }
@BF5 @}
@    @
@332 @struct PolyHash{
@0DD @  vector<pair<ll,ll>> hsh;
@    @
@C90 @  PolyHash(string& s){
@20A @    hsh = vector<pair<ll,ll>> (s.size()+1,{0LL,0LL});
@1CF @    for(int i=0;i<s.size();i++){
@1AB @      hsh[i+1].first = ( (hsh[i].first *base) % MOD1 + s[i] ) % MOD1;
@9DD @      hsh[i+1].second =( (hsh[i].second*base) % MOD2 + s[i] ) % MOD2;
@213 @    }
@A7A @  }
@    @
@2F0 @  ll gethash(int a, int b){
@4FC @    ll h1 = (MOD1 + hsh[b+1].first  - ( hsh[a].first *expBase1[b-a+1] ) % MOD1) % MOD1;
@695 @    ll h2 = (MOD2 + hsh[b+1].second - ( hsh[a].second*expBase2[b-a+1] ) % MOD2) % MOD2;
@A46 @    return (h1<<32LL) | h2;
@842 @  }
@ADD @};
