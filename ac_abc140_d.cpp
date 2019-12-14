//https://atcoder.jp/contests/abc140/tasks/abc140_d
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
vector<pair<char, int>> runLengthEncoding(string s) {
    int n = s.length();

    vector<pair<char, int>> res;
    char pre = s[0];
    int cnt = 1;
    rep(i, 1, n) {
        if (pre != s[i]) {
            res.push_back({ pre, cnt });
            pre = s[i];
            cnt = 1;
        }
        else cnt++;
    }

    res.push_back({ pre, cnt });
    return res;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/

int N, K;
string S;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> K >> S;
    auto rl = runLengthEncoding(S);
    int gr = rl.size();
    rep(k, 0, K) {
        if(3 <= gr)
            gr -= 2;
        else if(gr == 2)
            gr = 1;
    }
    int ans = N - gr;
    cout << ans << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
400点にしてはだいぶ難しく見える。
回転というのは厄介か。
まず、重要な考察がいくつかある。

- 方向が一致してない箇所で幸福が1つ減る
    - つまり、なるべく方向を一致させたい
- 回転しても、回転した区間で方向が一致していない箇所は変化しない
    - つまり、複数の方向が一致していない区間を回転させてもその間では何も起きない

で、これらを考えていくと、回転させるのは、ある同一方向を向いている塊を回転させれば良さそうということになる。
やっと400点レベルにまで落ちてきた。
方向が一致している区間を縮約するとLRLRLRやRLRLRLになっているはず。
例えばLRLRLRの最初のRを回転させるとLLLRLRでLRLRとなり、方向が一致していない箇所が2つ減る。
なので、LかRのどちらかを貪欲に回転させて、方向不一致の区間を減らしていったときの幸福人数が答え。
幸福人数はN-(LかRのグループ数)となる。各グループで1つは幸福でないため。
自分はLRの縮約をランレングスでやったが、これはオーバーキル。
///////////////////////// writeup2 end */
