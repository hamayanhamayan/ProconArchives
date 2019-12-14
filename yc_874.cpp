//https://yukicoder.me/problems/no/874
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














string A, B;
//---------------------------------------------------------------------------------------------------
enum {
    NORMAL,
    QUESTION,
    STAR
};
//---------------------------------------------------------------------------------------------------
vector<pair<int,char>> parse(string s) {
    int n = s.length();
    vector<pair<int,char>> res;
    rep(i, 0, n) {
        if(i + 1 < n and s[i + 1] == '?') {
            res.push_back({QUESTION, s[i]});
            i++;
        } else if(i + 1 < n and s[i + 1] == '*') {
            res.push_back({STAR, s[i]});
            i++;
        } else res.push_back({NORMAL, s[i]});
    }
    return res;
}
//---------------------------------------------------------------------------------------------------
int dp[2010][2010];
void _main() {
    cin >> A >> B;

    auto AA = parse(A);
    auto BB = parse(B);

    int NA = AA.size();
    int NB = BB.size();

    rep(a, 0, NA + 1) rep(b, 0, NB + 1) dp[a][b] = inf;
    dp[0][0] = 0;

    rep(a, 0, NA) rep(b, 0, NB) {
        if (AA[a].first == NORMAL) chmin(dp[a + 1][b], dp[a][b] + 1);
        else chmin(dp[a + 1][b], dp[a][b]); // ?の場合は0コストで消せる

        if (BB[b].first == NORMAL) chmin(dp[a][b + 1], dp[a][b] + 1);
        else chmin(dp[a][b + 1], dp[a][b]); // ?の場合は0コストで消せる

        if(AA[a].first == NORMAL and BB[b].first == NORMAL) {
            chmin(dp[a + 1][b + 1], dp[a][b] + (AA[a].second != BB[b].second));
        }
        if(AA[a].first == NORMAL and BB[b].first == QUESTION) {
            chmin(dp[a + 1][b + 1], dp[a][b] + (AA[a].second != BB[b].second));
        }
        if(AA[a].first == NORMAL and BB[b].first == STAR) {
            chmin(dp[a + 1][b + 1], dp[a][b] + (AA[a].second != BB[b].second));
            chmin(dp[a + 1][b], dp[a][b] + (AA[a].second != BB[b].second)); // *の場合は使っても遷移させないでOK
        }

        if(AA[a].first == QUESTION and BB[b].first == NORMAL) {
            chmin(dp[a + 1][b + 1], dp[a][b] + (AA[a].second != BB[b].second));
        }
        if(AA[a].first == QUESTION and BB[b].first == QUESTION) {
            chmin(dp[a + 1][b + 1], dp[a][b] + (AA[a].second != BB[b].second));
        }
        if(AA[a].first == QUESTION and BB[b].first == STAR) {
            chmin(dp[a + 1][b + 1], dp[a][b] + (AA[a].second != BB[b].second));
            chmin(dp[a + 1][b], dp[a][b] + (AA[a].second != BB[b].second)); // *の場合は使っても遷移させないでOK
        }

        if(AA[a].first == STAR and BB[b].first == NORMAL) {
            chmin(dp[a + 1][b + 1], dp[a][b] + (AA[a].second != BB[b].second));
            chmin(dp[a][b + 1], dp[a][b] + (AA[a].second != BB[b].second));
        }
        if(AA[a].first == STAR and BB[b].first == QUESTION) {
            chmin(dp[a + 1][b + 1], dp[a][b] + (AA[a].second != BB[b].second));
            chmin(dp[a][b + 1], dp[a][b] + (AA[a].second != BB[b].second));
        }
        if(AA[a].first == STAR and BB[b].first == STAR) {
            chmin(dp[a + 1][b + 1], dp[a][b] + (AA[a].second != BB[b].second));
            chmin(dp[a + 1][b], dp[a][b] + (AA[a].second != BB[b].second)); // *の場合は使っても遷移させないでOK
            chmin(dp[a][b + 1], dp[a][b] + (AA[a].second != BB[b].second)); // *の場合は使っても遷移させないでOK
        }
    }

    rep(a, 0, NA) {
        if (AA[a].first == NORMAL) chmin(dp[a + 1][NB], dp[a][NB] + 1);
        else chmin(dp[a + 1][NB], dp[a][NB]);
    }

    rep(b, 0, NB) {
        if (BB[b].first == NORMAL) chmin(dp[NA][b + 1], dp[NA][b] + 1);
        else chmin(dp[NA][b + 1], dp[NA][b]);
    }

    cout << dp[NA][NB] << endl;
}





/* ///////////////////////// writeup1 start
- [DP(【テク20: 編集距離】編集距離の計算は、2つの文字列の添字を持つDPでできる)](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
///////////////////////// writeup2 start
編集距離はDPで解けることが知られているので、とりあえずDPで考えてみよう。
dp[a][b] := 文字列Aがa文字目まで、文字列Bがb文字目まで解釈されているときの編集距離の最小値
これで解けそうな雰囲気がある。
文字列目とかだと、先読みしなくてはいけないので、「文字」「?付き文字」「*付き文字」に先にパースしておこう。

根性で遷移を作る。
普通の編集距離のDPを理解していないと解くのは難しいので、やったことがないならそっちを先にやろう。
遷移をミスって最適じゃないものが混じっていても、最適な遷移がちゃんと含まれてれば問題ない。
考えうる遷移のパターンを盛り込んでおこう。
基本は編集距離のDPと同じ。
?であれば、消す時に0コストでできる
*であれば、追加する時に0コストでできる
///////////////////////// writeup2 end */
