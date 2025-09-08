#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

const int LIM = 1e6 + 5;
bool isPrime[LIM];

vi sieve(){ // crivo com os numeros primos
  memset(isPrime,1, sizeof(isPrime));
  isPrime[0] = isPrime[1] = false;

  vi primes;
  for(int i =2;i <LIM; i++){
    if(isPrime[i]){
      primes.push_back(i);
      for(int j = i * 2; j <LIM; j +=i){
        isPrime[j] = false;
      }
    }
  }

  return primes;
}







int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  return 0;
}