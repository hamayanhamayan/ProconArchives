//https://yukicoder.me/problems/no/864
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
vector<ll> enumdiv(ll n) {
	vector<ll> S;
	for (ll i = 1; i*i <= n; i++) if (n%i == 0) { S.push_back(i); if (i*i != n) S.push_back(n / i); }
	sort(S.begin(), S.end());
	return S;
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










ll N, K;
//---------------------------------------------------------------------------------------------------
ll get(ll x) {
	if (x <= 1) return 0;
	else if (x <= N + 1) return x - 1;
	else if (x <= 2 * N) return 2 * N + 1 - x;
	else return 0;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;

	auto ed = enumdiv(K);
	ll ans = 0;
	fore(ac, ed) ans += get(ac) * get(K / ac);
	cout << ans << endl;
}






/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
ab + bc + cd + da = Kを変形していく
(ab + da) + (bc + cd) = K
a(b + d) + c(b + d) = K
(a + c)(b + d) = K
となるので、a+c, b+dはKの倍数になる。
なので、Kを2つの積に分解して、aとc, bとdで組み合わせを求めればいい。

あとは、x + y = zであり、1≦x,y≦Nであるx,yの組がわかればいい。
get(z)が条件を満たす組み合わせであるとすると、[1,N]の制約がなければf(z) = z - 1通りである。
z - 1≦Nであるならばすべて条件を満たすし、逆に2N<zであれば条件を満たすものはない。
つまり、
z ≦ N+1ならz-1通り
2N < zなら0通り
N+2≦z≦2Nはわからないが、きっと1個ずつ減るんだろうと仮定すると、
z=2Nなら1なので、2N-z+1であろう。
あとは、z≦1なら0通りなのを追加するとOK
///////////////////////// writeup2 end */	