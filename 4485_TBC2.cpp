// TBC2

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   long long a, b;
   cin >> a;
   for (long i = 0; i < 3; ++i)
   {
   	cin >> b;
   	a = a + b;
   }
   cout << setprecision(2) << fixed << double(a) / 4;
   return 0;
}
    