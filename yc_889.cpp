//https://yukicoder.me/problems/no/889
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
bool isprime(int v) {
	if (v == 1) return false;
	for (int i = 2; 1LL*i*i <= v; i++) if (v%i == 0) return false;
	return true;
}
bool isSquare(ll n) {
    ll d = (ll)sqrt(n) - 1;
    while (d*d < n) ++d;
    return d * d == n;
}
bool isCubic(ll v) {
    ll r = 1;
    while(1LL * r * r * r < v) r++;
    return 1LL * r * r * r == v;
}
vector<ll> enumdiv(ll n) {
	vector<ll> S;
	for (ll i = 1; i*i <= n; i++) if (n%i == 0) { S.push_back(i); if (i*i != n) S.push_back(n / i); }
	sort(S.begin(), S.end());
	return S;
}
bool isPerfectNumber(ll x) {
    if(x <= 0)
        return false;
    auto ed = enumdiv(x);
    ll tot = 0;
    fore(d, ed) if (d != x) tot += d;
    return x == tot;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/

int N;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;

    if (2 <= N and isprime(N)) cout << "Sosu!" << endl;
    else if (2 <= N and isSquare(N)) cout << "Heihosu!" << endl;
    else if (2 <= N and isCubic(N)) cout << "Ripposu!" << endl;
    else if (isPerfectNumber(N)) cout << "Kanzensu!" << endl;
    else cout << N << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
いろいろな種類の数に対する判定をする問題。
こういうものは関数化してライブラリとして持っておこう。
完全数判定なんて、どこで使うかわからないが、いつか役立ったりする。
全部の判定問題は基本的には、 O(sqrt(N))の素数判定を改造したものになる。
///////////////////////// writeup2 end */
