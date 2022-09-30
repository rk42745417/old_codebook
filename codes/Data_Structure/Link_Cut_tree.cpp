namespace LCT {
    const int N = 1e5 + 25;
    int pa[N], ch[N][2];
    ll dis[N], prv[N], tag[N];
    vector<pair<int, int>> edge[N];
    vector<pair<ll, ll>> eve;
    inline bool dir(int x) { return ch[pa[x]][1] == x; }
    inline bool is_root(int x) { return ch[pa[x]][0] != x && ch[pa[x]][1] != x; }
    inline void rotate(int x) {
        int y = pa[x], z = pa[y], d = dir(x);
        if(!is_root(y))
            ch[z][dir(y)] = x;
        pa[x] = z;
        ch[y][d] = ch[x][!d];
        if(ch[x][!d])
            pa[ch[x][!d]] = y;
        ch[x][!d] = y;
        pa[y] = x;
    }
    inline void push_tag(int x) {
        if(!tag[x])
            return;
        prv[x] = tag[x];
        if(ch[x][0])
            tag[ch[x][0]] = tag[x];
        if(ch[x][1])
            tag[ch[x][1]] = tag[x];
        tag[x] = 0;
    }
    void push(int x) {
        if(!is_root(x))
            push(pa[x]);
        push_tag(x);
    }
    inline void splay(int x) {
        push(x);
        while(!is_root(x)) {
            if(int y = pa[x]; !is_root(y))
                rotate(dir(y) == dir(x) ? y : x);
            rotate(x);
        }
    }
    inline void access(ll t, int x) {
        int lst = 0, tx = x;
        while(x) {
            splay(x);
            if(lst) {
                ch[x][1] = lst;
                eve.push_back({prv[x] + dis[x], t + dis[x]});
            }
            lst = x;
            x = pa[x];
        }
        splay(tx);
        if(ch[tx][0])
            tag[ch[tx][0]] = t;
    }
    void dfs(int u) {
        prv[u] = -LINF;
        for(const auto &[v, c] : edge[u]) {
            if(v == pa[u])
                continue;
            pa[v] = u;
            ch[u][1] = v;
            dis[v] = dis[u] + c;
            dfs(v);
        }
    }
};
