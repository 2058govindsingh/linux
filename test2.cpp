//Sat Apr 22 06:21:20 PM EDT 2023
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
int INF = 1e18 + 1e9;
int dp[18][2][2];
int mod = 1e9 + 7;
vector<int> a, b;
int lenA, lenB;
int x= 0;
int rec(int idx, int lo, int hi)
{
	if(idx == lenB)
	{
		cout << x<<"\n";	
		return 1;
	}
	if(dp[idx][lo][hi] == -1)
	{
		int l = 0, r = 9;
		if(lo)
			l = a[idx];
		if(hi) 
			r = b[idx];
		int count = 0;
		for(int i = l; i <= r; i++)
		{
			if(idx % 2 != i % 2 || (lo  &&  idx <= lenB - lenA - 1))
			{
				x = x * 10 + i;
				count += rec(idx + 1, lo ? i == a[idx] : 0, hi ? i == b[idx] : 0);
				x -= i;
				x /= 10;
			}
		}
		dp[idx][lo][hi] = count % mod;
	}
	return dp[idx][lo][hi];
}
signed main()
{
	fast_io;
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		int l, r;
		memset(dp, -1, sizeof(dp));
		cin >> l >> r;
		a.clear();
		b.clear();
		r = min(r, (int)1e18 - 1);
		while(r)
		{
			b.push_back(r % 10);
			r /= 10;
		}
		while(l)
		{
			a.push_back(l % 10);
			l /= 10;
		}
		lenA = a.size(), lenB = b.size();
		int extra = b.size() - a.size();
		while(extra--) a.push_back(0);
		reverse(b.begin(), b.end());
		reverse(a.begin(), a.end());
		cout << "Case #"<< t << ": "<<rec(0, 1, 1) <<'\n';
	}	
	return 0;
}

