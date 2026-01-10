
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
    string s;
    cin>>s;
    ll ans=0;
    ll n = s.size();
    if(s[0]=='u'){
        s[0] = 's';
        ans++;
    }
    if(s[n-1]=='u'){
        s[n-1] = 's';
        ans++;
    }

    for(ll i=0; i<n-1; i++){
        if(s[i]=='u' && s[i+1]=='u'){
            s[i+1] = 's';
            ans++;
        }
    }

    cout << ans << endl;
}

int main()
{
    int t;cin>>t;while(t--)solve();
}
