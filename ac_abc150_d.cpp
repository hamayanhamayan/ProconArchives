//https://atcoder.jp/contests/abc150/tasks/abc150_d
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
ll mul(ll a, ll b) { if (infl / a < b) return infl; return min(infl, a * b); }
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { if (a == infl || b == infl) return infl; return mul(a / gcd(a, b), b); }
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, M, A[101010], B[101010];
//---------------------------------------------------------------------------------------------------
int naive() {
	int ans = 0;
	
	rep(x, 1, M + 1) {
		bool ok = true;
		rep(i, 0, N) {
			if (x % B[i] != 0) ok = false;
			if ((x / B[i]) % 2 == 0) ok = false;
		}
		if (ok) {
			printf(">> %d\n", x);
			ans++;
		}
	}

	return ans;
}
//---------------------------------------------------------------------------------------------------
int solve() {
	ll lc = 1;
	rep(i, 0, N) lc = lcm(lc, B[i]);

	rep(i, 0, N) if ((lc / B[i]) % 2 == 0) return 0;

	ll ans = M / lc;
	ans = (ans + 1) / 2;
	return ans;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, N) cin >> A[i];
	rep(i, 0, N) B[i] = A[i] / 2;

	//cout << naive() << endl;
	cout << solve() << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
式中に小数が出てくるのは面倒なので、小数が出てこないような形にしよう。
A[k]は偶数なので、A[k] = 2 * B[k]とおくと、
X = A[k] * (p + 0.5)
X = B[k] * (2p + 1)
これを見てみると、B[k]の奇数倍の数が作られることになる。
それはいいけど、そこからどうする？

競技プログラミングでアルゴリズムを考えるときに、似てる問題に対するアルゴリズムをもじるという方針がある。
今回でいうと、公倍数を数えるとしたときに、どうやって解くかを考えてみよう。
公倍数は最小公倍数の倍数となるという性質がある。
これだと、全部の数の最小公倍数を取って、M÷最小公倍数をすると答えが得られる。

最小公倍数を計算するには、最大公約数を求めることで求めることができ、
最大公約数はユークリッドの互除法を用いるのが良い。
やり方はネットで解説され尽くされているので、ググって欲しい。

今回の問題も多分これ。
B[k]の最小公倍数を取って、Mで割ればいいが、これだと奇数倍も偶数倍も含まれてしまう。
なので、更に2で割って、切り上げたものが答え。
この辺は入力例を見てエスパーした。

が・・・ダメッ！
冷静にWA数を見てみると、10個くらいWAしている。
経験上、このくらいのWAだったら、コーナーケースっぽいのを踏んでいる感じがする。

実験するが、奇数倍での公倍数を数えていくので、これは愚直解が簡単にかけそう。
これを書く。
書いて実験すると、
2 20
2 4
でダメなことが分かる。
あ、そうか、1,2で公倍数取ると、2になって、2=1*2だから奇数倍にならんのか。
最小公倍数を取ったときに、各B[i]の奇数倍になってることを確認する。
なってないなら、0を答える。
///////////////////////// writeup2 end */
