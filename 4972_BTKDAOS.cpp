// BTKDAOS

#include <iostream>
#include <set>
#include <string>

using namespace std;

long n, dem = 0;
string a, b;
bool check[9] = { 1,1,1,1,1,1,1,1,1 };
set<string> res;

void btk()
{
    if (b.size() == n) res.insert(b);
    else
    {
        for (long i = 0; i < n; ++i)
        {
            if (check[i])
            {
                b += a[i];
                check[i] = false;

                btk();
                
                b.pop_back();
                check[i] = true;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin >> a;
    n = a.size();
    btk();

    cout << res.size();
    for (set<string>::iterator i = res.begin(); i != res.end(); ++i)
        cout << '\n' << *i;
}
    