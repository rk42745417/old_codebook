/* do not move ta,tb, default for xor
 * remove last 2 lines for non-xor
 * or convolution:
 * x[i]=ta,x[j]=ta+tb; x[i]=ta,x[j]=tb-ta for inv
 * and convolution:
 * x[i]=ta+tb,x[j]=tb; x[i]=ta-tb,x[j]=tb for inv */
void fwt(int x[], int N, bool inv = false) {
	for(int d = 1; d < N; d <<= 1) {
		for(int s = 0, d2 = d * 2; s < N; s += d2)
			for(int i = s, j = s + d; i < s + d; i++, j++) {
				int ta = x[i], tb = x[j];
				x[i] = modadd(ta, tb);
				x[j] = modsub(ta, tb);
			}
	}
	if(inv) for(int i = 0, invn = modinv(N); i < N; i++)
		x[i] = modmul(x[i], invn);
} // N: array len
