#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
#define pii pair<int, int>
#define pff pair<float, float>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector <long long>
#define INF 0x3f3f3f3f

struct pt {
  ll x, y;
  pt() : x(0), y(0) {}
  pt(ll x, ll y) : x(x), y(y) {}
  pt operator + (pt o){ return pt(x + o.x, y + o.y);}
  pt operator - (pt o){ return pt(x-o.x, y-o.y ); }
  pt operator *(ll k){ return pt(k*x, k*y ); }
  ll len(){return hypot(x,y); }
  ll cross(pt o) {return x* o.y - y* o.x ;}
  bool operator == (pt o) {return tie(x,y) == tie(o.x,o.y); }
  bool operator != (pt o) {return tie(x,y) != tie(o.x,o.y); }
  bool operator < (pt o) {return tie(x,y) < tie(o.x,o.y); }
  
};
int sgn(long long val) { return val > 0 ? 1 : (val == 0 ? 0 : -1); }

bool lexComp(const pt &l, const pt &r) {
    return l.x < r.x || (l.x == r.x && l.y < r.y);
}

vector<pt> seq;
pt translation;
int n;

bool ptInTriangle(pt a, pt b, pt c, pt point) {
  ll s1 = abs((b-a).cross(c-b));
  ll area1 = abs((point - a).cross(point - b));
  ll area2 = abs((point - b).cross(point - c));
  ll area3 = abs((point - c).cross(point - a));
  ll s2 = area1 + area2 + area3;
  return s1 == s2;
}
void prepare(vector<pt> &points) {
    n = points.size();
    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (lexComp(points[i], points[pos]))
            pos = i;
    }
    rotate(points.begin(), points.begin() + pos, points.end());
    n--;
    seq.resize(n);
    for (int i = 0; i < n; i++)
        seq[i] = points[i + 1] - points[0];
    translation = points[0];
}

bool ptInConvexPolygon(pt ponto) {
  ponto = ponto - translation;
  if (seq[0].cross(ponto) != 0 &&sgn(seq[0].cross(ponto)) != sgn(seq[0].cross(seq[n - 1]))){
    return false;
  }
  if (seq[n - 1].cross(ponto) != 0 &&sgn(seq[n - 1].cross(ponto)) != sgn(seq[n - 1].cross(seq[0]))){
    return false;
  }
  if (seq[0].cross(ponto) == 0){
    return seq[0].len() >= ponto.len();
  }
  int l = 0, r = n - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    int pos = mid;
    if (seq[pos].cross(ponto) >= 0){
      l =mid;
    }else{
      r = mid;
    }
  }
  int pos = l;
  return ptInTriangle(seq[pos], seq[pos + 1], pt(0, 0), ponto);
}
