//#include<iostream>
//#include<queue>
//using namespace std;
//typedef struct NODE
//{
//    int state;//棋盘状态
//    int cnt;//相应状态下翻转的次数
//}NODE;
//NODE Node, tempNode;
//// 1 denotes white 'w' and 0 denotes black 'b'
//const int WHITE = (1 << 16) - 1;//全白状态
//const int BLACK = 0;//全黑状态
//bool used[1 << 16];//记录棋盘状态
//int num;//在Init()函数中将状态压缩到num
//queue<NODE>q;
//bool init() {
//    char c;
//    int count = 0;
//    num = 0;
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            cin >> c;
//            if (c == 'w') {
//                num += (1 << count);
//            }
//            count++;
//        }
//    }
//    if (num == WHITE || num == BLACK) {
//        cout << 0 << endl;
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//
//
//int main() {
//    if (!init()) {
//
//
//
//    }
//    
//}