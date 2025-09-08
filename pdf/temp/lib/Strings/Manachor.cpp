@F79 @#define pll pair<long long, long long>
@0C1 @#define vi vector<int>
@358 @#define vll vector<long long>
@    @
@AD1 @typedef long long ll;
@    @
@E8D @int main(){
@52E @  ios::sync_with_stdio(0);
@C97 @  cin.tie(NULL);
@905 @  string a;
@964 @  cin >> a;
@94D @  int n = a.size();
@BA7 @  vi d1(n);
@358 @  vi d2(n);
@3B8 @  for(int i = 0, l = 0, r = -1; i < n; i++){
@DF9 @    int k;
@6D2 @    if (i > r){
@B24 @      k = 1;
@260 @    }else{
@CFC @      k = min (d1[l + r -i], r - i + 1);
@310 @    }
@F96 @    while(0 <= i - k && i + k < n && a[i-k] == a[i + k]){
@AC1 @      k++;
@936 @    }
@61E @    d1[i] = k--;
@17C @    if(i + k > r){
@BB6 @      l = i - k;
@272 @      r = i + k;
@007 @    }
@E8E @  }
@    @
@3B8 @  for(int i = 0, l = 0, r = -1; i < n; i++){
@DF9 @    int k;
@6D2 @    if (i > r){
@5A4 @      k = 0;
@FAD @    }else{
@0E2 @      k = min (d2[l + r -i + 1], r - i + 1);
@D6A @    }
@146 @    while(0 <= i - k -1 && i + k < n && a[i-k - 1] == a[i + k]){
@AC1 @      k++;
@BE7 @    }
@E1C @    d2[i] = k--;
@17C @    if(i + k > r){
@56F @      l = i - k -1;
@272 @      r = i + k;
@6C1 @    }
@A15 @  }
@C85 @  int max_par = 0;
@805 @  int max_impar = 0;
@478 @  int max_indice_par;
@A41 @  int max_indice_impar;
@724 @  for(int i = 0; i < d1.size();i++){
@005 @    if(d1[i] >max_impar ){
@788 @      max_indice_impar = i;
@553 @    }
@B2F @    if(d2[i] >max_par ){
@9BB @      max_indice_par = i;
@AD8 @    }
@F8F @    max_impar = max (max_impar,d1[i]);
@D2A @    max_par = max (max_par,d2[i]);
@605 @  }
@0BD @  string ans;
@370 @  if(max_par >= max_impar){
@4F7 @    ans = a.substr(max_indice_par - max_par, max_par * 2);
@1A6 @  }else{
@4BB @    ans = a.substr(max_indice_impar - (max_impar-1),max_impar * 2 -1 );
@27E @  }
@    @
@F21 @  cout << ans;
@    @
@BB3 @  return 0;
@31E @}
