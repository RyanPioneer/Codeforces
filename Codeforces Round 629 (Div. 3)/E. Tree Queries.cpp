/**
 * Source: t.ly/cwnQ6
 * Date: 2024/5/5
 * Time:
 * Space:
 * Skill:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;
#define SZ(X) ((int)(X).size())
#define ll long long
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;

const int MX = 2e5+2;

int depth[MX], f[MX][20], head[MX], cnt = 0, v[MX];

struct edge {
    int next, to;
} e[MX << 1];

void addEdge(int from, int to) {
    e[++cnt] = {head[from], to};
    head[from] = cnt;
}

bool cmp(int x, int y) {
    return depth[x] > depth[y];
}

void dfs(int cur, int par) {
    depth[cur] = depth[par] + 1;
    f[cur][0] = par;
    for (int i = 1; i < 20; i++) {
        f[cur][i] = f[f[cur][i - 1]][i - 1];
    }
    for (int i = head[cur]; i != 0; i = e[i].next) {
        if (e[i].to != par) dfs(e[i].to, cur);
    }
}

bool check(int c, int p) {
    if (p == c) return true;
    for (int i = 19; i >= 0; i--) {
        if (depth[f[c][i]] >= depth[p]) {
            c = f[c][i];
        }
    }
    return c == p;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    for (int i = 1, n1, n2; i < n; i++) {
        cin >> n1 >> n2;
        addEdge(n1, n2);
        addEdge(n2, n1);
    }

    dfs(1, 0);

    for (int i = 1, k; i <= m; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> v[j];
            v[j] = v[j] == 1 ? 1 : f[v[j]][0];
        }
        sort(v + 1, v + k + 1, cmp);
        bool res = true;
        for (int j = 2; j <= k; j++) {
            if (!check(v[j - 1], v[j])) {
                res = false;
                break;
            }
        }
        cout << (res ? "YES" : "NO") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (t = 1; t; t--) {
        solve();
    }
}