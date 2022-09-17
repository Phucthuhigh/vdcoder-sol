// STRPERIO

/// Monarchuwu
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int l;
string a;

bool full9() {
    for (char c : a) if (c < '9') return false;
    return true;
}

bool type() {
    for (int i = l; i < a.size(); ++i) {
        if (a[i] > a[i % l]) return true;
        if (a[i] < a[i % l]) return false;
    }
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> l >> a;
    if (a.size() % l != 0 || full9()) {
        int k = a.size() / l + 1;
        while (k-- > 0) {
            cout << 1;
            for (int i = 1; i < l; ++i) cout << 0;
        }
    }
    else {
        if (type()) {
            for (int i = l - 1; i >= 0; --i) {
                if (a[i] == '9') a[i] = '0';
                else {
                    ++a[i];
                    break;
                }
            }
        }
        for (int i = 0; i < a.size(); ++i) cout << a[i % l];
    }
    return 0;
}
    