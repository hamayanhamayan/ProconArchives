//https://codeforces.com/contest/1305/problem/C
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














int N, M, A[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, N) cin >> A[i];

	if (M < N) {
		cout << 0 << endl;
		return;
	}

	ll ans = 1;
	rep(i, 0, N) rep(j, i + 1, N) {
		ans *= abs(A[i] - A[j]);
		ans %= M;
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [鳩ノ巣原理](https://www.hamayanhamayan.com/entry/2017/10/14/125941)
///////////////////////// writeup2 start
天才的なひらめきを要する問題。
それがないと、modで個数分けして数え上げてみようだとか、絶対値をなんとかして取り外して分解？？だとか
爆発解法に走ってしまう（私です）。
ですが、まだC問題ということでちょっとやばそう、かつ順位表を見ても爆速解法が乱発しているので、
これはひらめきが求められている。

解法を説明する。
答えはmod Mで要求されているので、すべての計算はmod Mでやればいい。
配列Aもmod Mで考えてしまって問題ない。
この操作が重要で、これにより以下の性質が生まれる。
「配列Aの全部の要素をmod Mにすると、個数がM個を超えると必ず同じ値になる要素が出てくる」
これは鳩ノ巣原理であり、この状況になっているとabs(a[i] - a[j])=0となる部分が生まれるので、
全体の答えは0となる。

総括して説明すると、M<Nの場合は鳩ノ巣原理により必ず答えが0となる。
N≦Mの場合は、M≦10^3なので、問題で与えられている計算式をそのまま計算しても間に合うのでやる。
///////////////////////// writeup2 end */
