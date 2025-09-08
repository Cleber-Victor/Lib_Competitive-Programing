#include<bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

const long long MOD = 1000000007;

const double eps = 1e-6;

double b,c;
double f(double m){
	double ret = (m*m + b*m + c)/sin(m);
	
	return ret;
}



int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL);
	int t; cin >>t;

	while(t--){
		//cin >>b>>c;	
		double l,r;
		cin>>b>>c;
		l = 0.000001;
		r = (M_PI/2);
		double divide = 3;
		while(r-l > eps){
			double m1 = l + ((r-l)/divide);
			double m2 = r - ((r-l)/divide);
			if(f(m2)<=f(m1)){
				l = m1;				
			}else{
				r = m2;
			}
		}
		double div =2;
		double ans = f((l+r)/div);	
		cout << setprecision(10)<<fixed;
		cout <<ans<<'\n';
	}
    
  return 0;
}
