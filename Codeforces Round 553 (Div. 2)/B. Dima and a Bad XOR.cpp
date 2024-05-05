/**
 * Source: t.ly/ZLUWW
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

const int MX = 502;


void solve() {
    int n, m, dp1[1024] = {0}, dp2[1024] = {0}, choose[MX][1024] = {0}, arr[MX][MX];
    dp2[0] = 1;
    cin >> n >> m;
    for (int i = 0, num; i < n; i++) {
        for (int j = 0; j < 1024; j++) {
            dp1[j] = dp2[j];
            dp2[j] = 0;
        }
        for (int j = 0; j < m; j++) {
            cin >> num;
            arr[i][j] = num;
            for (int k = 0; k < 1024; k++) {
                if (dp1[k ^ num]) {
                    dp2[k] = 1;
                    choose[i][k] = j;
                }
            }
        }
    }
    bool check = false;
    int target;
    for (int i = 1; i < 1024; i++) {
        if (dp2[i]) {
            target = i;
            check = true;
            break;
        }
    }
    cout << (check ? "TAK" : "NIE") << endl;
    if (check) {
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            st.push(choose[i][target]);
            target ^= arr[i][choose[i][target]];
        }
        while (!st.empty()) {
            cout << st.top() + 1 << " ";
            st.pop();
        }
        cout << endl;
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