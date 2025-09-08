@7CE @using ll = long long int;
@B73 @#define pff pair<float, float>
@F79 @#define pll pair<long long, long long>
@0C1 @#define vi vector<int>
@358 @#define vll vector <long long>
@E1F @#define INF 0x3f3f3f3f
@    @
@B2A @struct pt {
@0BE @  ll x, y;
@D30 @  pt() : x(0), y(0) {}
@0FA @  pt(ll x, ll y) : x(x), y(y) {}
@C17 @  pt operator + (pt o){ return pt(x + o.x, y + o.y);}
@55F @  pt operator - (pt o){ return pt(x-o.x, y-o.y ); }
@A14 @  pt operator *(ll k){ return pt(k*x, k*y ); }
@9BF @  ll len(){return hypot(x,y); }
@8C8 @  ll cross(pt o) {return x* o.y - y* o.x ;}
@B42 @  bool operator == (pt o) {return tie(x,y) == tie(o.x,o.y); }
@F41 @  bool operator != (pt o) {return tie(x,y) != tie(o.x,o.y); }
@357 @  bool operator < (pt o) {return tie(x,y) < tie(o.x,o.y); }
@    @
@2A4 @};
@AC7 @int sgn(long long val) { return val > 0 ? 1 : (val == 0 ? 0 : -1); }
@    @
@043 @bool lexComp(const pt &l, const pt &r) {
@47C @    return l.x < r.x || (l.x == r.x && l.y < r.y);
@EF9 @}
@    @
@891 @vector<pt> seq;
@99B @pt translation;
@1A8 @int n;
@    @
@7A7 @bool ptInTriangle(pt a, pt b, pt c, pt point) {
@0E1 @  ll s1 = abs((b-a).cross(c-b));
@708 @  ll area1 = abs((point - a).cross(point - b));
@CC2 @  ll area2 = abs((point - b).cross(point - c));
@243 @  ll area3 = abs((point - c).cross(point - a));
@7F8 @  ll s2 = area1 + area2 + area3;
@83F @  return s1 == s2;
@889 @}
@2B3 @void prepare(vector<pt> &points) {
@2BC @    n = points.size();
@BEC @    int pos = 0;
@6F5 @    for (int i = 1; i < n; i++) {
@B9B @        if (lexComp(points[i], points[pos]))
@E4C @            pos = i;
@9F3 @    }
@CF4 @    rotate(points.begin(), points.begin() + pos, points.end());
@15A @    n--;
@317 @    seq.resize(n);
@830 @    for (int i = 0; i < n; i++)
@37D @        seq[i] = points[i + 1] - points[0];
@D86 @    translation = points[0];
@837 @}
@    @
@E1D @bool ptInConvexPolygon(pt ponto) {
@216 @  ponto = ponto - translation;
@692 @  if (seq[0].cross(ponto) != 0 &&sgn(seq[0].cross(ponto)) != sgn(seq[0].cross(seq[n - 1]))){
@D1F @    return false;
@B3C @  }
@5C9 @  if (seq[n - 1].cross(ponto) != 0 &&sgn(seq[n - 1].cross(ponto)) != sgn(seq[n - 1].cross(seq[0]))){
@D1F @    return false;
@5F1 @  }
@28F @  if (seq[0].cross(ponto) == 0){
@9F5 @    return seq[0].len() >= ponto.len();
@4F1 @  }
@561 @  int l = 0, r = n - 1;
@219 @  while (r - l > 1) {
@AE0 @    int mid = (l + r) / 2;
@351 @    int pos = mid;
@563 @    if (seq[pos].cross(ponto) >= 0){
@229 @      l =mid;
@177 @    }else{
@168 @      r = mid;
@66F @    }
@5C7 @  }
@5AB @  int pos = l;
@526 @  return ptInTriangle(seq[pos], seq[pos + 1], pt(0, 0), ponto);
@BB8 @}
