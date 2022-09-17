// MAX3

#include <iostream>
using namespace std;
int main()
{
   long long a, b, c;
   cin >> a >> b >> c;
   if (a < b) a = b;
   if (a < c) a = c;
   cout << "So lon nhat: " << a;
   return 0;
}
    