#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long 
#define mod 1000000007
#define INF 1e18+7
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace __gnu_pbds;
int  nC2(int n){
    return (n*(n-1))/2;
}
int N=1e7+10;
// vector<bool> isPrime(N, 1);
// void seive()
// {
// 	isPrime[0] = isPrime[1] = 0;
// 	for (int i = 2; i*i <= N; i++)
// 	{
// 		if (isPrime[i])
// 		{
// 			for (int j = i * i; j <= N; j += i)
// 			{
// 				isPrime[j] = 0;
// 			}
// 		}
// 	}
// }
//struct comp {
//     bool operator() (const string& s1, const string& s2) const {
//         for(int i=0;i<min(s1.size(),s2.size());)
//         {
//             if(s1[i]==s2[i]) i++;
//             else return s1[i]<s2[i];
//         }
//         return s1.size()<s2.size();
//     }
// };
class DSU
{
private:
    vector<int> parent,size;
public:
    DSU(int n)
    {
        for(int i=0;i<=n;i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }
public: int findPar(int node)
    {
        if(parent[node]==node) return node;
        return parent[node]=findPar(parent[node]);
    }
public: 
        void Union(int u,int v)
        {
            int pu=findPar(u);
            int pv=findPar(v);
            if(pu==pv) return ;
            if(size[pu]<size[pv])
            {
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
            else
            {
                parent[pv]=parent[pu];
                size[pu]+=size[pv];
            }
        }
};
int ub(vector<int> &v,int low,int high, int target)
{
    //int low = 0, high = v.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }
    if (ans == -1)
        return -1;
    return ans;
}
int lb(vector<int> &v,int low,int high, int target)
{
    //int low = 0, high = v.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] < target)
        {
            low=mid+1;
        }
        else
        {
            ans = mid;
            high=mid-1;
        }
    }
    if (ans == -1)
        return -1;
    return ans;
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
int cbrtt(int n)
{
    int low = 1, high = cbrt(LLONG_MAX), mid;
    int ans = low;
    while(high>=low)
    {
        mid = (low+high)/2;
        if(mid*mid*mid<=n)
        {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}
int lcm(int a, int b) { return a * b / __gcd(a, b); }
int check_ps(int n)
{
    double sqrt_n = sqrt(n);
    if (sqrt_n == (int)(sqrt_n))
    {
        return 1;
    }
    return 0;
}
int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 

    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
 

int modInverse(int b, int m)
{
    int x, y; 
    int g = gcdExtended(b, m, &x, &y);
 
    if (g != 1)
        return -1;
 
    return (x%m + m) % m;
}
 
int modDivide(int a, int b, int m)
{
    a = a % m;
    int inv = modInverse(b, m);
    return (1LL* inv * a) % m;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdin);
#endif
	fast_io
	int T;
	cin>>T;
	while (T--)
	{

	}
    return 0;
}
