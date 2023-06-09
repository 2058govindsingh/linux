//Tue Apr 25 10:51:41 AM EDT 2023
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
int INF = 1e18 + 1e9;
int dp[18][2][2][18];
int mod = 1e9 + 7;
vector<int> a, b;
int lenA, lenB;
int x = 0;
int rec(int idx, int lo, int hi, int first)
{
	if(idx == lenB)
	{
		//cout << x <<"\n";	
		return 1;
	}
	if(dp[idx][lo][hi][first] == -1)
	{
		int l = 0, r = 9;
		if(lo)
			l = a[idx];
		if(hi) 
			r = b[idx];
		int count = 0;
		int nl = l, nr = r;
		if(idx < first)
		{
			r = 0;		
		}
		for(int i = l; i <= r; i++)
		{
			if(idx >= first && (abs(idx - first + 1 - i) % 2 == 1))
				continue;
			{
				//x = x * 10 + i;
				count += rec(idx + 1, lo ? i == nl : 0, hi ? i == nr: 0, first);
				//x -= i;
				//x/= 10;
			}
		}
		dp[idx][lo][hi][first] = count;
	}
	return dp[idx][lo][hi][first] ;
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
		l = min(l, (int)1e18 - 1);
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
		while(extra-- > 0) a.push_back(0);
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int res = 0;
		for(int i = 0; i < lenB;i ++)
		{
			res += rec(0, 1, 1, i);
		}
		cout << "Case #"<< t << ": "<<res <<'\n';	
	}	
	return 0;
}
