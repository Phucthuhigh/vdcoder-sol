// kilucdiem

#include <iostream>
#include <string>
using namespace std;
void xuat(string s)
{
	while (s.back() >= '0' && s.back() <= '9') s.pop_back();
	cout << s;
}
int main()
{
   long long n, maxd, tmpd;
   string maxname, tname;
   
   cin >> n;
   
   getline(cin, maxname, '.'); cin >> maxd;
   if (maxname[maxname.size() - 2] == '1') { xuat(maxname); return 0; }
   maxd += (maxname.back() - '0') * 10;
   
   for (long i = 1; i < n; ++i)
   {
   	getline(cin, tname, '.'); cin >> tmpd;
   	if (tname[tname.size() - 2] == '1') { xuat(tname); return 0; }
   	tmpd += (tname.back() - '0') * 10;
   	if (maxd < tmpd)
   	{
   		maxd = tmpd;
   		maxname = tname;
   	}
   }
   xuat(maxname);
   return 0;
}
    