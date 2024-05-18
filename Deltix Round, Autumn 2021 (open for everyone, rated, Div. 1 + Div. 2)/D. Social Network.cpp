/**
 * Source: t.ly/vOwNK
 * Date: 2024/5/18
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
#define ll long long
#define SZ(X) ((int)(X).size())
#define For(i, a, b) for (int i = (a); i <= (b); i++)
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;

const int MX = 1010;

void solve() {
    int n, d, a, b, addition = 0;
    cin >> n >> d;
    int groups[MX], sz[MX];
    for (int i = 1; i <= n; i++) sz[i] = 1;
    iota(groups, groups + MX, 0);

    function<int(int)> findGroup = [&](int idx) {
        if (groups[idx] != idx) {
            groups[idx] = findGroup(groups[idx]);
        }
        return groups[idx];
    };

    For(i,1,d) {
        cin >> a >> b;
        int groupA = findGroup(a);
        int groupB = findGroup(b);
        if (groupA != groupB) {
            sz[groupA] += sz[groupB];
            groups[groupB] = groupA;
        } else {
            addition++;
        }
        vector<int> arr;
        For(j,1,n) {
            if (findGroup(j) == j) {
                arr.push_back(sz[j]);
            }
        }
        sort(begin(arr), end(arr), greater<int>());
        int num = 0;
        for (int j = 0; j < arr.size() && j <= addition; j++) {
            num += arr[j];
        }
        cout << num - 1 << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (t=1; t; t--) {
        solve();
    }
}