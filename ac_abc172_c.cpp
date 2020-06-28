//https://atcoder.jp/contests/abc172/tasks/abc172_c
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














int N, M, K, A[201010], B[201010];
ll Atot[201010], Btot[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> K;
	rep(i, 0, N) cin >> A[i];
	rep(i, 0, M) cin >> B[i];

	Atot[0] = 0;
	rep(i, 0, N) Atot[i + 1] = Atot[i] + A[i];
	Btot[0] = 0;
	rep(i, 0, M) Btot[i + 1] = Btot[i] + B[i];

	int ans = 0;
	int ok = M;
	rep(a, 0, N + 1) {
		while (0 <= ok && K < Atot[a] + Btot[ok]) ok--;
		if(0 <= ok) chmax(ans, a + ok);
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [尺取り法](https://www.hamayanhamayan.com/entry/2017/09/09/220426)
///////////////////////// writeup2 start
## まずは全探索で考えてみる

机Aからa冊、机Bからb冊取り除くとする。
すると、必要な時間が、A[1]+A[2]+...+A[a] + B[1]+B[2]+...+B[b]となる。
これがK以下であるようなa+bの最小値を答えればいい。
普通にやるとO(NM(N+M))の計算量だけど、A[1]+A[2]+...+A[a]は、以下のような累積和を作っておけば高速に求められる。
Atot[a] = A[1] + A[2] + ... + A[a]
Btot[b] = B[1] + B[2] + ... + B[b]
これの作り方が分からない場合は、累積和でググるといい。
でも計算量はまだO(NM)だ。
10^10は間に合わない。10^7くらいにはしたい。

## 何か使える性質はないか

aを0から順に増やしていったときに、最適なbはどのように変化するかを観察してみる。
aが増えるということは、Atot[a]が増えていく。
和がK以下である必要があるので、必然的にBtot[b]も小さくなる必要があり、bは小さくなっていく。
aが増えるにしたがってbが小さくなっていくという単調性という性質が見られる。
こういった場合に使えるのが尺取り法

## 尺取り法

尺取り法の詳しい説明はどこかに任せるので、ググって欲しい。
正直尺取り法でなくても、最適なbを求めるには二分探索を利用してもいい。
こちらでも計算量的には間に合うし、こっちの方が考えることが少なくて良いという人もいる。
尺取り法が分かっていれば、ここからの改善はそんなに難しくない。
前回の最適なbを覚えておいて、そこからbを条件を満たす最大のbとして保ちながら減らしながらa+bの最大を取っていく。
///////////////////////// writeup2 end */
