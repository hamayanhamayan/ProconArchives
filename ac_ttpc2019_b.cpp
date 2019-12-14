//https://atcoder.jp/contests/ttpc2019/tasks/ttpc2019_b
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














int N; string S;
//---------------------------------------------------------------------------------------------------
#define yes "Yes"
#define no "No"
string okyo = "okyo";
string ech = "ech";
string solve() {
    int n = S.length();
    rep(s1, 0, n) rep(s2, s1 + 4, n) {
        bool ok = true;
        rep(i, 0, 4) if(S[s1 + i] != okyo[i]) ok = false;
        rep(i, 0, 3) if(S[s2 + i] != ech[i]) ok = false;
        if(ok) return yes;
    }
    return no;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) {
        cin >> S;
        cout << solve() << endl;
    }
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
各文字列について、それぞれ判定をする。
判定については、「okyo」となる先頭と「ech」となる先頭を全探索する方法で行った。
okyoとなる先頭がs1番目、echとなる先頭がs2番目とする。
S[s1:s1+3] == "okyo"、かつ、S[s2:s2+2] == "ech"であればYesを返す。
そうなる組み合わせがなければNoを返す。
///////////////////////// writeup2 end */
