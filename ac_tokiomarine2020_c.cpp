//https://atcoder.jp/contests/tokiomarine2020/tasks/tokiomarine2020_c
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














int N, K, A[201010], B[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;
	rep(i, 0, N) cin >> A[i];

	rep(k, 0, K) {
		rep(i, 0, N) B[i] = 0;
		rep(i, 0, N) {
			int L = max(0, i - A[i]);
			int R = min(N - 1, i + A[i]);

			B[L]++;
			B[R + 1]--;
		}
		rep(i, 1, N) B[i] += B[i - 1];

		bool same = true;
		rep(i, 0, N) {
			if (A[i] != B[i]) same = false;
			A[i] = B[i];
		}

		if (same) break;
	}

	rep(i, 0, N) {
		if(i) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}





/* ///////////////////////// writeup1 start
# 前提知識
- [imos法](https://www.hamayanhamayan.com/entry/2017/07/04/020117)
///////////////////////// writeup2 start
K回操作を行うとあるが、実験してみると、数が早いスピードで大きくなっていくことが分かる。
これは最小ケースである0 0 0 0…で様子を見てみると分かる。
なので、方針としては、シミュレーションを行って、結果が収束するかK回操作をしたら、終えるという方針にする。

次はシミュレーションのやり方が問題になる。
O(N)でやるのが最速なので、まずはこれを目指してみる。
問題では、ある電球の次の強さは照らされている電球の個数とされているが、
逆に考えてみる。
ある電球について[電球の座標-強さ,電球の座標+強さ]の範囲に強さを+1するという風に言い換えられる。
もらうDPを配るDPにするようなイメージ。

この区間に+1するという操作はimos法を使えばよい。
[A,B]に+xしたい場合は、Aに+xをして、B+1に-xをして、最後に先頭から累積和を取ると求めたいものが求まる。

自分の状態を配列Bとして構築して、差があるかを見て、ないなら抜けて…みたいな感じで実装している。
///////////////////////// writeup2 end */
