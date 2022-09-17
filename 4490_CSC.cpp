// CSC

#include <iostream>
using namespace std;
int main()
{
   long long m, n, k;
   cin >> m >> n >> k;
   if (n - m == k - n) cout << m + n + k;
   else cout << "KHONG PHAI CAP SO CONG";
   return 0;
}
    