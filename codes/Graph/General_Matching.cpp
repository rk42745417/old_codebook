// Find max matching on general graph in O(|V|^3)
vector<int> max_matching(vector<vector<int>> g) {
    int n = g.size();
    vector<int> match(n + 1, n), pre(n + 1, n), que;
    vector<int> s(n + 1), mark(n + 1), pa(n + 1);
    function<int(int)> fnd = [&](int x) {
        if(x == pa[x]) return x;
        return pa[x] = fnd(pa[x]);
    };
    auto lca = [&](int x, int y) {
        static int tk = 0;
        tk++;
        x = fnd(x);
        y = fnd(y);
        for(;; swap(x, y))
            if(x != n) {
                if(mark[x] == tk)
                    return x;
                mark[x] = tk;
                x = fnd(pre[match[x]]);
            }
    };
    auto blossom = [&](int x, int y, int l) {
        while(fnd(x) != l) {
            pre[x] = y;
            y = match[x];
            if(s[y] == 1)
                que.push_back(y), s[y] = 0;
            if(pa[x] == x) pa[x] = l;
            if(pa[y] == y) pa[y] = l;
            x = pre[y];
        }
    };
    auto bfs = [&](int r) {
        fill(s.begin(), s.end(), -1);
        iota(pa.begin(), pa.end(), 0);
        que = {r}; s[r] = 0;
        for(int it = 0; it < que.size(); it++) {
            int x = que[it];
            for(int u : g[x]) {
                if(s[u] == -1) {
                    pre[u] = x;
                    s[u] = 1;
                    if(match[u] == n) {
                        for(int a = u, b = x, lst;
                                b != n; a = lst, b = pre[a]) {
                            lst = match[b];
                            match[b] = a;
                            match[a] = b;
                        }
                        return;
                    }
                    que.push_back(match[u]);
                    s[match[u]] = 0;
                }
                else if(s[u] == 0 && fnd(u) != fnd(x)) {
                    int l = lca(u, x);
                    blossom(x, u, l);
                    blossom(u, x, l);
                }
            }
        }
    };
    for(int i = 0; i < n; i++)
        if(match[i] == n) bfs(i);
    match.resize(n);
    for(int i = 0; i < n; i++)
        if(match[i] == n) match[i] = -1;
    return match;
} // 0-based
