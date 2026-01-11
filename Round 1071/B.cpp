
#include<bits/stdc++.h>
using namespace std;
#define gcd __gcd
#define ll long long

const ll MOD = 998244353;

int power(int base, int pwr){
	int res = 1;
	//pwr = MOD - 2 // if inverse power
	while(pwr){
		if (pwr % 2){
			res = (res * base) % MOD;
		}
		pwr >>= 1;
		base = (base * base) % MOD;
	}
	return res;
}

int factorial(int n){
	int res = 1;
	for(int i=1; i<=n; i++){
		res = (res*i) % MOD;
	}

	return res;
}


bool prime(ll n)
{
    if(n<2)return false;
    else if(n==2)return true;
    else if(n%2==0){
        return false;
    }
    else{
        for(ll i=3; i<=sqrt(n); i+=2){
            if(n%i==0)return false;
        }
    }
    return true;
}

vector<ll> prime_factor(ll x){
    vector<ll> pf;
    for(ll i=2; i*i<=x; i++){
        while(x % i == 0){
            pf.push_back(i);
            x = x/i;
        }
    }
    if(x>1)pf.push_back(x);
    return pf;
}


void solve()
{
    ll n;
    cin>>n;
    ll a[n+1];
    for(ll i=1; i<=n; i++)cin>>a[i];
    ll b[n+1];
    for(ll i=1; i<n; i++) b[i] = abs(a[i]-a[i+1]);
    ll sm=0;
    for(ll i=1; i<n;i++)sm += b[i];
    ll ans = LLONG_MAX;
    for(ll i=2; i<n; i++){
        ll x = sm - b[i] - b[i-1];
        x += abs(a[i+1]-a[i-1]);
        ans = min(ans, x);
    }
    ans = min(ans, sm-b[1]);
    ans = min(ans, sm-b[n-1]);
    cout << ans << endl;
}

int main()
{
    int t;cin>>t;while(t--)solve();
}
