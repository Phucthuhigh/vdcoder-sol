// STRSUBEVEN

#include <iostream>
#include <string>
using namespace std;
int main()
{
   string s;
   long long sum = 0;
   cin >> s;
   for (long i = 0; i < s.size(); ++i)
   {
	if (s[i] % 2 == 0) sum = sum + i + 1;
   }
   cout << sum;
   return 0;
}
    