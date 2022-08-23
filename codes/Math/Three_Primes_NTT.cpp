// MOD: arbitrary prime
const int M1 = 998244353;
const int M2 = 1004535809;
const int M3 = 2013265921;
int super_big_crt(int64_t A, int64_t B, int64_t C) {
    static_assert(M1 <= M2 && M2 <= M3);
    ll r12 = mpow(M1, M2 - 2, M2);
    ll r13 = mpow(M1, M3 - 2, M3);
    ll r23 = mpow(M2, M3 - 2, M3);
    ll M1M2 = 1LL * M1 * M2 % MOD;
    B = (B - A + M2) * r12 % M2;
    C = (C - A + M3) * r13 % M3;
    C = (C - B + M3) * r23 % M3;
    return (A + B * M1 + C * M1M2) % MOD;
} // return ans % MOD
