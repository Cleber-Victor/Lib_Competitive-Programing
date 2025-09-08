@F79 @#define pll pair<long long, long long>
@0C1 @#define vi vector<int>
@358 @#define vll vector<long long>
@    @
@AD1 @typedef long long ll;
@    @
@07E @vector<int> z(string &s){
@163 @  int n= s.size();
@BBF @  vector<int>zf(n,0);
@898 @  int r = 0;
@B8D @  int l = 0;
@6F5 @  for(int i = 1; i < n; i++){
@4F3 @    if(i <= r){
@DF4 @      zf[i] = min(zf[i-l], r - i + 1);
@A58 @    }
@    @
@118 @    while(s[zf[i]] == s[i + zf[i]] && i + zf[i] < n){
@547 @      zf[i]++;
@342 @    }
@    @
@EC5 @    if (i + zf[i] -1 > r){ // o intervalo q eu olhei passou de r, eu atualizo o r pois ele maraca ate quando olhei
@A89 @      r = i + zf[i] -1;
@537 @      l = i;
@D41 @    }
@424 @  }
@A6D @  return zf;
@124 @}
@    @
@E8D @int main(){
@52E @  ios::sync_with_stdio(0);
@C97 @  cin.tie(NULL);
@59B @  string n,m;
@AA3 @  cin >> n >> m;
@053 @  string nova = m + '$';
@0BA @  nova += n;
@80C @  vi ans = z(nova);
@3BD @  int resp = 0;
@C3E @  for(int i = 0; i < ans.size();i++){
@B0A @    if (ans[i] == m.size()){
@7AD @      resp++;
@19B @    }
@0EF @  }
@046 @  cout << resp;
@    @
@    @
@BB3 @  return 0;
@EEA @}
