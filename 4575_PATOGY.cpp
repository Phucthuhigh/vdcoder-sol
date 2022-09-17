// PATOGY

#include <iostream>
using namespace std;
int main()
{
   long long a, b, c, tmp;
   cin >> a >> b >> c;
   if (a < b) {tmp = a; a = b; b = tmp; }
   if (a < c) {tmp = a; a = c; c = tmp; }
   if (a * a == b * b + c * c)
      cout << "Ba so da nhap la bo so Pi-ta-go";
   else cout << "Ba so da nhap khong la bo so Pi-ta-go";
   return 0;
}
    