//https://atcoder.jp/contests/acl1/tasks/acl1_b
#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; using namespace atcoder;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














ll N;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;

	ll ans = infl;
	auto ed = enumdiv(2 * N);
	fore(x, ed) {
		ll y = 2 * N / x;

		vector<ll> r(2), m(2);
		r[0] = 0, m[0] = x;
		r[1] = -1, m[1] = y;

		auto p = crt(r, m);
		if (p.first != 0 && p.second != 0) chmin(ans, p.first);
	}

	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
1h考えてmodのもの字も出てこなかった…
大学受験で出てきそうな問題。

## 言い換え

この言い換えはできた。
(1+2+...+K)=aN
K(K+1)/2=aN
K(K+1)=2aN
これを満たす最小のKが答えになる。

## 約数で分割する

右辺の2aNをKとK+1に分割するようなイメージ。
aは倍数ということで勝手につけたものなので、そこではなく固定されている2Nを起点に考える。
2Nを素因数分解したときに、その素因数がKとK+1に分かれることになる。
どのように分かれるかというのはわからないので、ここは全探索することにしよう。
実際は素因数というより約数で考える方がスムーズ。
2Nの約数xがKに属する、もう片方のy=2N/xがK+1に属すると考える。

だが、注意するべきなのは、「属する」というのは倍数になるという部分である。
結局、倍数じゃないか。なんとかならないか。

## modで考える

さっきのように変数aを使うのではなく、modを使って倍数を対処しよう。

Kがxの倍数であるというのは、K=0 (mod x)と考えることができる。
modが分かれば何となく分かるだろう。
K+1がyの倍数であるというのは、K+1=0 (mod y)と考えることができる。
公式解説ではK=-1 (mod y)とされている。

これで2つの合同式が得られた訳だが、合同式から元の数を復元する方法がある。
CRTだ。

## CRT

中国人剰余定理の頭文字。
内容については、ググってもらうことにして、2つの合同式があれば、変数の値を復元できる。
よって、
K=0 (mod x)
K=-1 (mod y)
が分かっていれば、Kの値がmod xyで分かる。
[中国の剰余定理 - Wikipedia](https://ja.wikipedia.org/wiki/%E4%B8%AD%E5%9B%BD%E3%81%AE%E5%89%B0%E4%BD%99%E5%AE%9A%E7%90%86)
ここの補助定理にもあるようにx,yが互いに素であれば一意に存在する。
今回の全探索では互いに素でないパターンも試すことになるが、解がうまく出せないだけで、
全パターンの中に互いに素となるものがあるので問題ない。
あと、連続する2つの整数は互いに素であることが言えるので、答えを導けるx,yも互いに素である必要があるってのもある。
///////////////////////// writeup2 end */
