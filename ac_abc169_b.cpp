//https://atcoder.jp/contests/abc169/tasks/abc169_b
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
ll mul(ll a, ll b) { if (a == 0) return 0; if (infl / a < b) return infl; return min(infl, a * b); }
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N;
ll MA = 1;
//---------------------------------------------------------------------------------------------------
void _main() {
	rep(i, 0, 18) MA *= 10;

	cin >> N;
	ll tot = 1;
	rep(i, 0, N) {
		ll a; cin >> a;
		tot = mul(tot, a);
	}
	if (MA < tot) cout << "-1" << endl;
	else cout << tot << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
さて、競プロ（の割と変な問題）に慣れている諸君であれば、これは一目見てオーバーフローが気になる所だろう。
このような計算過程に巨大な数が現れる場合の対処には2通りある。

1. 多倍長整数を使う
多倍長整数という言葉がある。
無限（というと語弊があるか）の大きさを整数を扱える整数である。
pythonであれば、普通に整数を作ると、これになるが、C++ではそうではない。
long longを使っても10^18くらいが上限なので、今回のような10^18を何回もかけると上限を超えてしまう。
越えるとどうなるかは整数オーバーフローあたりで調べると、いいだろう。
2の補数表現とかを調べると、まあいいんじゃないかな？
C++でやるのは辛いので、pythonで解こう（実際そうしてる人は割といると思う）

2. 上限付き掛け算を使う
今回の問題のように10^18より大きい場合は、なんでもいいみたいなパターンが出てきたら上限付き掛け算を使うのもいい。
自分はこっちで解いた。
上限（infl）を決めておいて、infl<a*bを満たすならinflを返すようにしてやる。
infl<a*bを満たす判別は浮動小数点を使ってもいいし、logを使ってもいいが、
infl/b<aと変形するのが自分がやってきた中では一番良かった。
結果も安定するし、そんなに遅くない（遅いけどね）。

場合分けで頑張るのもアリだが、どちらの場合でも使えると役立つ場面はあるだろう。
///////////////////////// writeup2 end */
