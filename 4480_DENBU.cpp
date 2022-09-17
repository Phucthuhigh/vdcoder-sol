// DENBU

#include <iostream>
using namespace std;
int main()
{
   long long a, b, c, m, n, k;
   cin >> a >> b >> c >> m >> n >> k;
   n = n - m - k;
   cout << m * a + k * b + n * c;
   return 0;
}
    