// MIMA

#include <iostream>
#include <vector>
using namespace std;
vector <long long> a;
int main()
{
   long long n;
   cin >> n;
   a.resize(n);
   cin >> a[0];
   long long min = a[0], max = a[0];
   for (long long i = 1; i < n; ++i)
   {
      cin >> a[i];
      if (min > a[i]) min = a[i];
      if (max < a[i]) max = a[i];
   }
   cout << "SO LON NHAT: " << max << "\nSO BE NHAT: " << min;
   return 0;
}
    