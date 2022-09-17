// PASSW

#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<cmath>
#define ff     first
#define ss     second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 300;
int k;
string s;

void del_string() {
    string t("");
    for (char c : s)
        if (isdigit(c)) t.push_back(c);

    int del = (int)t.size() - k;
    s.clear();
    for (char c : t) {
        if (s.empty()) s.push_back(c);
        else {
            while (!s.empty() && del && s.back() < c) {
                --del;
                s.pop_back();
            }
            s.push_back(c);
        }
    }
    while (del--) s.pop_back();
}

bool check() {
    int l(0), r(s.size() - 1);
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> k; cin.ignore();
    getline(cin, s);
    del_string();
    cout << s << '\n' << (check() ? "YES" : "NO");
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    