@F79 @#define pll pair<long long, long long>
@0C1 @#define vi vector<int>
@358 @#define vll vector<long long>
@    @
@A8C @const int LIM = 1e6 + 5;
@BDE @bool isPrime[LIM];
@    @
@003 @vi sieve(){ // crivo com os numeros primos
@C08 @  memset(isPrime,1, sizeof(isPrime));
@1F3 @  isPrime[0] = isPrime[1] = false;
@    @
@AF0 @  vi primes;
@C35 @  for(int i =2;i <LIM; i++){
@5ED @    if(isPrime[i]){
@E74 @      primes.push_back(i);
@889 @      for(int j = i * 2; j <LIM; j +=i){
@90F @        isPrime[j] = false;
@8B7 @      }
@00A @    }
@1C3 @  }
@    @
@A20 @  return primes;
@90C @}
@    @
@    @
@    @
@    @
@    @
@    @
@    @
@E8D @int main(){
@52E @  ios::sync_with_stdio(0);
@C97 @  cin.tie(NULL);
@    @
@BB3 @  return 0;
@4EC @}
