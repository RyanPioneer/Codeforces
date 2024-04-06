/**
 * Source: is.gd/Gw3dwd
 * Date: 2024/4/6
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


#define SZ(X) ((int)(X).size())
#define ll long long
using namespace std;


void solve() {
    int n, cnt[10] = {0}, m;
    bool res = false;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        cnt[m % 10]++;
    }

    for (int i = 0; i < 10 && !res; i++) {
        if (3 * i % 10 == 3 && cnt[i] >= 3) {
            res = true;
            break;
        }
    }

    for (int i = 0; i < 10 && !res; i++) {
        for (int j = 0; j < 10 && !res; j++) {
            if (i == j) continue;
            if ((i * 2 + j) % 10 == 3 && cnt[i] >= 2 && cnt[j] >= 1) {
                res = true;
                break;
            }
        }
    }

    for (int i = 0; i < 10 && !res; i++) {
        for (int j = 0; j < 10 && !res; j++) {
            if (i == j) continue;
            for (int k = 0; k < 10 && !res; k++) {
                if (k == i || k == j) continue;
                if ((i + j + k) % 10 == 3 && cnt[i] >= 1 && cnt[j] >= 1 && cnt[k] >= 1) {
                    res = true;
                    break;
                }
            }
        }
    }
    cout << (res ? "yes" : "no") << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin >> t; t--;) {
        solve();
    }
}