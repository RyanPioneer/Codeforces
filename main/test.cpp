#include <iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
#include <unordered_set>
using namespace std;

const int N=2e5+10;

typedef  long long ll;
typedef pair<int,int> pii;

ll arr[N];

void Solved() {

    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        if(i%2==0) arr[i]=x;
        else arr[i]=-x;
    }

//用set判重，当前面出现过和这个前缀和相等值的前缀和，那么这两个之间的区间和是0.
// s[a]-s[b-1]---->a到b之间的区间和。

    unordered_set<ll> s;

//注意如果前缀和本身就是0，那么就不需要和其他前缀和组合也能满足情况。
    s.insert(0);
    int num = 0;

    for(int i=1;i<=n;i++){
        int x;
        num+=arr[i];

        if(s.count(num)){
            cout<<"YES"<<endl;
            return;
        }

        s.insert(num);
    }
    cout<<"NO"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;
    while(t--) {
        Solved();
    }
    return 0;
}