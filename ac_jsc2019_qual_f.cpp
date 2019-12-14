//https://atcoder.jp/contests/jsc2019-qual/tasks/jsc2019_qual_f
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















//---------------------------------------------------------------------------------------------------
void _main() {
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
とりあえずは[解説放送](https://www.youtube.com/watch?v=JTH27weC38k)を見るといい。

まず、[L,R]の問題を解くときは、[0,R]-[0,L-1]で答えになる場合は、これで考えるのがいい。
なので、Aの総和がR以下であるときの場合の数を求めることにしよう。
これは典型テク。

ここからはどうしてもうまくつなげることができないのだが、M番目とM+1番目の要素が等しくないという補事象を考えて、
全体から引くことで答えを求めよう。

さて、するとA[1]≧A[2]≧…A[M]＞A[M+1]≧…となる問題を求めることになる。
これもこのままでは大変。
そこで、A[M]の値を固定してみる。
A[M]=xとおくと、A[1]～A[M]≧x、かつ、A[M+1]～A[N]＜xであればいい。
こうすると、順序を考える必要がないので、だいぶ都合がいい。
この言い換えは使えそうなテクに見える。

ここまで考えることができれば、解法はだいぶ見えてくる。
A[1]～A[M]にxを先にそれぞれ割り当てておけば、A[1]～A[N]に適当に割り当てる問題になる。
しかしこれでは、2つ問題がある。

1. A[M+1]～A[N]＜xを満たさない可能性がある → 包除原理
2. 固定したはずのA[M]=xにならないかもしれない → x+1以上-x以上をすると、ちょうどxを数えられる

S[i] := x以上の要素がi個以上である割り当ての場合の数
///////////////////////// writeup2 end */
