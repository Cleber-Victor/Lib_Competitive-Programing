vll a;
 
const int sumax = 100001;
const int nmax = 101;
 
int dp [nmax][sumax];
int extra [nmax][sumax];
 
 
int solve(int n, int falta){
 
  if(n == a.size()) return 0;
 
  if(falta == 0) return 1;
 
  if(dp[n][falta] != -1) return dp[n][falta];
 
  int op1,op2;
 
  op1 = solve(n+1,falta- a[n]); // pegar
  op2 = solve(n+1,falta); // nao pegar
 
  if(op1 == 1){
    extra[n][falta] = 1;
  }else{
    extra[n][falta] = 0;
  }
 
  dp[n][falta] = (op1||op2);
 
  return dp[n][falta];
 
}
 
