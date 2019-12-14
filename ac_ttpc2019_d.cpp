//https://atcoder.jp/contests/ttpc2019/tasks/ttpc2019_d
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
vector<bool> makePrimesBool(int n) { // [2,n]
    vector<bool> pr(n + 1, 1);
    pr[0] = pr[1] = 0;
    rep(p, 2, sqrt(n) + 2) if (pr[p]) for (int x = p * 2; x <= n; x += p) pr[x] = 0;
    return pr;
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














int N, A[201010];
int grundy[1010101];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) cin >> A[i];

    auto pr = makePrimesBool(1010101);
    rep(i, 1, 1010101) if(pr[i]) {
        set<int> gr;
        gr.insert(0); // get i
        if (0 < i - 2 and pr[i - 2]) {
            gr.insert(grundy[i - 2]); // get 2
            gr.insert(grundy[2]); // get i-2
        }
        while(gr.count(grundy[i])) grundy[i]++;
    }

    int xo = 0;
    rep(i, 0, N) xo ^= grundy[A[i]];

    if(xo == 0) cout << "Ai" << endl;
    else cout << "An" << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [grundy数](https://www.hamayanhamayan.com/entry/2017/02/27/025050)
///////////////////////// writeup2 start
以下、grundy数の理解が必須。
太字のルール「一度に取ることができる石の数は素数個で、かつその山の残る石の数も0個または素数個である必要がある」
特殊なルールであるが、素数1-X=素数2となるのは「X=素数1」か「X=2」か「Xが素数1-2の素数」となるかしかない。
つまり、遷移は多くて3択になる。
遷移が3つであれば、grundy数が事前計算できるので、計算しよう。
あとは、全ての山のgrundy数をxorして、判定する。
///////////////////////// writeup2 end */
