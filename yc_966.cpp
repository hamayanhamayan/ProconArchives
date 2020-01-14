//https://yukicoder.me/problems/no/966
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














int A[3];
//---------------------------------------------------------------------------------------------------
void solve() {
	rep(i, 0, 3) cin >> A[i];

	int ans = inf;

	vector<int> ord;
	rep(i, 0, 3) ord.push_back(i);
	do {
		if (ord[1] == 1) continue;
		int pre = A[ord[0]];
		int tot = 0;
		rep(i, 1, 3) {
			int nxt = min(A[ord[i]], pre - 1);
			tot += A[ord[i]] - nxt;
			pre = nxt;
		}
		if (0 < pre) chmin(ans, tot);
	} while (next_permutation(all(ord)));

	if (ans == inf) ans = -1;
	printf("%d\n", ans);
}
//---------------------------------------------------------------------------------------------------
void _main() {
	int T; cin >> T;
	rep(t, 0, T) solve();
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
3種類の操作があるが、3種類の操作を1つずつ行う操作では、全体の大小関係が変化しないので意味がない。
よって、操作を行う整数の対象は2つ以下である。
max,mid,minを決めてしまえば、midとminを減らすよう操作すればいい。
maxは操作する必要はない。
midはmax-1を目指せばいいし、minはmid-1を目指せばいい。
あとは、Bがmaxかminになる場合だけ考える。

若干方針ガチャな問題。
最適方針を熟考するのが大切。
（自分は根性場合分けを考えて破滅した）
///////////////////////// writeup2 end */
