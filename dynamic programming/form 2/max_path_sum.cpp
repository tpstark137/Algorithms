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
int n, m;
int arr[1001][1001];
int dp[1001][1001];
int rec(int row, int col)
{
    // pruning case
    if (row < 0 || col < 0)
    {
        return -1e9;
    }
    // base case
    if (row == 0 && col == 0)
    {
        return arr[0][0];
    }
    // cache check
    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }
    // compute
    int ans = -1e9;
    if (row)
    {
        ans = max(ans, arr[row - 1][col] + arr[row][col]);
    }
    if (col)
    {
        ans = max(ans, arr[row][col - 1] + arr[row][col]);
    }
    return dp[row][col] = ans;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(n - 1, m - 1);
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
