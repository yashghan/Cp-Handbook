
#include <bits/stdc++.h>
 
using namespace std;
 
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);              \
    cout.precision(numeric_limits<double>::max_digits10);
#define int long long
 
const int M = 1e9 + 7;

//Calculationg modulo power
int powm(int x, int n)
{
    x %= M;
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    int p = powm(x * x, n / 2);
    if (n % 2)
        return p * x % M;
    else
        return p;
}

//Calculation of mod division
int mod_div(int p, int q) { 
  return p % M * powm(q, M - 2) % M; 
}
 
vector<int> fact;
int N = 1e6;
 
int ncr(int n, int r)
{
    if (r > n)
        return 0;
    return mod_div(fact[n], fact[n - r] * fact[r]);
}
 
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int c1 = count(a.begin(), a.end(), 1LL);
    int c0 = n - c1;
    int k1 = k / 2 + 1;
    if (c1 < k1)
    {
        cout << "0\n";
        return;
    }
    int ans = 0;
    for (int i = k1; i < min(k, c1) + 1; i++)
    {
        ans = (ans + ncr(c1, i) * ncr(c0, k - i) % M) % M;
    }
    cout << ans << '\n';
}
 
int32_t main()
{
    fastIO;
 
    fact.assign(N, 1);
  
    //Precalculating Factorial
    for (int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % M;
    }
    
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
