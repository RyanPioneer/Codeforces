/**
 * Source: t.ly/9yS9Q
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

const int MX = 3e5+2;

class TrieNode {
public:
    TrieNode *next[2];
    int num[2];
    TrieNode() {
        for (int i = 0; i < 2; i++) {
            num[i] = 0;
            next[i] = nullptr;
        }
    }
};

void solve() {
    ll n;
    cin >> n;
    ll total[31][2] = {0};
    TrieNode *root = new TrieNode();
    for (ll i = 0, num; i < n; ++i) {
        TrieNode *node = root;
        cin >> num;
        for (ll j = 30; j >= 0; --j) {
            int next = ((num >> j) & 1);
            if (next == 1) {
                total[j][0] += node->num[0];
                node->num[1]++;
            }
            if (next == 0) {
                total[j][1] += node->num[1];
                node->num[0]++;
            }
            if (node->next[next] == nullptr) {
                node->next[next] = new TrieNode();
            }
            node = node->next[next];
        }
    }

    ll res = 0, cnt = 0;
    for (int i = 0; i < 31; i++) {
        if (total[i][1] > total[i][0]) {
            res += 1 << i;
            cnt += total[i][0];
        } else {
            cnt += total[i][1];
        }
    }
    cout << cnt << " " << res << endl;
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