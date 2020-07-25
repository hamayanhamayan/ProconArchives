//https://atcoder.jp/contests/aising2020/tasks/aising2020_c
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














int N;
int ans[10101];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(x, 1, 101) rep(y, 1, 101) rep(z, 1, 101) {
		int tot = x * x + y * y + z * z + x * y + y * z + z * x;
		if (tot <= N) ans[tot]++;
	}
	rep(i, 1, N + 1) printf("%d\n", ans[i]);
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
こういう系が初見だと何から手を付ければいいか分からないかもしれない。
基本は全探索なので、全探索を考える。
Nをそれぞれ答えるので、Nの全探索を考えたくなるが…これは罠である。
x,y,zを全探索しよう。

## 全探索範囲について
x,y,zが1以上の整数としか条件になっていないので、上限が困るところ。
この上限がどのくらいかで、全探索ができるかが変わる。
x,y,zは実は上限100までで探索すればいい。
これはx=100であるだけで、x^2部分で10^4となるのでこれ以上増やしても、計算結果がN以下とならない。
よって、x,y,zは[1,100]で全探索する。
x,y,zでやると、全体で10^6通りとなるので、これは問題ない。
（探索空間が10^6通りなら行けるし、10^7くらいなら怪しいし、それ以上なら無理）
あとは、
ans[n] := 計算結果がnである組合せ
を数え上げていって、最後に順番に答えればよい。
///////////////////////// writeup2 end */
