struct pt {
  double x, y;
  pt() : x(0), y(0) {}
  pt(double x, double y) : x(x), y(y) {}
  pt operator + (pt o){ return pt(x + o.x, y + o.y);}
  pt operator - (pt o){ return pt(x-o.x, y-o.y ); }
  pt operator *(double k){ return pt(k*x, k*y ); }
  double len(){return hypot(x,y); }
  double cross(pt o) {return x* o.y - y* o.x ;}
  bool operator == (pt o) {return tie(x,y) == tie(o.x,o.y); }
  bool operator != (pt o) {return tie(x,y) != tie(o.x,o.y); }
  bool operator < (pt o) {return tie(x,y) < tie(o.x,o.y); }
  
};

int orientation(pt a, pt b, pt c) {
  pt AB = b-a;
  pt BC = c-b;
  double v = AB.cross(BC);
  if (v < 0) return -1; // clockwise
  if (v > 0) return +1; // counter-clockwise
  return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
  int o = orientation(a, b, c);
  return o < 0 || (include_collinear && o == 0);
}
bool ccw(pt a, pt b, pt c, bool include_collinear) {
  int o = orientation(a, b, c);
  return o > 0 || (include_collinear && o == 0);
}

void convex_hull(vector<pt>& a, bool include_collinear = false) {
  if (a.size() == 1){
    return;
  }
  //sort(a.begin(),a.end());  if!sorted
  pt p1 = a[0], p2 = a.back();
  vector<pt> up, down;
  up.push_back(p1);
  down.push_back(p1);
  for (int i = 1; i < (int)a.size(); i++) {
    if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
        while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i], include_collinear)){
          up.pop_back();
        }          
      up.push_back(a[i]);
    }
    if (i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear)) {
      while (down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i], include_collinear)){
        down.pop_back();
      }      
      down.push_back(a[i]);
    }
  }
  if(include_collinear && up.size() == a.size()) {
    reverse(a.begin(), a.end());
    return;
  }
  a.clear();
  for (int i = 0; i < (int)up.size(); i++){
    a.push_back(up[i]);
  }     
  for (int i = down.size() - 2; i > 0; i--){
  a.push_back(down[i]);
  }      
}
double dist(pt a,pt b){
  double dist = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
  return (sqrt(dist)); 
}
