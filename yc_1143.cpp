//https://yukicoder.me/problems/no/1143
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
	for (ll i = 1; i * i <= n; i++) if (n % i == 0) { S.push_back(i); if (i * i != n) S.push_back(n / i); }
	sort(S.begin(), S.end());
	return S;
}
ll mul(ll a, ll b) { if (a == 0) return 0; if (infl / a < b) return infl; return min(infl, a * b); }
template<class... T> ll mul(ll x, T... y) { return mul(x, mul(y...)); }
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
	N = N * N;
	auto v = enumdiv(N);
	int ans = 0;
	int n = v.size();
	rep(a, 0, n) {
		int c = n - 1;
		rep(b, a, n) {
			while (b < c && N < mul(v[a], v[b], v[c], v[a] + v[b] + v[c])) c--;
			if (mul(v[a], v[b], v[c], v[a] + v[b] + v[c]) == N && a <= b && b <= c) ans++;
		}
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [ヘロンの公式](https://www.hamayanhamayan.com/entry/2018/02/27/105814)
- [高度合成数](https://www.hamayanhamayan.com/entry/2017/10/14/125941)
///////////////////////// writeup2 start
あまり見ないような問題。
自分の経験則から言うとあまり見ないような感じだと特殊な公式とか定理を要求しているかもを頭の片隅で考える。
でも、辺の長さとかで全探索するんだろうなぁ…と思いつつ、考えると、
辺の長さと面積といえばヘロンの公式であり、その辺から考えると浮かんでくる。

## ヘロンの公式

これを使う問題は初めて見たかもしれない。
ルートは扱いにくいので二乗してみよう。

S^2 = s(s-a)(s-b)(s-c)

s-a=x, s-b=y, s-c=zとして、変換してみると、

S^2 = xyz(x+y+z)

とすることができ、きれいになる。

## 全探索

これでようやくAtCoderでよく見るような感じになってきた。
x,y,zの候補はS^2の約数である。
これは最大10^12で約数の最大個数は6720個なので、ギリギリ大丈夫かな？という感じ。
実行時間が短いのが気になるが、計算もとても軽いのでやってみる価値はある。

## 注意点

- x,yを全探索するが、zは尺取り法で探索する必要がある。ちゃんとO(約数^2)に収めないと厳しい
- あと、ヘロンの公式をそのまま使うと、オーバーフローするので上限付きmulを使うか、何かしら工夫が必要
- 時間が結構厳しい
	- 下手に時間設定するとO(N^2)の賢い枝刈りとか通りそうだし、厳しいのはそのせいだろう

///////////////////////// writeup2 end */
