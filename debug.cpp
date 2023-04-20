#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bits/stdc++.h>
#define int long long int
using namespace std;
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

int correct(int a, int b)
{
	return (b - a + 1) % mod;
}
int solve(int a, int b)
{
	memset(dp, -1, sizeof(dp));
        vector<int> va = get(a);
        vector<int> vb = get(b);
        return countNums(0, 18, 1, 1, va, vb);

}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    srand(time(NULL));
    int T = 1000;
    while (T--)
    {
        int a = 1LL * rand() * rand();
	int b = 1LL * rand() * rand();
	if(a > b)
		swap(a, b);
        int correctAns = correct(a, b);
        int myAns = solve(a, b);
        if (correctAns != myAns)
        {
            
            cout << "\ncorrectAns = " << correctAns << ", myAns = " << myAns<< ", a = " << a << ", b = " << b << endl;
            break;
        }
    }
    return 0;
}

