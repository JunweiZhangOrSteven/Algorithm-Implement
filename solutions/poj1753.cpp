////���̷�ת
////����+״̬ѹ��+λ����
//#include<iostream>
//#include<queue>
//using namespace std;
//typedef struct NODE
//{
//    int state;//����״̬
//    int cnt;//��Ӧ״̬�·�ת�Ĵ���
//}NODE;
//NODE Node, tempNode;
//const int WHITE = (1 << 16) - 1;//ȫ��״̬
//const int BLACK = 0;//ȫ��״̬
//bool used[1 << 16];//��¼����״̬
//int num;//��Init()�����н�״̬ѹ����num
//queue<NODE>q;
//bool Init()
//{
//    char ch;
//    int count;//λ��ָ��
//    num = count = 0;
//    for (int i = 0; i < 4; i++)
//    {
//        for (int j = 0; j < 4; j++, count++)
//        {
//            cin >> ch;
//            if (ch == 'w')
//            {
//                num += 1 << count;//��countλ��1
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
//void Flip(int x, int y) //(x,y)�ȼ���4*x+yλ
//{
//    tempNode.state ^= 1 << (4 * x + y);//��(x,y)λ��ת
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
//        for (i = 0; i < 4; i++)//��Node״̬����һ������ö�٣�һ����16�п���
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
//    if (!Init())//���������Ҫ��ת
//    {
//        Node.state = num;//���̵�ǰ״̬
//        Node.cnt = 0;//��ǰ��ת����Ϊ0
//        Bfs();
//    }
//}