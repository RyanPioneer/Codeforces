/**
 * Source: t.ly/XH9TR
 * Date: 2024/5/6
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

struct edge {
    int next, to;
} e[MX << 1];

int head[MX] = {0}, cnt = 0;

void addEdge(int from, int to) {
    e[++cnt] = {head[from], to};
    head[from] = cnt;
}

void solve() {
    int n, m, mxDeg = 0, maxNode;
    cin >> n >> m;
    int degree[MX] = {0}, visited[MX] = {0};
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        addEdge(a, b);
        addEdge(b, a);
        degree[a]++;
        degree[b]++;
        if (degree[a] > mxDeg) {
            mxDeg = degree[a];
            maxNode = a;
        }
        if (degree[b] > mxDeg) {
            mxDeg = degree[b];
            maxNode = b;
        }
    }

    queue<int> q;
    q.push(maxNode);
    visited[maxNode] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = head[cur]; i; i = e[i].next) {
            int j = e[i].to;
            if (!visited[j]) {
                cout << cur << " " << j << endl;
                visited[j] = 1;
                q.push(j);
            }
        }
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