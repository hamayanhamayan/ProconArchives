//https://atcoder.jp/contests/ttpc2019/tasks/ttpc2019_c
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














int N, X, A[501010];
//---------------------------------------------------------------------------------------------------
bool solve() {
    int xo = X;
    int cnt = 0;
    rep(i, 0, N) {
        if (A[i] < 0) cnt++;
        else xo ^= A[i];
    }

    if (cnt == 0) {
        if (xo == 0) return true;
        else return false;
    } else if (cnt == 1) {
        if (0 <= xo and xo <= X) {
            rep(i, 0, N) if(A[i] < 0) A[i] = xo;
            return true;
        }
        else return false;
    } else {
        int ans1 = 1;
        while(ans1 < xo) ans1 *= 2;
        ans1 /= 2;
        int ans2 = xo - ans1;

        int flag = 0;
        rep(i, 0, N) if(A[i] < 0) {
            if(flag == 0) A[i] = ans1, flag++;
            else if(flag == 1) A[i] = ans2, flag++;
            else A[i] = 0;
        }

        if (ans1 <= X and ans2 <= X) return true;
        else return false;
    }
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> X;
    rep(i, 0, N) cin >> A[i];

    auto ans = solve();

    if (ans) {
        rep(i, 0, N) {
            if(i) printf(" ");
            printf("%d", A[i]);
        }
        printf("\n");
    } else {
        printf("-1\n");
    }
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
自明な場合分けとして、欠損したものがなければ、XORをとって、Xと一致するかを見ればいい。

0≦ai≦Xであるという条件がなければ、欠損したaiがあれば必ず構築可能である。
欠損したaiが1つであれば、全体をXORしてXになるためにはai = X xor (ai以外のxor和)である必要がある。
このaiが0≦ai≦XであればOK、そうでないなら-1

欠損したaiが2つ以上あれば、使うのは2つで良さそう。
「X xor 欠損していないaiのxor和」を作ろうとした時に最上位ビットだけ立っているものと、最上位ビット以外が立っているもので作れる。
2つ以外は0で埋めておけばいい。
最上位ビットだけ立っているものがすでにXを超えている可能性があるので、それをチェックしておく。
どちらもX以下ならOK, そうでないなら-1
///////////////////////// writeup2 end */
