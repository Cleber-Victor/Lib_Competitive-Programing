@797 @vll a;
@    @
@1DA @const int sumax = 100001;
@97B @const int nmax = 101;
@    @
@DDF @int dp [nmax][sumax];
@267 @int extra [nmax][sumax];
@    @
@    @
@030 @int solve(int n, int falta){
@    @
@8E0 @  if(n == a.size()) return 0;
@    @
@713 @  if(falta == 0) return 1;
@    @
@CB7 @  if(dp[n][falta] != -1) return dp[n][falta];
@    @
@997 @  int op1,op2;
@    @
@E45 @  op1 = solve(n+1,falta- a[n]); // pegar
@4E0 @  op2 = solve(n+1,falta); // nao pegar
@    @
@4C6 @  if(op1 == 1){
@99F @    extra[n][falta] = 1;
@E85 @  }else{
@F5C @    extra[n][falta] = 0;
@9BD @  }
@    @
@F9F @  dp[n][falta] = (op1||op2);
@    @
@A17 @  return dp[n][falta];
@    @
@7C7 @}
