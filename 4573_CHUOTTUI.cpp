// CHUOTTUI

#include <iostream>
using namespace std;
int main()
{
   long long x1, v1, x2, v2;
   cin >> x1 >> v1 >> x2 >> v2;
   if (v1 < v2 || (v1 == v2 && x1 != x2) || (x2 - x1) % (v1 - v2) != 0) cout << "NO";
   else cout << "YES";
   return 0;
}
    