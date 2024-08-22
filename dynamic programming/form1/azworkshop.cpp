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
int taken[1001];
int t[1001];
int s[1001];
int x, k;

// place and unplace in col
bool check(int level)
{
    int timetaken = 0, itemtaken = 0;
    for (int i = 0; i < level; i++)
    {
        if (taken[i])
        {
            timetaken += t[i];
            itemtaken++;
        }
    }
    timetaken += t[level];
    itemtaken++;
    if (timetaken <= x && itemtaken <= k)
        return 1;
    return 0;
}
int rec(int level)
{
    if (level == n)
    {
        return 0;
    }
    int ans = rec(level + 1);
    if (check(level))
    {
        // take this skill
        taken[level] = 1;
        // move to next level
        ans = max(ans, rec(level + 1) + s[level]);
        // backtrack-> revert the original state
        taken[level] = -1;
    }
    return ans;
}

void solve()
{
    cin >> n;
    memset(taken, -1, sizeof(taken));
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
