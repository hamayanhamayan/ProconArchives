//https://atcoder.jp/contests/past202004-open/tasks/past202004_f
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














int N, A[201010], B[201010];
vector<int> add[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i] >> B[i];

	rep(i, 0, N) add[A[i]].push_back(B[i]);
	
	priority_queue<int> que;
	int ans = 0;
	rep(d, 1, N + 1) {
		fore(b, add[d]) que.push(b);
		ans += que.top();
		que.pop();
		printf("%d\n", ans);
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
例えば、1日目に選ぶタスクはどのタスクがいいだろうか。
複数タスクがある場合は最もポイントが大きいタスクを選べばいい。
次に2日目になるとタスクが増える。2日目に選ぶタスクはどのタスクがいいだろうか。
これも、選べるタスクの中で最もポイントが大きいタスクを選べばいい。
つまり、各日付について貪欲に最もポイントが大きいタスクを選べばいい。
これを高速に行おう。

この解法で求められる、最も数が大きい数を取り出すデータ構造が存在する。
Priority Queueを使おう。
各日付について、選べるようになったタスクのポイントをpriority queueに入れていく。
各日付について追加するタスクのポイントを高速に選択できるように、
add[d] := d日目に選べるタスクのポイントの配列
を先に作って置くといい。
すると、各日付について全体を見る必要がなくなり、O(N^2)となるのを回避できる。
これは全体の確認回数の総和はO(N)となるので、ならしO(N)である。
あとは、priority queueから毎回一番大きいものを取り出してポイントとする。
日付を1から順に進めていき、その日付でのポイントを答えればいい。
///////////////////////// writeup2 end */
