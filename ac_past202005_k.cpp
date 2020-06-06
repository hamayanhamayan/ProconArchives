//https://atcoder.jp/contests/past202005-open/tasks/past202005_k
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













int N, Q;
struct Node {
	Node(int v) : val(v), next(nullptr) {}
	Node* next;
	int val;
};
Node* containers[201010];
Node* topOfDesk[201010];
int ans[201010];
//---------------------------------------------------------------------------------------------------
void out() {
	rep(desk, 1, N + 1) {
		Node* cur = topOfDesk[desk];
		while (cur != nullptr) {
			ans[cur->val] = desk;
			cur = cur->next;
		}
	}
	rep(container, 1, N + 1) printf("%d\n", ans[container]);
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> Q;

	rep(i, 1, N + 1) topOfDesk[i] = containers[i] = new Node(i);
	rep(_, 0, Q) {
		int f, t, x; cin >> f >> t >> x;

		Node* nextTop = topOfDesk[f];
		topOfDesk[f] = containers[x]->next;
		containers[x]->next = topOfDesk[t];
		topOfDesk[t] = nextTop;
	}

	out();
}




/* ///////////////////////// writeup1 start
# 前提知識
- 単方向リスト
///////////////////////// writeup2 start
単方向リストを実装させる問題である。
（あまり見ないが、双方向リストであればコドフォで一回見た）

単方向リストがピンとこない場合はどこかで勉強して来た方がいい。

コンテナをリストのノードとして考える。
単方向の遷移先は下にあるコンテナを指すようにする。

以下の配列を使ってポインタ管理をしていく。
containers[i] := i番目のコンテナのノードへのポインタ
topOfDesk[i] := i番目の机の一番上にあるコンテナのノードへのポインタ

各クエリ(f,t,x)について以下のように代入を行う。
topOfDesk[f] ← containers[x]->next;   // 移動元の机fの一番上は移動させるコンテナの下に位置するコンテナになる
containers[x]->next ← topOfDesk[t];   // 移動させるコンテナの下に位置するコンテナは、移動先の机tの一番上のコンテナになる
topOfDesk[t] ← topOfDesk[f];          // 移動先の机tの一番上は移動元の机fの一番上になる
以上でイコールじゃなくて矢印を使っているのは、同時代入をしてほしくて、実装上は同時代入するか、
topOfDesk[f]をtmpで対比させておくかの工夫が必要である。

これでクエリをさばいた後に、置かれている机の番号を答える場合は、机の上から順番にコンテナを見ていって、
どこかに結果をメモって行き、コンテナの順番で置かれている机について答えればいい。
out関数内にてそれを実装している。
///////////////////////// writeup2 end */
