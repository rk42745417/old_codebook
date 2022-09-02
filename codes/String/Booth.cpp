// return start index of minimum rotation in O(|s|)
int min_rotation(string s) {
    s += s;
    int k = 0;
    vector<int> f(s.size(), -1);
    for(int j = 1; j < s.size(); j++) {
        int i = f[j - k - 1];
        for(i = f[j - k - 1];
                i != -1 && s[j] != s[i + k + 1]; i = f[i])
            if(s[k + i + 1] > s[j])
                k = j - i - 1;
        if(i == -1 && s[j] != s[k + i + 1]) {
            if(s[j] < s[k + i + 1])
                k = j;
            f[j - k] = -1;
        }
        else
            f[j - k] = i + 1;
    }
    return k;
}

