// STRKONE2

#include <iostream>
#include <string>

using namespace std;

// Inp
int n, k, pos[1000000], cnt = 1;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin >> k >> s;
    n = s.size();
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '1') pos[cnt++] = i;
    }
    pos[0] = -1;
    pos[cnt] = n;

    long long d = 0;
    for (int l = 1, r = k; r < cnt; ++l, ++r)
    {
        d += 1LL * (pos[l] - pos[l - 1]) * (pos[r + 1] - pos[r]);
    }

    cout << d;

    return 0;
}
    