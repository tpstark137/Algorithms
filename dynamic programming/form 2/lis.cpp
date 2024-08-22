#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define read(x) \
    int x;      \
    cin >> x
using namespace std;
void init_code()
{
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int n;
vector<int> arr;
int dp[1005];

int rec(int level)
{
    // pruning case
    if (level < 0)
        return -1e9;
    int ans = 1;
    int curr = level;
    // cache check
    if (dp[level] != -1)
        return dp[level];

    for (int prev_taken = 0; prev_taken < level; prev_taken++)
    {
        if (arr[prev_taken] < arr[curr])
        {
            ans = max(ans, 1 + rec(prev_taken));
        }
    }
    return dp[level] = ans;
}

void solve()
{
    cin >> n;
    arr.resize(n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int best = 0;
    for (int i = 0; i < n; i++)
    {
        best = max(best, rec(i));
    }
    cout << best;
}

signed main()
{
    init_code();
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}
