// C_k = \sum_{i xor j = k} A_i * B_j
// C_k = ifwt(fwt(A_k) * fwt(B_k))
// arr.size() = 2^n
const int mod = 998244353;
void fwt(int n, vector<int> &arr) {
	for(int i = 0; i < n; i++) {
		auto x = arr;
		for(int j = 0; j < (1 << n); j++) {
			if(j >> i & 1)
				arr[j] = (x[j ^ (1 << i)] - x[j] + mod) % mod;
			else
				arr[j] = (x[j] + x[j | (1 << i)]) % mod;
		}
	}
}
void ifwt(int n, vector<int> &arr) {
	ll inv = (mod + 1) / 2;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < (1 << n); j++) {
			if(j >> i & 1)
				continue;
			int a = (arr[j] + arr[j | (1 << i)]) * inv % mod;
			int b = (arr[j] - a + mod) % mod;
			arr[j] = a;
			arr[j | (1 << i)] = b;
		}
	}
}
