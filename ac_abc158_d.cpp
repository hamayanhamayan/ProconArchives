//https://atcoder.jp/contests/abc158/tasks/abc158_d
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














string S; int Q;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> S >> Q;

	deque<char> deq;
	fore(c, S) deq.push_back(c);
	bool isRev = false;

	rep(_, 0, Q) {
		int t; cin >> t;
		if (t == 1) isRev = !isRev;
		else {
			int f; char c; cin >> f >> c;

			if (f == 1) {
				if (isRev) deq.push_back(c);
				else deq.push_front(c);
			}
			else {
				if (isRev) deq.push_front(c);
				else deq.push_back(c);
			}
		}
	}

	string ans = "";
	if (isRev) {
		while (!deq.empty()) {
			ans += deq.back();
			deq.pop_back();
		}
	}
	else {
		while (!deq.empty()) {
			ans += deq.front();
			deq.pop_front();
		}
	}

	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
実装問題。
各クエリO(1)くらいでやりたい所。
先頭と末尾に追加クエリがある。
先頭と末尾に追加するという操作ができるデータ構造がある。dequeだ。

dequeで実装を進めていく。
文字列が反転されているかを示すフラグを用意しておく。
isRev := 文字列が反転されているか

T=1のときは、isRevを反転させるだけ
T=2のときは、isRevがtrueになっているなら追加場所を逆転させる。
そうでないなら、クエリ通りに追加してやる感じ。

答えの文字列をdequeから再構成するが、isRevの値を見て、先頭からか末尾からか
どちらかから順番にとってきて答える。
///////////////////////// writeup2 end */
