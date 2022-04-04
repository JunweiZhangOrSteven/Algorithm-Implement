////棋盘翻转
////广搜+状态压缩+位运算
//#include<iostream>
//#include<queue>
//using namespace std;
//typedef struct NODE
//{
//    int state;//棋盘状态
//    int cnt;//相应状态下翻转的次数
//}NODE;
//NODE Node, tempNode;
//const int WHITE = (1 << 16) - 1;//全白状态
//const int BLACK = 0;//全黑状态
//bool used[1 << 16];//记录棋盘状态
//int num;//在Init()函数中将状态压缩到num
//queue<NODE>q;
//bool Init()
//{
//    char ch;
//    int count;//位数指针
//    num = count = 0;
//    for (int i = 0; i < 4; i++)
//    {
//        for (int j = 0; j < 4; j++, count++)
//        {
//            cin >> ch;
//            if (ch == 'w')
//            {
//                num += 1 << count;//将count位置1
//            }
//        }
//    }
//    if (num == WHITE || num == BLACK)
//    {
//        cout << 0 << endl;
//        return true;
//    }
//    return false;
//}
//void Flip(int x, int y) //(x,y)等价于4*x+y位
//{
//    tempNode.state ^= 1 << (4 * x + y);//将(x,y)位翻转
//    if (x == 0)
//    {
//        tempNode.state ^= 1 << (4 + y);
//    }
//    else if (x == 3)
//    {
//        tempNode.state ^= 1 << (8 + y);
//    }
//    else
//    {
//        tempNode.state ^= 1 << (4 * (x - 1) + y);
//        tempNode.state ^= 1 << (4 * (x + 1) + y);
//    }
//    if (y == 0)
//    {
//        tempNode.state ^= 1 << (4 * x + 1);
//    }
//    else if (y == 3)
//    {
//        tempNode.state ^= 1 << (4 * x + 2);
//    }
//    else
//    {
//        tempNode.state ^= 1 << (4 * x + y + 1);
//        tempNode.state ^= 1 << (4 * x + y - 1);
//    }
//}
//void Bfs()
//{
//    used[Node.state] = true;
//    q.push(Node);
//    int i, j;
//    while (!q.empty())
//    {
//        Node = q.front();
//        q.pop();
//        ++Node.cnt;
//        for (i = 0; i < 4; i++)//对Node状态的下一步进行枚举，一共有16中可能
//        {
//            for (j = 0; j < 4; j++)
//            {
//                tempNode = Node;
//                Flip(i, j);
//                if (tempNode.state == WHITE || tempNode.state == BLACK)
//                {
//                    cout << tempNode.cnt << endl;
//                    return;
//                }
//                 if (!used[tempNode.state])
//                {
//                    used[tempNode.state] = true;
//                    q.push(tempNode);
//                }
//            }
//        }
//    }
//    cout << "Impossible\n";
//}
//int main()
//{
//    if (!Init())//如果棋盘需要翻转
//    {
//        Node.state = num;//棋盘当前状态
//        Node.cnt = 0;//当前翻转次数为0
//        Bfs();
//    }
//}