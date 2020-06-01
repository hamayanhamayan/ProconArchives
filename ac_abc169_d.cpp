//https://atcoder.jp/contests/abc169/tasks/abc169_d
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
map<ll, int> enumpr(ll n) {
	map<ll, int> V;
	for (ll i = 2; i * i <= n; i++) while (n % i == 0) V[i]++, n /= i;
	if (n > 1) V[n]++;
	return V;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














ll N;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	auto ep = enumpr(N);

	int ans = 0;
	fore(p, ep) {
		int cnt = p.second;
		rep(i, 1, 1010) {
			if (i <= cnt) {
				ans++;
				cnt -= i;
			}
			else break;
		}
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [素因数分解(O(sqrt(N)))](https://www.hamayanhamayan.com/entry/2017/10/14/125941)
///////////////////////// writeup2 start
今回の操作では以下のことが言える。

- 各素数pについて、割れる回数は独立に計算できる
- ある素数pについて、最適な割る操作は、p, p^2, p^3, ...のようにすること

これが思いつけば、まず第一段階はクリア。
独立性については、色々な問題で出てくる考え方なので、頑張って思いついてもらうとして、
2つ目だが、操作を行う問題の取り組み方として、「最適な方針があるかも」として考えるのはテクである。
選択肢の1つとして覚えておこう。

この最適操作をやるというのが次のステップになるが、操作を考えると、Nの素因数分解が必要そうな感じに見える。
実は素因数分解はO(sqrt(N))で行うことができる。
ググろう。
N=10^12というのから計算量O(sqrt(N))をメタ読みして、素因数分解にたどり着いてもいい。
自分はメタ読みが先だった。

あとは、各素数についてp, p^2, p^3を割れなくなるまでシミュレートして、全体でやった回数をこたえると答え。
///////////////////////// writeup2 end */
