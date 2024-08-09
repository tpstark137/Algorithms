/*
Problem: Match the pattern P in given string T
In Naive approach we are incrementing window by single step TC: O(N*M)
In Kmp Algorithm we are shifting by k steps TC:O(N+M)
Step1: Build Prefix Table
Step2: Match the pattern
*/
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

void solve()
{
    int n;
    string s;
    cin >> n;
    cin >> s;

    int lps[n + 1];
    int i = 0, j = -1;
    lps[0] = -1; // representing empty lps
    while (i < n)
    {
        while (j != -1 && s[j] != s[i])
            j = lps[j]; // backtrack till find perfect match
        // increment the pointers when found the perfect match
        i++;
        j++;
        lps[i] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << lps[i] << " ";
    }
    cout << endl;
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

/*
Author : Tusshar Paul
*/