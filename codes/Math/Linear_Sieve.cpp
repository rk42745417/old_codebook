int least_prime_divisor[maxn];
vector<int> pr;
void linear_sieve() {
    for(int i = 2; i < maxn; i++) {
        if(!least_prime_divisor[i]) {
            pr.push_back(i);
            least_prime_divisor[i] = i;
        }
        for(int p : pr) {
            if(1LL * i * p >= maxn) break;
            least_prime_divisor[i * p] = p;
            if(i % p == 0) break;
        }
    }
}
