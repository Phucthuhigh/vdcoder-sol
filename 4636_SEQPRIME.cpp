// SEQPRIME

#include <iostream>
//#include <vector>
using namespace std;
bool check[20000];
long n;
void sieve()
{
	for (long long i = 3; i < 20000; i += 2)
		if (!check[i])
		{
			if (n > 0) cout << i << ' ';
			else return;
			--n;
			 for (long long j = i * i; j < 20000; j += 2 * i) check[j] = true;
		}
}
int main()
{
	cin >> n;
	if (n % 2 == 1)
	{
		cout << 2 << ' ';
		--n;
	}
	sieve();
	return 0;
}
    