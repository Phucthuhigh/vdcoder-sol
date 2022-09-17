// NTHDIVISI

#include <iostream> 
using namespace std;

// Function to return 
// gcd of a and b 
long long gcd(long long a, long long b)
{
	if (a == 0)
		return b;

	return gcd(b % a, a);
}

// Function to calculate how many numbers 
// from 1 to num are divisible by a or b 
long long divTermCount(long long a, long long b, long long lcm, long long num)
{
	// calculate number of terms divisible by a and 
	// by b then, remove the terms which is are 
	// divisible by both a and b 
	return num / a + num / b - num / lcm;
}

// Binary search to find the nth term 
// divisible by a or b 
long long findNthTerm(long long a, long long b, long long n)
{
	// set low to 1 and high to max(a, b)*n, here 
	// we have taken high as 10^18 
	long long low = 1, high = 1000000000000000000, mid;
	long long lcm = (a * b) / gcd(a, b);

	while (low < high) {
		mid = low + (high - low) / 2;

		// if the current term is less than 
		// n then we need to increase low 
		// to mid + 1 
		if (divTermCount(a, b, lcm, mid) < n)
			low = mid + 1;

		// if current term is greater than equal to 
		// n then high = mid 
		else
			high = mid;
	}

	return low;
}

// Driver code 
int main()
{
	long long a, b, n;
	cin >> a >> b >> n;
	cout << findNthTerm(a, b, n) << endl;

	return 0;
}
    