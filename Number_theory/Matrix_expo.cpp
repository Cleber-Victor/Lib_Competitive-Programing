#include<bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

const long long MOD = 1000000007;

long long m;

struct Matrix{
    //long long a[m][m];
    vector<vll> a;
    
    

    Matrix operator * (const Matrix  &p){
        //Matrix product[m][m] = {{{0,0},{0,0}}};
        Matrix product;
        product.a.resize(m); 
        for (int x = 0; x < m; x++){
            product.a[x].resize(m);
            for (int y = 0; y < m ; y++){
                product.a[x][y] = 0;
            }
        }
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j< m; j++){
                for (int k = 0; k < m; k++){
                    product.a[i][j] +=  a[i][k] * p.a[k][j];
                    product.a[i][j] = product.a[i][j] % MOD;
                }
            }
        }
        
        return product;
    }   
    
};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    long long k;
    cin >> m >> k;
    Matrix graph;
    graph.a.resize(m);
    Matrix ans;
    ans.a.resize(m);
    for ( int i = 0; i < m; i++){
        graph.a[i].resize(m);
        ans.a[i].resize(m);
        for (int j = 0; j < m; j++){
            if (i == j){
                ans.a[i][j] = 1;
            }else{
                ans.a[i][j] = 0;
            }
            int x; cin >> x;
            graph.a[i][j] = x;
        }
    }
    

    while (k > 0){
        if (k % 2) ans = ans * graph;

        graph = graph * graph;
        k = k /2;
    }

    long long resp = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j< m; j++){
            if(ans.a[i][j]){
                resp +=ans.a[i][j];
                resp = resp % MOD;
            }
        }
    }
    cout << resp;
    
    return 0;
}