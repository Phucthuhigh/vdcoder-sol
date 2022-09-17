// SBIGNUM

#include <iostream>
#include <string>
using namespace std;
int main()
{
   string a, b;
   int carry = 0, tmp;
   cin >> a >> b;
   while (a.size() < b.size()) a = '0' + a;
   while (b.size() < a.size()) b = '0' + b;
   for (long i = a.size() - 1; i >= 0; --i)
   {
      tmp = a[i] - '0' + b[i] - '0' + carry;
      carry = tmp / 10;
      a[i] = (tmp % 10) + '0';
   }
   if (carry) a = '1' + a;
   cout << a;
   return 0;
}
    