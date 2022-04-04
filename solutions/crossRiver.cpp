//#include<iostream>
//#include<cstdio>
//#include<queue>
//#include<vector>
//#include<algorithm>
//#include <stdlib.h>
//#include <cmath>
//#define maxn 15
//#define maxm 15
//#define maxk 60
//#define inf 99999999
//#define maxup (1<<(maxn+1))+55
//using namespace std;
//struct node { int t; };
//queue<int> que;
//vector<node> map[maxup];
//int N, M, K, dist[maxup], vis[maxup] = { 0 }, upper;
////m-seats ; n-dogs ; k-couple of enemy ; 
//bool useful[maxup];
//void swp(int* a, int* b) { int tmp = *a; *a = *b, * b = tmp; }
//int Max(int a, int b) { if (a > b) return a; return b; }
//int len(int T) {//取二进制数长度
//    int k = 0;
//    while (T != 0) T >>= 1, k++;
//    return k;
//}
//int getnum(int n) {//取二进制数中1的个数
//    int count = 0;
//    while (n) {
//        ++count;
//        n = n & (n - 1);
//    }
//    return count;
//}
//
//int judmov(int f, int t) {
//    int a, b, c, d;
//    if ((t & 1) == 1) swp(&f, &t);
//
//}
//
//int main() {
//    int f, t, o;
//    node tmp;
//    cin >> M >> N >> K;
//    upper = (1 << (N + 1)) - 1;
//    for (int i = 0; i <= upper; i++) useful[i] = 1;
//    
//    for (int i = 1; i <= K; i++) {
//        cin >> f >> t;//the number of hostile dogs
//        o = (1 << f) | (1 << t);//the relationship
//        for (int j = 0; j <= upper; j++) {
//            if (useful[j] == 1) {
//                if (((j & o) == o) && ((j & 1) == 0)) {
//                    useful[j] = 0;
//                    useful[upper - j] = 0;
//                }
//            }
//        }
//    }//
//    for (int i = 0; i <= upper; i++) {
//        for (int j = i + 1; j <= upper; j++) {
//            if (useful[i] && useful[j] && getnum(i ^ j) <= M && ((i^j)&1) == 1 && judmov(i<j) {
//
//            }
//        }
//    }
//
//}