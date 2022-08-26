using pt = pair<ll, ll>;
using ptf = pair<ld, ld>;
pt operator+(pt a, pt b)
{ return pt {a.F + b.F, a.S + b.S}; }
pt operator-(pt a, pt b)
{ return pt {a.F - b.F, a.S - b.S}; }
ptf to_ptf(pt p) { return ptf {p.F, p.S}; }
int sign(ll x) { return (x > 0) - (x < 0); }
ll dot(pt a, pt b) { return a.F * b.F + a.S * b.S; }
ll cross(pt a, pt b) { return a.F * b.S - a.S * b.F; }
ld abs2(ptf a) { return dot(a, a); }
ld abs(ptf a) { return sqrtl(dot(a, a)); }
int ori(pt a, pt b, pt c)
{ return sign(cross(b - a, c - a)); }
bool operator<(pt a, pt b)
{ return a.F != b.F ? a.F < b.F : a.S < b.S; }

