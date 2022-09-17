// DADD

#include <iostream>
using namespace std;
int main()
{
   long long n, demd = 0;
   cin >> n;
   for (long long i = 0, tmp; i < n; ++i)
   {
      cin >> tmp;
      if (tmp > 0) ++demd;
   }
   cout << "SO DUONG: " << demd << "\nSO AM: " << n - demd;
   return 0;
}
    