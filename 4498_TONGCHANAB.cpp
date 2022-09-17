// TONGCHANAB

#include <iostream>
using namespace std;
int main()
{
   long long a, b, sum = 0;
   cin >> a >> b;
   for (long long i = (a + 1) / 2 * 2; i <= b; i += 2) sum += i;
   cout << sum;
   return 0;
}
    