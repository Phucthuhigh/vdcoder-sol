// FINDBADMIN

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
string s;
vector<pair<int,int>> ans;
int dps[100010],dpm[100010],n;
int add(int t)
{
    int i = 1 , swin = 0 , mwin = 0 , cnt1 , cnt2 , lastwin = 0;
    while (i <= n)
    {
        int d = i , c = n , vt = -1;
        while (d <= c)
        {
            int mid = (d+c)/2;
            cnt1 = dps[mid] - dps[i-1];
            cnt2 = dpm[mid] - dpm[i-1];
            if (cnt1 >= t || cnt2 >= t)
            {
                vt = mid;
                c = mid - 1;
            }
            else d = mid + 1;
        }
        if (vt == -1) return 0;
        cnt1 = dps[vt] - dps[i-1];
        if (cnt1 >= t) swin++ , lastwin = 1; else mwin++ , lastwin = 2;
        i = vt + 1;
    }
    if (swin > mwin && lastwin == 2) return 0;
    if (swin < mwin && lastwin == 1) return 0;
    if (swin == mwin) return 0;
    return max(swin , mwin);
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    s = "!" + s;
    for (int i=1; i<=n; i++)
    {
        if (s[i] == 'S') dps[i] = dps[i-1]+1; else dps[i] = dps[i-1];
        if (s[i] == 'M') dpm[i] = dpm[i-1]+1; else dpm[i] = dpm[i-1];
    }
    for (int i=1; i<=n; i++)
    {
        int g = add(i);
        if (g > 0) ans.push_back({g,i});
    }
    sort(ans.begin(),ans.end());
    if (ans.size() == 0) cout << "ERROR"; else
        for (auto x:ans)
            cout << x.first << " " << x.second <<"\n";
    return 0;
}
    