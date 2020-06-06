//https://atcoder.jp/contests/past202005-open/tasks/past202005_i
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













int N, Q;
int rows[101010], columns[101010];
bool tenchi = false;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> Q;
	rep(i, 0, N) rows[i] = i;
	rep(i, 0, N) columns[i] = i;

	rep(_, 0, Q) {
		int t; cin >> t;
		if (tenchi) {
			if (t == 1) t = 2;
			else if (t == 2) t = 1;
		}

		if (t == 1) {
			int A, B; cin >> A >> B;
			A--; B--;
			swap(rows[A], rows[B]);
		}
		else if (t == 2) {
			int A, B; cin >> A >> B;
			A--; B--;
			swap(columns[A], columns[B]);
		}
		else if (t == 3) {
			tenchi = !tenchi;
		}
		else {
			int A, B; cin >> A >> B;
			A--; B--;
			if (tenchi) swap(A, B);

			int i = rows[A];
			int j = columns[B];

			ll ans = 1LL * N * i + j;
			printf("%lld\n", ans);
		}
	}
}



/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
難しい問題。
差分を計算するイメージではあるが、情報をいかに圧縮して計算量を減らせるかという問題。

「4 A B」の答えを言いたいときに普通に行列が全てメモリ上にあれば配列のmatrix[A][B]を答えるだけであるが、
これができないということは、何とかして、a[i][j]のi,jを特定する必要があるということになる。
すべてのマスについて(i,j)を書くことはできないので、必然的に行に対して0,1,2,3,...N-1
列に対して0,1,2,3,...,N-1と値を割り当てて置き、あるマスの(i,j)は(i行目に割り当てられた数, j列目に割り当てられた数)となる。
なので、全ての操作をこの、行と列に割り当てられた数に対する操作と考えよう。

rows[i] := i番目の行に割り当てられた数
columns[i] := i番目の列に割り当てられた数
tenchi := 行列が転置されているか

クエリ1: rows[A]とrows[B]をスワップする
クエリ2: columns[A]とcolumns[B]をスワップする
クエリ3: tenchiを反転する
クエリ4: iがrows[A], jがcolumns[B]となるので、それで数を計算

転置を無視して説明したが、転置の場合は、クエリ1,2の場合は行に対する操作が列に対する操作に、
列に対する操作が行に対する操作になってしまう。
なので、転置されている状態であればクエリを入れ替えて対応しよう。
クエリ4で答える場合は、行列が反転しているので、A,Bを反転して与えらている座標の行列も反転させて対応しよう。
///////////////////////// writeup2 end */
