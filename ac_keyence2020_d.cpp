//https://atcoder.jp/contests/keyence2020/tasks/keyence2020_d
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














int N, AB[18][2];
int dp[1 << 18][51];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> AB[i][0];
	rep(i, 0, N) cin >> AB[i][1];

	rep(msk, 0, 1 << N) rep(lst, 0, 51) dp[msk][lst] = inf;

	dp[0][0] = 0;
	rep(msk, 0, 1 << N) rep(lst, 0, 51) if (dp[msk][lst] != inf) {
		int done = 0;
		rep(i, 0, N) if (msk & (1 << i)) done++;

		rep(i, 0, N) {
			if (msk & (1 << i)) continue;

			int p = abs(done - i) % 2;
			if (AB[i][p] < lst) continue;

			int c = 0;
			rep(j, 0, i) if (!(msk & (1 << j))) c++;

			chmin(dp[msk | (1 << i)][AB[i][p]], dp[msk][lst] + c);
		}
	}

	int ans = inf;
	rep(lst, 0, 51) chmin(ans, dp[(1 << N) - 1][lst]);

	if (ans == inf) ans = -1;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [BitDP](https://www.hamayanhamayan.com/entry/2017/07/16/130151)
///////////////////////// writeup2 start
とある性質がある。
「位置が1だけずれると同時に裏返されるため、位置と色のパリティ（2で割った余り）は必ず一致するか、必ず異なる」
つまり、0,2,4番目にあるカードは0,2,4では赤であるが、1,3,5では青になる。
そして、これが満たされれば操作によって、その位置を実現できる。

制約からBitDP感が伝わってくるので、その方針で考えるといける。
以下、0-indexedで考える。

dp[msk][lst] := 既に整列済みの集合がmskで、最後の値がlstであるときの操作の最小値
これで、未選択のi番目のカードを列の末尾に追加することを考える。
既にdone枚選択されている場合、done番目に追加されることになる。
もともとi番目にあるので、abs(i - done)が位置の差となる。
このパリティが0であれば、赤が表になっていて、1であれば青が表になっている。
赤青が分かるということは数が確定するということである。
末尾はlstであるので、これ未満であれば置くことはできない。
さて、おける時に、操作の回数はどうなるだろうか。
今回も問題はバブルソートと実はほぼ同じである。
バブルソートでは転置数の総和が最小総和回数である。
よって、今の段階での転置数を見よう。
i番目より前のカードについて（元々前にある）、選択されていない（その数より大きい位置に置かれる予定）ものの数が転置数である。
これを愚直に数える。

セオリー通りに計算量解析すると、O(2^N N^3)であり、厳しい気もするが、
DP更新時に更新元がINFであれば計算しないなどの枝刈りを行うと通る。
///////////////////////// writeup2 end */
