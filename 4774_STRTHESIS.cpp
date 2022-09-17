// STRTHESIS

#include <iostream>
#include <string>
using namespace std;
int n, open, close, cntopen, cntclose;
string s;

void printno() {
    cout << ":(";
    exit(0);
}

int main() {
    cin >> n >> s;
    for (char c : s) {
        if (c == '(') ++open;
        else if (c == ')') ++close;
    }
    int pos = 1;
    for (char& c : s) {
        if (c == '(') ++cntopen;
        else if (c == ')') ++cntclose;
        else { // c == '?'
            if (open < n / 2) { // spam open
                c = '(';
                ++open, ++cntopen;
            }
            else { // spam close
                c = ')';
                ++close, ++cntclose;
            }
        }

        if (pos++ < n) {
            if (cntopen <= cntclose) printno();
        }
        else {
            if (cntopen != cntclose) printno();
        }
    }
    cout << s;
    return 0;
}
    