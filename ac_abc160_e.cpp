//https://atcoder.jp/contests/abc160/tasks/abc160_e
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














int X, Y, A, B, C;
int p[101010], q[101010], r[101010];
ll smpq[201010];
ll smr[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> X >> Y >> A >> B >> C;
	rep(i, 0, A) cin >> p[i];
	rep(i, 0, B) cin >> q[i];
	rep(i, 0, C) cin >> r[i];

	vector<int> pq;
	sort(p, p + A, greater<int>());
	rep(i, 0, X) pq.push_back(p[i]);
	sort(q, q + B, greater<int>());
	rep(i, 0, Y) pq.push_back(q[i]);
	sort(all(pq), greater<int>());

	smpq[0] = 0;
	rep(i, 0, X + Y) smpq[i + 1] = smpq[i] + pq[i];

	sort(r, r + C, greater<int>());
	smr[0] = 0;
	rep(i, 0, C) smr[i + 1] = smr[i] + r[i];

	ll ans = 0;
	rep(c, 0, min(C, X + Y) + 1) chmax(ans, smr[c] + smpq[X + Y - c]);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
̖今回の問題では、2種類の取り組み方をブレンドして解く。
C個の無色のリンゴの中で使う個数を「全探索」し、そのパターンで「貪欲」にリンゴを選んでいき、答えを求めることにする。

無色のリンゴの中でc個のリンゴを着色して食べることとする。
このc個のリンゴは色にかかわらず食べるので、全部美味しさの総和に足されることになる。
そして、ここで選ばれるc個のリンゴはおいしいものから選んでいけばいい。
事前に「smr[c] := 無色のリンゴを美味しさが高いものからc個選んだときの総和」を計算しておけば効率よく求められる。

あとは、残りのX+Y-c個のリンゴを赤色と緑色から選んでいく。
だが、これも貪欲に美味しさが高いものから選べばいい。
注意点として赤色のリンゴをX個を超えては取れないし、緑色も同様である。
よって、赤色のリンゴを大きいものからX個選択し、緑色のリンゴも大きいものからY個選択し、降順ソートしておく。
これで「smpq[c] := 赤緑のリンゴを美味しさが高いものから、赤緑の個数制限を超えないようにc個選んだ時の総和」を作っておけば、効率よく計算可能。

この2つの配列ができたら、後は無色のリンゴを使う個数を全探索して、最適解を計算すれば答え。
///////////////////////// writeup2 end */
