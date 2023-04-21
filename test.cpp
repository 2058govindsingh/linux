//Fri Apr 21 07:31:26 AM EDT 2023
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
int INF = 1e18 + 1e9;
int mod = 1e9 + 7;
int dp[18][2][2];
vector<int> get(int x)
{
	vector<int> res;
	for(int i = 0; i< 18;i++)
	{
		res.push_back(x % 10);
		x /=10;
	}
	reverse(res.begin(), res.end());
	return res;
}
int powMod(int a, int b, int n)
{
    int x = 1, y = a;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x * y) % n;
        }
        y = (y * y) % n;
        b /= 2;
    }
    return x % n;
}

int countNums(int i, int n, int lo, int hi, vector<int> & va, vector<int> &vb)
{
	if(i == n)
		return 1;
	if(dp[i][lo][hi] != -1)
		return dp[i][lo][hi];
	if(lo && hi)
	{
		if(va[i] == vb[i])
		{
			return dp[i][lo][hi] = countNums(i + 1, n, lo, hi, va, vb);
		}
		int count = countNums(i + 1, n, 1, 0, va, vb);
		count += countNums(i + 1, n, 0, 1, va, vb);
		for(int j = va[i] + 1; j <= vb[i] - 1;j++)
		{
			count += countNums(i + 1, n, 0, 0, va, vb);
		}
		return dp[i][lo][hi] = count % mod;
	}
	if(lo)
	{
		int count = countNums(i + 1, n, 1, 0, va, vb);
		for(int j = va[i] + 1; j <= 9; j++)
		{
			count += countNums(i + 1, n, 0, 0, va, vb);
		}
		return dp[i][lo][hi] = count % mod;
	}
	if(hi)
	{
		int count = countNums(i + 1, n, 0, 1, va, vb);
		for(int j = 0; j <= vb[i] - 1; j++)
		{
			count += countNums(i + 1, n, 0, 0, va, vb);
		}
		return dp[i][lo][hi] = count % mod;
	}
	int count = powMod(10, n - i, mod);
	return dp[i][lo][hi] = count;

}	
signed main()
{
	fast_io;
	int a, b;
	cin >> a >> b;
	memset(dp, -1, sizeof(dp));
	int res = 0;
	vector<int> va = get(a);
	vector<int> vb = get(b);
	cout << countNums(0, 18, 1, 1, va, vb);
	return 0;
}
