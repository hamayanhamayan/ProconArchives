//https://atcoder.jp/contests/tkppc4-2/tasks/tkppc4_2_c
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













int memo[2][30][2][2];
int dfs(int zero, int one, int kokuban, int turn) {
    if(0 <= memo[zero][one][kokuban][turn]) return memo[zero][one][kokuban][turn];

    if(zero + one == 0) {
        if(kokuban == 1 and turn == 0) return memo[zero][one][kokuban][turn] = 1;
        if(kokuban == 0 and turn == 1) return memo[zero][one][kokuban][turn] = 1;
        return memo[zero][one][kokuban][turn] = 0;
    }

    memo[zero][one][kokuban][turn] = 0;

    if(0 < zero) {
        if(dfs(zero - 1, one, kokuban, 1 - turn) == 0) memo[zero][one][kokuban][turn] = 1;
    }
    if(0 < one) {
        if (turn == 0) {
            if(dfs(zero, one - 1, 1 - kokuban, 1 - turn) == 0) memo[zero][one][kokuban][turn] = 1;
        }
        else {
            if(dfs(zero, one - 1, kokuban, 1 - turn) == 0) memo[zero][one][kokuban][turn] = 1;
        }
    }

    return memo[zero][one][kokuban][turn];
}
void labo() {
    rep(zero, 0, 2) rep(one, 0, 30) rep(kokuban, 0, 2) rep(turn, 0, 2) memo[zero][one][kokuban][turn] = -1;
    rep(zero, 0, 2) rep(one, 0, 30) printf("%d %d -> %d\n", zero, one, dfs(zero, one, 0, 0));
}







ll A, B;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> A >> B;

    bool ans = false;

    if (A % 2 == 0) {
        if (B % 4 == 1) ans = true;
        if (B % 4 == 2) ans = true;
    } else {
        if (B % 4 == 1) ans = true;
        if (B % 4 == 2) ans = true;
        if (B % 4 == 3) ans = true;
    }

    if (ans) cout << "Angel" << endl;
    else cout << "Devil" << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
実験せよと問題が囁いてくるので、実験をする。
labo関数を使って、バックトラックで実験してみる。

眺めると、ゼロの個数は偶奇しか関係なさそう。
なので、ゼロの個数を2択にして、イチの個数を増やして様子を見よう。
A%2=0のときは、「0 1 1 0」が続いているので、B%4としたときに1,2となれば天使が勝てる。
A%2=1のときは、「0 1 1 1」が続いているので、B%4としてときに1,2,3となれば天使が勝てる。

submit証明でAC。
///////////////////////// writeup2 end */
