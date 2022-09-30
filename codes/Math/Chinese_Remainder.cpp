ll chre(ll x1, ll m1, ll x2, ll m2){
    ll g = __gcd(m1, m2);
    if ((x2 - x1) % g) return -1; //no solution
    m1 /= g; m2 /= g;
    ll p = get<0>(extgcd(m1, m2));
    ll lcm = m1 * m2 * g;
    ll res = p * (x2 - x1) * m1 + x1;
    //might overflow, be cautious
    return (res % lcm + lcm) % lcm;
}