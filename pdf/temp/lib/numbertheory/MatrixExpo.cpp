@D41 @// Fast Exp
@031 @const ll mod = 1e9+7;
@    @
@    @
@8D8 @ll fexpll(ll a, ll n){
@D54 @	ll ans = 1;
@02A @	while(n){
@A19 @		if(n & 1) ans = (ans * a) % mod;
@4E2 @		a = (a * a) % mod;
@9D3 @		n >>= 1;
@CAB @	}
@BA7 @	return ans;
@D19 @}
@D41 @// matriz quadrada
@BE9 @class Matrix{
@673 @	public:
@21E @	vector<vector<ll>> mat;
@2E6 @	int m;
@1D7 @	Matrix(int m): m(m){
@593 @		mat.resize(m);
@2BC @		for(int i = 0; i < m; i++) mat[i].resize(m,0);
@809 @	}
@215 @	Matrix operator * (const Matrix& rhs){
@8EB @		Matrix ans = Matrix(m);
@94F @		for(int i = 0; i < m; i++)
@A75 @			for(int j = 0; j < m; j++)
@800 @				for(int k = 0; k < m; k++)
@1F7 @					ans.mat[i][j] = (ans.mat[i][j] + (mat[i][k] * rhs.mat[k][j]) % mod) % mod;
@BA7 @		return ans;
@2E6 @	}
@A70 @};
@    @
@E2E @Matrix fexp(Matrix a, ll n){
@71E @	int m = a.m;
@8EB @	Matrix ans = Matrix(m);
@642 @	for(int i = 0; i < m; i++) ans.mat[i][i] = 1;
@02A @	while(n){
@A50 @		if(n & 1) ans = ans * a;
@476 @		a = a * a;
@9D3 @		n >>= 1;
@CDF @	}
@BA7 @	return ans;
@966 @}
