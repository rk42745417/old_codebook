using cplx = complex<double>;
const double pi = acos(-1);
cplx omega[maxn * 4];
void prefft(int n) {
  for(int i = 0; i <= n; i++)
    omega[i] = cplx(cos(2 * pi * i / n),
          sin(2 * pi * i / n));
}
void fft(vector<cplx> &v, int n) {
    int z = __builtin_ctz(n) - 1;
    for(int i = 0; i < n; i++) {
        int x = 0, j = 0;
        for(; (1 << j) < n; j++) x ^= (i >> j & 1) << (z - j);
        if(x > i) swap(v[x], v[i]);
    }
    for(int s = 2; s <= n; s <<= 1) {
        int z = s >> 1;
        for(int i = 0; i < n; i += s) {
            for(int k = 0; k < z; k++) {
                cplx x = v[i + z + k] * omega[n / s * k];
                v[i + z + k] = v[i + k] - x;
                v[i + k] = v[i + k] + x;
            }
        }
    }
}
void ifft(vector<cplx> &v, int n) {
    fft(v, n); reverse(v.begin() + 1, v.end());
    for(int i = 0; i < n; i++) v[i] = v[i] * cplx(1.0 / n, 0);
}
vl convolution(const vl &a, const vl &b) {
    // Should be able to handle N <= 10^5, C <= 10^4
    int sz = 1, tot = a.size() + b.size() - 1;
    while(sz < tot) sz <<= 1;
    prefft(sz);
    vector<cplx> v(sz);
    for(int i = 0; i < sz; i++) {
        double re = i < a.size() ? a[i] : 0;
        double im = i < b.size() ? b[i] : 0;
        v[i] = cplx(re, im);
    }
    fft(v, sz);
    for(int i = 0; i <= sz / 2; i++) {
        int j = (sz - i) & (sz - 1);
        cplx x = (v[i] + conj(v[j])) * (v[i] - conj(v[j])) * cplx(0, -0.25);
        if(j != i) v[j] = (v[j] + conj(v[i])) * (v[j] - conj(v[i])) * cplx(0, -0.25);
        v[i] = x;
    }
    ifft(v, sz);
    vl c(sz);
    for(int i = 0; i < sz; i++)c[i] = round(v[i].real());
    c.resize(tot);
    return c;
}
