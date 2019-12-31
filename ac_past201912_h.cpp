//https://atcoder.jp/contests/past201912-open/tasks/past201912_h
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
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, C[201010], Q;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> C[i];
	cin >> Q;

	int offset[2] = { 0, 0 };
	int mi[2] = { inf, inf };
	int cnt[2];

	cnt[1] = N / 2;
	cnt[0] = N - cnt[1];

	rep(i, 0, N) chmin(mi[i % 2], C[i]);

	ll ans = 0;
	rep(_, 0, Q) {
		int t; cin >> t;
		if (t == 1) {
			int x, a; cin >> x >> a; x--;

			if (a <= C[x] - offset[x % 2]) {
				ans += a;
				C[x] -= a;
				chmin(mi[x % 2], C[x]);
			}
		}
		else if (t == 2) {
			int a; cin >> a;

			if (a <= mi[0] - offset[0]) {
				ans += 1LL * a * cnt[0];
				offset[0] += a;
			}
		}
		else {
			int a; cin >> a;
			if (a <= mi[0] - offset[0] and a <= mi[1] - offset[1]) {
				ans += 1LL * a * N;
				offset[0] += a;
				offset[1] += a;
			}
		}
	}

	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
さて、色々な操作があるが、愚直に操作していくと、O(QN)となって間に合わない。
セット販売と全種類販売について工夫して操作をする必要がある。
データ構造力がある場合は遅延評価セグメントツリーを使うと、要求操作をそのまま実現できる。
だが、アルゴリズム技能検定で要求されていることはそういうことではないと思うので、
もっと違った方針で考える。

クエリを実現するには、どういう操作が必要かを考える。
まずは、難しい問題を1つ抽出して、それを解決することで全部解決するよう努めてみよう。
全種類販売は、セット販売と「番号を偶数にした場合の」セット販売が実現できれば、答えられそう。
番号の奇数・偶数は、特に状況の違いは感じられないので、どっちかできていれば良さそう。
なので、「セット販売」が実現できれば良さそう。

この中で大変な部分は、番号が奇数のカードを「a枚ずつ減らす」というのと、「在庫があるかの確認」である。
「a枚ずつ減らす」というのは、全部一律aだけ減らすということであるが、
これは全部でどれだけ減らされているかという値を別に持っておくといい。
offset := 全部で減らされている量
これを更新する。
これを使うと、実際の在庫はC[i]-offset枚となる。
なので、セット販売で減らす操作は、offset += aとすればOK。
「在庫があるかの確認」であるが、これは全部のminを取った時に、minがa以上であるかを判定すればいい。
よって、全体のminを持っておくことにする。
mi := 全体の最小値
offsetも含めて考えると、実際の全体の最小値はmi - offsetとなる。

これでセット販売は問題ない。
単品販売は、C[x] -= aとすれば問題ない。
offsetについては全体の話なので更新の必要は無いが、
miについては更新の可能性があるので、mi = min(mi, C[x])として更新しておく。

全種類販売では、偶数も扱う必要があるので、セット販売で用意したoffsetとmiを偶奇でそれぞれ持っていればいい。
あとは、減った量を数えておいて答える。
///////////////////////// writeup2 end */
