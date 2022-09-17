// KEBAN

#include <iostream>
using namespace std;
long long abs(long long a)
{
   if (a > 0) return a;
   else return -a;
}
int main()
{
   long long a, b, tmp = 1, dem = 0;
   cin >> a >> b;
   while (tmp * a < b) {tmp *= 2; ++dem; };
   if (tmp * a == b) cout << dem;
   else cout << dem - 1;
   return 0;
}
    