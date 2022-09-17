// STRXOAYVG

#include <iostream>
#include <string>
using namespace std;
long abs(long k)
{
	if (k > 0) return k;
	return -k;
}
int main()
{
   string s;
   long long sum = 0;
   cin >> s;
   s = 'a' + s;
   for (long i = 1, tmp; i < s.size(); ++i)
   {
   	tmp = abs(s[i] - s[i - 1]);
   	if (tmp > 13) sum = sum + 26 - tmp;
   	else sum += tmp;
   }
   cout << sum;
   return 0;
}
    