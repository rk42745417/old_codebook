// return globale min cut in O(n^3)
struct SW { // 1-based
    int edge[maxn][maxn], wei[maxn], n;
    bool vis[maxn], del[maxn];
    void init(int _n) {
        n = _n; MEM(edge, 0); MEM(del, 0);
    }
    void add_edge(int u, int v, int w) {
        edge[u][v] += w; edge[v][u] += w;
    }
    void search(int &s, int &t) {
        MEM(wei, 0); MEM(vis, 0);
        s = t = -1;
        while(true) {
            int mx = -1;
            for(int i = 1; i <= n; i++) {
                if(del[i] || vis[i]) continue;
                if(mx == -1 || wei[mx] < wei[i])
                    mx = i;
            }
            if(mx == -1) break;
            vis[mx] = true;
            s = t; t = mx;
            for(int i = 1; i <= n; i++)
                if(!vis[i] && !del[i])
                    wei[i] += edge[mx][i];
        }
    }
    int solve() {
        int ret = INF;
        for(int i = 1; i < n; i++) {
            int x, y;
            search(x, y);
            ret = min(ret, wei[y]);
            del[y] = true;
            for(int j = 1; j <= n; j++) {
                edge[x][j] += edge[y][j];
                edge[j][x] += edge[y][j];
            }
        }
        return ret;
    }
} sw;

