// Find maximum bipartite matching in O(Esqrt(V))
// g: edges for all nodes at left side
vector<int> hopcroft_karp(vector<vector<int>> g, int l, int r) {
    vector<int> match_l(l, -1), match_r(r, -1);
    vector<int> dis(l);
    vector<bool> vis(l);
    while(true) {
        queue<int> que;
        for(int i = 0; i < l; i++) {
            if(match_l[i] == -1)
                dis[i] = 0, que.push(i);
            else
                dis[i] = -1;
            vis[i] = false;
        }
        while(!que.empty()) {
            int x = que.front();
            que.pop();
            for(int y : g[x])
                if(match_r[y] != -1 && dis[match_r[y]] == -1) {
                    dis[match_r[y]] = dis[x] + 1;
                    que.push(match_r[y]);
                }
        }
        auto dfs = [&](auto dfs, int x) {
            vis[x] = true;
            for(int y : g[x]) {
                if(match_r[y] == -1) {
                    match_l[x] = y;
                    match_r[y] = x;
                    return true;
                }
                else if(dis[match_r[y]] == dis[x] + 1
                        && !vis[match_r[y]]
                        && dfs(dfs, match_r[y])) {
                    match_l[x] = y;
                    match_r[y] = x;
                    return true;
                }
            }
            return false;
        };
        bool ok = true;
        for(int i = 0; i < l; i++)
            if(match_l[i] == -1 && dfs(dfs, i))
                ok = false;
        if(ok)
            break;
    }
    return match_l;
} // 0-based
