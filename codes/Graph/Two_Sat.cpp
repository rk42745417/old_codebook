// maxn >= 2 * n (n: number of variables)
// clauses: (x, y) = x V y, -x if neg, var are 1-based
// return empty is no solution
vector<bool> solve(int n, const vector<pair<int, int>> &clauses) {
    auto id = [&](int x) { return abs(x) + n * (x < 0); };
    for(const auto &[a, b] : clauses) {
        scc::add_edge(id(-a), id(b));
        scc::add_edge(id(-b), id(a));
    }
    auto pa = scc::solve(n * 2);
    vector<bool> ans(n + 1);
    for(int i = 1; i <= n; i++) {
        if(pa[i] == pa[i + n])
            return vector<bool>();
        ans[i] = pa[i] > pa[i + n];
    }
    return ans;
}
