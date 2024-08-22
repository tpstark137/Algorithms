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
int queens[20];
// place and unplace in col
bool check(int level, int col)
{
    for (int i = 0; i < level; i++)
    {
        int pCol = queens[i];
        int pRow = i;
        if (pCol == col || abs(col - pCol) == abs(pRow - level))
        {
            return 0;
        }
    }
    return 1;
}
int rec(int level)
{
    // returns the number of ways to place queens in nXn board
    if (level == n) // base case
        return 1;   // when we reached last level -> means we have placed all queens in nxn board
    int ans = 0;
    // choices
    for (int col = 0; col < n; col++)
    {
        // check
        if (check(level, col) == 1)
        {
            queens[level] = col;
            // other queens not attacking so place on the board and move forward
            ans += rec(level + 1);
            // revert back the prev. state
            queens[level] = -1;
        }
    }
    // return
    return ans;
}

void solve()
{
    cin >> n;
    memset(queens, -1, sizeof(queens));
    cout << rec(0);
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
