@B2A @struct pt {
@662 @  double x, y;
@D30 @  pt() : x(0), y(0) {}
@E47 @  pt(double x, double y) : x(x), y(y) {}
@C17 @  pt operator + (pt o){ return pt(x + o.x, y + o.y);}
@55F @  pt operator - (pt o){ return pt(x-o.x, y-o.y ); }
@3F5 @  pt operator *(double k){ return pt(k*x, k*y ); }
@F7E @  double len(){return hypot(x,y); }
@811 @  double cross(pt o) {return x* o.y - y* o.x ;}
@B42 @  bool operator == (pt o) {return tie(x,y) == tie(o.x,o.y); }
@F41 @  bool operator != (pt o) {return tie(x,y) != tie(o.x,o.y); }
@357 @  bool operator < (pt o) {return tie(x,y) < tie(o.x,o.y); }
@    @
@742 @};
@    @
@458 @int orientation(pt a, pt b, pt c) {
@2B5 @  pt AB = b-a;
@0D1 @  pt BC = c-b;
@FCC @  double v = AB.cross(BC);
@0E9 @  if (v < 0) return -1; // clockwise
@896 @  if (v > 0) return +1; // counter-clockwise
@BB3 @  return 0;
@6F8 @}
@    @
@D90 @bool cw(pt a, pt b, pt c, bool include_collinear) {
@6EE @  int o = orientation(a, b, c);
@FFD @  return o < 0 || (include_collinear && o == 0);
@1D6 @}
@13D @bool ccw(pt a, pt b, pt c, bool include_collinear) {
@6EE @  int o = orientation(a, b, c);
@965 @  return o > 0 || (include_collinear && o == 0);
@926 @}
@    @
@628 @void convex_hull(vector<pt>& a, bool include_collinear = false) {
@53D @  if (a.size() == 1){
@505 @    return;
@C94 @  }
@D41 @  //sort(a.begin(),a.end());  if!sorted
@013 @  pt p1 = a[0], p2 = a.back();
@4DD @  vector<pt> up, down;
@1CB @  up.push_back(p1);
@726 @  down.push_back(p1);
@97F @  for (int i = 1; i < (int)a.size(); i++) {
@9A6 @    if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
@A6E @        while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i], include_collinear)){
@B1C @          up.pop_back();
@DDA @        }
@F29 @      up.push_back(a[i]);
@48C @    }
@8F4 @    if (i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear)) {
@80E @      while (down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i], include_collinear)){
@ABC @        down.pop_back();
@56D @      }
@48A @      down.push_back(a[i]);
@2EC @    }
@F64 @  }
@066 @  if(include_collinear && up.size() == a.size()) {
@3F7 @    reverse(a.begin(), a.end());
@505 @    return;
@C18 @  }
@228 @  a.clear();
@775 @  for (int i = 0; i < (int)up.size(); i++){
@DED @    a.push_back(up[i]);
@647 @  }
@B5A @  for (int i = down.size() - 2; i > 0; i--){
@F3F @  a.push_back(down[i]);
@FF7 @  }
@55E @}
@A17 @double dist(pt a,pt b){
@F30 @  double dist = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
@672 @  return (sqrt(dist));
@943 @}
