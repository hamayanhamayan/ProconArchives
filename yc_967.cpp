//https://yukicoder.me/problems/no/967
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












int A[3], C[3];
//---------------------------------------------------------------------------------------------------
void solve() {
	rep(i, 0, 3) cin >> A[i];
	rep(i, 0, 3) cin >> C[i];

	ll ans = infl;

	vector<int> ord;
	rep(i, 0, 3) ord.push_back(i);
	do {
		if (ord[1] == 1) continue;
		int pre = A[ord[0]];
		ll tot = 0;
		rep(i, 1, 3) {
			int nxt = min(A[ord[i]], pre - 1);
			tot += 1LL * (A[ord[i]] - nxt) * C[ord[i]];
			pre = nxt;
		}
		if (0 < pre) chmin(ans, tot);
	} while (next_permutation(all(ord)));

	if (ans == infl) ans = -1;
	printf("%lld\n", ans);
}
//---------------------------------------------------------------------------------------------------
void _main() {
	int T; cin >> T;
	rep(t, 0, T) solve();
}




/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
1つ前の下位互換の問題での方針ガチャによっては、ちょっと拡張するだけでこの問題が解ける。
（というか、この問題が解ければ、下位互換も同様に解ける）

min,mid,maxを全探索して、かかるコストを計算していこう。
前の解法がわかっていれば、この問題を解くのは難しくないだろう。
数が結構でかいので、long longじゃないとダメ。
///////////////////////// writeup2 end */
