@1F7 @const int MAXC = 1e7 + 10;
@BBB @int maxp[MAXC];
@73E @#pragma GCC optimize("O3")
@    @
@A63 @void crivo(){
@F29 @    for(int i=2; i<MAXC; i++)
@F95 @    {
@6C6 @        if(maxp[i]) continue;
@1C4 @        maxp[i] = i;
@    @
@30B @        for(int j=i*2; j<MAXC; j += i)
@9AA @            maxp[j] = i;
@E77 @    }
@E2D @}
