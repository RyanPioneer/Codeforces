/**
 * Source: t.ly/ntEGb
 * Date: 2024/5/4
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


const int MX = 3e5+10;

void solve() {
    int n;
    cin >> n;
    int attack[MX], defense[MX], damage[MX] = {0};
    for (int i = 0; i < n; i++) {
        cin >> attack[i];
        if (i > 0) damage[i - 1] += attack[i];
        if (i + 1 < n) damage[i + 1] += attack[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> defense[i];
    }

    list<int> List;
    unordered_map<int, list<int>::iterator> mp;
    queue<int> q;
    set<int> Set;
    for (int i = 0; i < n; i++) {
        List.push_back(i);
        mp[i] = prev(end(List));
        q.push(i);
    }

    for (int i = 0; i < n; i++) {
        int sz = q.size();
        while (sz--) {
            int pos = q.front();
            q.pop();
            if (mp.find(pos) == mp.end()) continue;
            auto it = mp[pos];
            damage[pos] = 0;
            if (it != begin(List)) {
                damage[pos] += attack[*prev(it)];
            }
            if (next(it) != end(List)) {
                damage[pos] += attack[*next(it)];
            }
            if (damage[pos] > defense[pos]) {
                if (it != begin(List) && (q.empty() || q.front() != *prev(it))) {
                    q.push(*prev(it));
                }
                if (next(it) != end(List)) {
                    q.push(*next(it));
                }
                Set.insert(pos);
            }
        }
        cout << Set.size() << " ";
        for (auto pos2: Set) {
            auto it2 = mp[pos2];
            List.erase(it2);
            mp.erase(pos2);
        }
        Set.clear();
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin >> t; t; t--) {
        solve();
    }
}