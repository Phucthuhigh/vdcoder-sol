// DPLAGA1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> f(201, "-1");

string sum(string a, string b)
{
   int carry = 0, tmp;
   while (a.size() < b.size()) a = '0' + a;
   while (b.size() < a.size()) b = '0' + b;
   for (long i = a.size() - 1; i >= 0; --i)
   {
      tmp = a[i] - '0' + b[i] - '0' + carry;
      carry = tmp / 10;
      a[i] = (tmp % 10) + '0';
   }
   if (carry) a = '1' + a;
   return a;
}

string lat_gach(long m)
{
   if (f[m] == "-1") f[m] = sum(lat_gach(m - 1), lat_gach(m - 2));
   return f[m];
}
void set_lat_gach()
{
   f[1] = "1";
   f[2] = "2";
   string tmp = lat_gach(200);
}
int main()
{
   set_lat_gach();
   ios_base::sync_with_stdio(false);
   long t, n;
   cin >> t;
   for (long i = 0; i < t; ++i)
   {
      cin >> n;
      cout << f[n] << '\n';
   }
   return 0;
}
    