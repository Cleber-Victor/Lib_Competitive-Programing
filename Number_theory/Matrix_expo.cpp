#include<bits/stdc++.h>
 
using namespace std;
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
 
typedef long long ll;
 
const ll MOD = 1e9 +7;;
ll m,n,k;
vector<vll>bse;
 
struct Matrix{
  vector<vll> a;
  Matrix operator * (const Matrix  &p){
    Matrix product;
		product.a = bse;
    for (int i = 0; i < n; i++){
      for (int j = 0; j< n; j++){
        for (int k = 0; k < n; k++){
          product.a[i][j] = (product.a[i][j]+ ((a[i][k] * p.a[k][j])%MOD))%MOD ;
        }
      }
    }  
    return product;
  }   
};

int main(){
  ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;  // n é o lado da matriz quadrada
	ll ans;
	Matrix base;   // matriz de recorrencia
	Matrix resp;   // matriz unitaria
	bse.assign(n,vll(n,0));  // necessario para a Matrix product;
	resp.a.resize(n);
	vi a(n);
	for(int i =0; i <n;i++){
		cin >>a[i];
	}
	for(int i =0; i <n;i++){
		resp.a[i].resize(n);
		for(int j =0; j <n;j++){
			if(i==j){
				resp.a[i][j]=1;
			}else{
				resp.a[i][j]=0;
			}
		}
	}
	base.a.resize(n);


	return 0;
}
 
