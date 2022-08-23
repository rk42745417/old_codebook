// return (d, x, y) s.t. ax+by=d=gcd(a,b)
template<typename T>
tuple<T, T, T> extgcd(T a, T b) {
    if(!b) return make_tuple(a, 1, 0);
    auto [d, x, y] = extgcd(b, a % b);
    return make_tuple(d, y, x - (a / b) * y);
} // not tested
