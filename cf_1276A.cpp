//https://codeforces.com/contest/1276/problem/A
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
#define CMAX 26
#define OFFSET 'a'
struct Node {int nxt[CMAX + 1]; int exist; vector<int> accept;
    Node() : exist(0) { memset(nxt, -1, sizeof(nxt)); }};
struct Trie {
    vector<Node> nodes; int root;Trie() : root(0) { nodes.push_back(Node()); }
    void upd_d(int node, int id) { nodes[node].accept.push_back(id); }
    void upd_c(int node, int child, int id) { ++nodes[node].exist; }
    void add(const string &str, int sindex, int nindex, int id){
        if (sindex == str.size()) upd_d(nindex, id); else {const int c = str[sindex] - OFFSET;
        if(nodes[nindex].nxt[c]==-1){nodes[nindex].nxt[c]=(int)nodes.size();nodes.push_back(Node());}
        add(str, sindex + 1, nodes[nindex].nxt[c], id);upd_c(nindex, nodes[nindex].nxt[c], id);}}
    void add(const string &str, int id) { add(str, 0, 0, id); }
    void add(const string &str) { add(str, nodes[0].exist); }
    int size() { return (nodes[0].exist); }int nodesize() { return ((int)nodes.size()); }};
struct AhoCorasick : Trie {
    static const int FAIL = CMAX; vector<int> correct; AhoCorasick() : Trie() {}
    void build() {correct.resize(nodes.size());
        rep(i, 0, nodes.size()) correct[i] = (int)nodes[i].accept.size();
        queue<int> que; rep(i, 0, CMAX + 1) { if (~nodes[0].nxt[i]) {
        nodes[nodes[0].nxt[i]].nxt[FAIL] = 0;que.emplace(nodes[0].nxt[i]);}else nodes[0].nxt[i] = 0;}
        while(!que.empty()){Node &now=nodes[que.front()];correct[que.front()]+=correct[now.nxt[FAIL]];
        que.pop();for (int i = 0; i < CMAX; i++) {if (now.nxt[i] == -1) continue;
        int fail = now.nxt[FAIL];while (nodes[fail].nxt[i] == -1) fail = nodes[fail].nxt[FAIL];
        nodes[now.nxt[i]].nxt[FAIL] = nodes[fail].nxt[i];auto &u = nodes[now.nxt[i]].accept;
        auto &v = nodes[nodes[fail].nxt[i]].accept;vector<int> accept;
        set_union(begin(u), end(u), begin(v), end(v), back_inserter(accept));u = accept;
        que.emplace(now.nxt[i]);}}}
    int match(const string &str, vector< int > &result, int now = 0) {
        result.assign(size(), 0);int count = 0;for (auto &c : str) {
        while (nodes[now].nxt[c - OFFSET] == -1) now = nodes[now].nxt[FAIL];
        now = nodes[now].nxt[c - OFFSET];count += correct[now];
        for (auto &v : nodes[now].accept) ++result[v];}return count;}
    int next(int now, char c) {while (nodes[now].nxt[c - OFFSET] == -1) now = nodes[now].nxt[FAIL];
        return nodes[now].nxt[c - OFFSET];}
};
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














string S;
AhoCorasick ac;
//---------------------------------------------------------------------------------------------------
int dp[201010][10];
pair<int, int> pre[201010][10];
void solve() {
	cin >> S;
	int N = S.length();
	rep(i, 0, N + 1) rep(t, 0, 10) dp[i][t] = inf;
	dp[0][ac.root] = 0;
	rep(i, 0, N) rep(t, 0, 10) if(dp[i][t] < inf) {
		if (chmin(dp[i + 1][t], dp[i][t] + 1)) {
			pre[i + 1][t] = { i, t };
		}

		int t2 = ac.next(t, S[i]);
		if (!ac.correct[t2]) {
			if (chmin(dp[i + 1][t2], dp[i][t])) {
				pre[i + 1][t2] = { i, t };
			}
		}
	}

	int ans1 = inf;
	int st = -1;
	rep(t, 0, ac.nodes.size()) if(!ac.correct[t]) {
		if (chmin(ans1, dp[N][t])) st = t;
	}
	printf("%d\n", ans1);
	vector<int> ans2;
	rrep(i, N, 1) {
		int st2 = pre[i][st].second;
		if (dp[i - 1][st2] != dp[i][st]) ans2.push_back(i);
		st = st2;
	}
	rep(i, 0, ans1) {
		if (i) printf(" ");
		printf("%d", ans2[i]);
	}
	printf("\n");
}
//---------------------------------------------------------------------------------------------------
void _main() {
	ac.add("one");
	ac.add("two");
	ac.build();

	int TT; cin >> TT;
	rep(t, 0, TT) solve();
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
DPをして復元しよう。
dp[i][t] := i文字目まで処理が終わっていて状態がtのときの削除の最小値
状態のtは今までの文字列の末尾を指していて、「なんでもいい」「O」「ON」「T」「TW」のいずれかである。
この辺を数値化して遷移していけばいい。
これは人力でやると大変だし、抜けもあるので、Aho Corasick法を使うと良い。
下手に頑張るよりアルゴリズムの力を借りよう。
あとは、復元も求められているので、pre[i][t]を用意して、前の状態を保存しておけば復元できる。

TLを見ると貪欲法もある。
///////////////////////// writeup2 end */
