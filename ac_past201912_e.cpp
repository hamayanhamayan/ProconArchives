//https://atcoder.jp/contests/past201912-open/tasks/past201912_e
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
bitset<100> follow[100];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> Q;
	rep(q, 0, Q) {
		int t; cin >> t;
		if (t == 1) {
			int a, b; cin >> a >> b; a--; b--;
			follow[a][b] = true;
		}
		else if (t == 2) {
			int a; cin >> a; a--;
			rep(u, 0, N) if (follow[u][a]) follow[a][u] = true;
		}
		else {
			int a; cin >> a; a--;
			vector<int> follow_user;
			rep(x, 0, N) if (follow[a][x]) follow_user.push_back(x);
			fore(x, follow_user) follow[a] |= follow[x];
		}
	}
	rep(i, 0, N) follow[i][i] = false;

	rep(i, 0, N) {
		rep(j, 0, N) {
			if(follow[i][j]) printf("Y");
			else printf("N");
		}
		printf("\n");
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
実装が厳しくなってくる。
N≦100なので、計算量は雑にやっても問題ない。
follow[i][j] := iがjをフォローしているか
これを持っておこう。
これはboolの2次元配列で持つのではなく、bitsetの1次元配列として持っておくと実装が少し楽になる。

フォロー操作
follow[a][b] = trueとするだけ

フォロー全返し
ユーザーu全てに対して、follow[u][a]=trueであればfollow[a][u]をtrueにする

フォローフォロー
ユーザーu全てに対して、follow[a][u]=trueであれば、follow[a] |= follow[u]とする。
これはbitsetで保持しているからできる芸当であるが、
boolの2次元配列でもループを1つ増やせば同等の操作ができる。

あとは、followを見ながら答える。
操作の過程で自分をfollowしてしまう可能性があるので、それをNにするのを忘れなく。
あと、順番に更新していくと、更新した情報を使って更に更新みたいなことをしてしまう場合があるので、注意。
///////////////////////// writeup2 end */
