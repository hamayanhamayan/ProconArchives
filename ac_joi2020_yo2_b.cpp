//https://atcoder.jp/contests/joi2020yo2/tasks/joi2020_yo2_b
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
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	vector<pair<int, int>> v;
	rep(i, 0, N) {
		int a, t;
		cin >> a >> t;
		v.push_back({ a, t });
	}
	sort(all(v));

	ll t = max(v[N - 1].first, v[N - 1].second);
	int x = v[N - 1].first;
	rrep(i, N - 2, 0) {
		t += x - v[i].first;
		x = v[i].first;
		chmax(t, 1LL * v[i].second);
	}
	t += x;
	cout << t << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
A,Tの上限が10^9なので、DPとかでなんとかするのは難しそう。
（座圧したらいけるかもしれないけど）
なので、とりあえず最適動作を考えよう。
直線上で左右に動ける問題は、だいたい行って戻ってを繰り返す動作は無駄と判定されることが多い。
なので、端までとりあえず移動して、戻りながら収穫していけばいい。
最適な動きな感じがする。

具体的には、以下の様な動きになる。
1. 最右のいちごに移動する
2. もし収穫できないなら待つ
3. 収穫したら1つ左のいちごに移動する、移動して収穫できないなら待つ
4. 3.を繰り返して、なくなったら入り口に戻ってきて終了

待つことができるかが問題には書いていないが、収穫できないなら、周りをうろうろしていればいいので、
待てると思って問題ない。
///////////////////////// writeup2 end */
