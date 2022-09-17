// RCSUC

#include <iostream>
using namespace std;
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main()
{
   long long a, b;
   cin >> a >> b;
   if (a < b) cout << gcd(b, a);
   else cout << gcd(a, b);
   return 0;
}
    