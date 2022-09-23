vector<int>  manacher_algorithm(string s) {
	int n = 2 * s.size() + 1;
	string t(n, 0);
	vector<int> len(n);//len[i]: max length when mid at i
	for(int i = 0; i < n; i++) {
		if(i & 1)
			t[i] = s[i / 2];
	}
	for(int i = 0, l = 0, r = -1; i < n; i++) {
		len[i] = (i <= r ? min(len[2 * l - i], r - i) : 0);
		while(i - len[i] >= 0 && i + len[i] < n && t[i - len[i]] == t[i + len[i]])
			len[i]++;
		len[i]--;
		if(i + len[i] > r)
			l = i, r = i + len[i];
	}
	return len;
}
