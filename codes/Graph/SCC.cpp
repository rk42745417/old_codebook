namespace scc {
    vector<int> edge[maxn], redge[maxn];
    stack<int, vector<int>> st;
    bool vis[maxn];
    void dfs(int u) {
        vis[u] = true;
        for(int v : edge[u])
            if(!vis[v])
                dfs(v);
        st.push(u);
    }
    void dfs2(int u, vector<int> &pa) {
        for(int v : redge[u])
            if(!pa[v])
                pa[v] = pa[u], dfs2(v, pa);
    }
    void add_edge(int u, int v) {
        edge[u].push_back(v);
        redge[v].push_back(u);
    }
    // pa[i]: scc id of all nodes in topo order
    vector<int> solve(int n) {
        vector<int> pa(n + 1);
        for(int i = 1; i <= n; i++)
            if(!vis[i])
                dfs(i);
        int id = 1; // start from 1
        while(!st.empty()) {
            int u = st.top();
            st.pop();
            if(!pa[u])
                pa[u] = id++, dfs2(u, pa);
        }
        return pa;
    } // 1-based
};
