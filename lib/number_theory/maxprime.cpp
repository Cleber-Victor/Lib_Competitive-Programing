const int MAXC = 1e7 + 10;
int maxp[MAXC];
#pragma GCC optimize("O3")
 
void crivo(){
    for(int i=2; i<MAXC; i++)
    {
        if(maxp[i]) continue;
        maxp[i] = i;
 
        for(int j=i*2; j<MAXC; j += i)
            maxp[j] = i;
    }   
}
 
