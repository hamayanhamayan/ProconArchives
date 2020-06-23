//https://atcoder.jp/contests/abc171/tasks/abc171_d
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














int N, A[101010], Q;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	map<int, int> cnt;
	ll tot = 0;
	rep(i, 0, N) {
		cnt[A[i]]++;
		tot += A[i];
	}

	cin >> Q;
	rep(_, 0, Q) {
		int B, C; cin >> B >> C;

		tot += 1LL * (C - B) * cnt[B];
		cnt[C] += cnt[B];
		cnt[B] = 0;

		printf("%lld\n", tot);
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
高速シミュレーションを行う。
クエリ問題で毎回操作後の総和を答える必要があるが、差分だけ計算することで高速に求めよう。
B[i]である全ての要素についてC[i]に変更するが、普通にやると間に合わないので、
個数を保持しておくことにしよう。
順番は特に関係ないので、
cnt[x] := 値がxである要素の個数
という配列を使えば、値がBである要素すべてをCに置き換える操作は、
cnt[C] += cnt[B]
cnt[B] = 0
という風に言い換えることができる。
かつ、総和の差分は、cnt[B]個のBが消えて、cnt[B]個のCが増えるので、
-B * cnt[B] + C * cnt[B] = (C - B) * cnt[B]
となる。
よって、この2つをクエリ毎に行えば、高速に操作と総和計算が行える。
///////////////////////// writeup2 end */
