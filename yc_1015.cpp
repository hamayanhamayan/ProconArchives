//https://yukicoder.me/problems/no/1015
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














int N; int X, Y, Z, A[101010];
//---------------------------------------------------------------------------------------------------
#define yes "Yes"
#define no "No"
string solve() {
	priority_queue<int> que;
	rep(i, 0, N) que.push(A[i] + 1);

	vector<int> yens = { 10000, 5000, 1000 };
	vector<int> cnts = { Z, Y, X };
	rep(_, 0, 3) {
		int yen = yens[_];
		int cnt = cnts[_];

		// ピッタリ使う
		rep(i, 0, N) {
			int q = que.top(); que.pop();
			int use = min(q / yen, cnt);
			cnt -= use;
			que.push(q - use * yen);
		}

		// 残りで値段が高いやつから払っていく
		rep(i, 0, N) {
			int q = que.top(); que.pop();
			if (0 < cnt) cnt--, q = 0;
			que.push(q);
		}
	}

	rep(i, 0, N) {
		int q = que.top();
		if (0 < q) return no;
	}

	return yes;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> X >> Y >> Z;
	rep(i, 0, N) cin >> A[i];
	cout << solve() << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
問題の見た目と★2なので、貪欲方針系だろうというのは分かる。
本番では別の貪欲をしてしまって通せなかった。
（ちゃんと落としてくるのが、さすが、maspyさん+beetさん）

解説にあるようにA[i]円をお釣りありで払うのではなく、A[i]+1円をなるべく少ない枚数で払うとして考える。

さて、解説にある貪欲方法を実践していこう。
大きい値段の札から使うことを考えていく。
例えば1万円札をいつ使うべきかということを考えると、1万円以上の商品については使ってしまっていい。
これは、それより安い札で払うと、細かい値段の商品について、1万円札を使わなくてはいけないからである。
それでも1万円札が残ってしまった場合は、なるべく高い商品に対して1万円札で支払い切ってしまう。

これで1万円札を消化したので、同様のことを5千円札で改めてやる。最後に千円札でやって、全部払い終えていれば答え。
実装は3種類のお札でロジックは同じなので、配列で回していくのがいい。
高い順に処理していくので、priority_queueを使うといい感じだろう。
///////////////////////// writeup2 end */
