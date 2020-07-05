//https://atcoder.jp/contests/abc173/tasks/abc173_d
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














int N, A[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];
	sort(A, A + N, greater<int>());

	ll ans = A[0];
	rep(i, 0, N - 2) ans += 1LL * A[i / 2 + 1];
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
難しい問題。
「N人の到着順番や割り込む位置を適切に決める」とあるが、決めるべきことが多すぎる。
こういう時は、固定できそうな所を探すといい。
以下、未証明。

## 一部固定する

まず、到着順番は降順で入れていくのがいい。
（これはある降順でない順番があったときに、
それを大小関係を維持しつつ降順に言い換えたときに状況が同じか改善されるかのどちらかであるため。）
理由についてはあまり気にしなくてもいいかも。
この程度の仮定がないと解くのは難しい。

## 貪欲法

次に割り込む位置であるが、複雑なルールは作りたくないので、実験でとりあえず貪欲にやってみる。
すると、昇順でA,B,C,D,E,...となった場合に、
0+A+B+B+C+C+D+D+E+E+...
のようになっていることが実験で分かる。
完全二分木っぽく自分は考えた。
あとは、これを実装するだけ。
///////////////////////// writeup2 end */
