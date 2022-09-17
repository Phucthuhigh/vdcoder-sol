// CNTPRIME3

#include <iostream>
#include <cmath>
using namespace std;
long prime[6000000], cntp, a[5], b[5];
bool mark[10007];
void simpleSieve(long limit)
{
	for (long p = 2; p * p < limit; ++p)
	{
		if (!mark[p])
		{
			for (long i = p * p; i < limit; i += p)
			{
				mark[i] = true;
			}
		}
	}
	for (long p = 2; p < limit; ++p)
	{
		if (!mark[p])
		{
			prime[cntp++] = p;
		}
	}
}
void segmentedSieve(long n)
{
	long limit = sqrt(n) + 1;
	simpleSieve(limit);
	long cnt = cntp;
	long low = limit;
	long high = 2 * limit;
	while (low < n)
	{
		if (high > n) high = n + 1;
		
//		vector<bool> mark(limit, true);
		for (long i = 0; i < limit; ++i) mark[i] = true;
		
		for (long i = 0; i < cnt; ++i)
		{
			long loLim = (low / prime[i]) * prime[i];
			
			if (loLim < low) loLim += prime[i];
			
			for (long j = loLim; j < high; j += prime[i])
			{
				mark[j - low] = false;
			}
		}
		for (long i = low; i < high; i++)
			if (mark[i - low])
				prime[cntp++] = i;
//				prime.push_back(i);
		low += limit;
		high += limit;
	}
}
long binsearch(long k)
{
	long l = 0, r = cntp - 1, mid, res = -1;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (prime[mid] == k) return mid;
		if (prime[mid] > k) r = mid - 1;
		else
		{
			res = mid;
			l = mid + 1;
		}
	}
	return res;
}
int main()
{
	long k, maxx = 0;
	cin >> k;
	for (long i = 0; i < k; ++i)
	{
		cin >> a[i] >> b[i];
		if (maxx < b[i]) maxx = b[i];
	}
	segmentedSieve(maxx);
	for (long i = 0; i < k; ++i)
	{
		cout << binsearch(b[i]) - binsearch(a[i] - 1) << '\n';
	}
	return 0;
}
    