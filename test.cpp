//Sat Apr 22 06:21:20 PM EDT 2023
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
int INF = 1e18 + 1e9;
int dp[10001][2][2][101];
int mod = 1e9 + 7;
int countWays(int n, int lo, int hi, int val, string &a, string &b, int d)
{
	if(n == a.size())
		return val == 0;
	if(dp[n][lo][hi][val] != -1)
		return dp[n][lo][hi][val];
	int count = 0;
	if(lo && hi)
	{
		if(a[n] == b[n])
			return dp[n][lo][hi][val] = countWays(n + 1, lo, hi, (val + a[n] - '0') % d, a, b, d);
		for(char i = a[n]; i <= b[n]; i++)
		{

			if(i == a[n])
				count += countWays(n + 1, lo, 0, (val + i - '0') % d, a, b, d);
			else if(i == b[n])
				count += countWays(n + 1, 0, hi, (val + i - '0') % d, a, b, d);
			else
				count += countWays(n + 1, 0, 0, (val + i - '0') % d, a, b, d); 
		}	
		return dp[n][lo][hi][val] = count % mod;
	}
	if(lo)
	{
		count += countWays(n + 1, lo, 0, (val + a[n] - '0') % d, a, b, d);
		for(char i = a[n] + 1; i <= '9'; i++)
		{
			count += countWays(n + 1, 0, 0, (val + i - '0') % d, a, b, d); 
		}
		return dp[n][lo][hi][val] = count % mod;
	}
	if(hi)
	{
		count += countWays(n + 1, 0, hi, (val + b[n] - '0') % d, a, b, d);
		for(char i = '0'; i <= b[n] - 1; i++)
			count += countWays(n + 1, 0, 0, (val + i - '0') % d, a, b, d);
		return dp[n][lo][hi][val] = count % mod;
	}
	for(char i = '0'; i <= '9'; i++)
		count += countWays(n + 1, 0, 0, (val + i - '0') % d, a, b, d);

	return dp[n][lo][hi][val] = count % mod;
}	
signed main()
{
	fast_io;
	string b;
	int d;
	memset(dp, -1, sizeof(dp));
	cin >> b >> d;
	int n = b.size();
	string a(n, '0');
	a[n-1] = '1';
	cout << countWays(0, 1, 1, 0, a, b, d);

	return 0;
}
