// BTKCUTPAL

#include <iostream>
#include <algorithm>
using namespace std;
string str;
int n;
bool palind[40][40];
void buildPalind()
{
    for (int i = 1; i <= n; ++i) palind[i][i] = true;
    for (int i = 1; i < n; ++i)
        if (str[i] == str[i + 1]) palind[i][i + 1] = true;
    for (int len = 3; len <= n; ++len)
        for (int l = 1, r = len; r <= n; ++l, ++r)
            if (str[l] == str[r]) palind[l][r] = palind[l + 1][r - 1];
}

void Try(int i, string s)
{
    if (i > n)
    {
        cout << s << '\n';
        return;
    }

    for (int j = i; j <= n; ++j)
    {
        if (palind[i][j])
        {
            string t(s);
            for (int k = i; k <= j; ++k) t += str[k];
            t += ' ';
            Try(j + 1, t);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> str; n = str.size(); str = " " + str;
    buildPalind();
    Try(1, "");
    return 0;
}
    