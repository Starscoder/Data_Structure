/**
 * C++: 邻接表图
 *https://www.cnblogs.com/skywang12345/p/3707624.html
 */

#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 100
// 邻接表
class ListDG
{
    private: // 内部类
        // 邻接表中表对应的链表的顶点
        class ENode
        {
            public:
                int ivex;           // 该边所指向的顶点的位置
                ENode *nextEdge;    // 指向下一条弧的指针
        };

        // 邻接表中表的顶点
        class VNode
        {
            public:
                char data;          // 顶点信息
                ENode *firstEdge;   // 指向第一条依附该顶点的弧
        };

	private: // 私有成员
        int mVexNum;             // 图的顶点的数目
        int mEdgNum;             // 图的边的数目
        VNode mVexs[MAX];

    public:
        // 创建邻接表对应的图(自己输入)
		ListDG();
        // 创建邻接表对应的图(用已提供的数据)
        ListDG(char vexs[], int vlen, char edges[][2], int elen);
		~ListDG();

        // 打印邻接表图
        void print();

	private:
        // 读取一个输入字符
        char readChar();
        // 返回ch的位置
        int getPosition(char ch);
        // 将node节点链接到list的最后
        void linkLast(ENode *list, ENode *node);
};

/*
 * 创建邻接表对应的图(自己输入)
 */
ListDG::ListDG()
{
    char c1, c2;
    int v, e;
    int i, p1, p2;
    ENode *node1, *node2;

    // 输入"顶点数"和"边数"
    cout << "input vertex number: ";
    cin >> mVexNum;
    cout << "input edge number: ";
    cin >> mEdgNum;
    if ( mVexNum < 1 || mEdgNum < 1 || (mEdgNum > (mVexNum * (mVexNum-1))))
    {
        cout << "input error: invalid parameters!" << endl;
        return ;
    }
 
    // 初始化"邻接表"的顶点
    for(i=0; i<mVexNum; i++)
    {
        cout << "vertex(" << i << "): ";
        mVexs[i].data = readChar();
        mVexs[i].firstEdge = NULL;
    }

    // 初始化"邻接表"的边
    for(i=0; i<mEdgNum; i++)
    {
        // 读取边的起始顶点和结束顶点
        cout << "edge(" << i << "): ";
        c1 = readChar();
        c2 = readChar();

        p1 = getPosition(c1);
        p2 = getPosition(c2);
        // 初始化node1
        node1 = new ENode();
        node1->ivex = p2;
        // 将node1链接到"p1所在链表的末尾"
        if(mVexs[p1].firstEdge == NULL)
          mVexs[p1].firstEdge = node1;
        else
            linkLast(mVexs[p1].firstEdge, node1);
    }
}

/*
 * 创建邻接表对应的图(用已提供的数据)
 */
ListDG::ListDG(char vexs[], int vlen, char edges[][2], int elen)
{
    char c1, c2;
    int i, p1, p2;
    ENode *node1, *node2;

    // 初始化"顶点数"和"边数"
    mVexNum = vlen;
    mEdgNum = elen;
    // 初始化"邻接表"的顶点
    for(i=0; i<mVexNum; i++)
    {
        mVexs[i].data = vexs[i];
        mVexs[i].firstEdge = NULL;
    }

    // 初始化"邻接表"的边
    for(i=0; i<mEdgNum; i++)
    {
        // 读取边的起始顶点和结束顶点
        c1 = edges[i][0];
        c2 = edges[i][1];

        p1 = getPosition(c1);
        p2 = getPosition(c2);
        // 初始化node1
        node1 = new ENode();
        node1->ivex = p2;
        // 将node1链接到"p1所在链表的末尾"
        if(mVexs[p1].firstEdge == NULL)
          mVexs[p1].firstEdge = node1;
        else
            linkLast(mVexs[p1].firstEdge, node1);
    }
}

/* 
 * 析构函数
 */
ListDG::~ListDG() 
{
}

/*
 * 将node节点链接到list的最后
 */
void ListDG::linkLast(ENode *list, ENode *node)
{
    ENode *p = list;

    while(p->nextEdge)
        p = p->nextEdge;
    p->nextEdge = node;
}


/*
 * 返回ch的位置
 */
int ListDG::getPosition(char ch)
{
    int i;
    for(i=0; i<mVexNum; i++)
        if(mVexs[i].data==ch)
            return i;
    return -1;
}

/*
 * 读取一个输入字符
 */
char ListDG::readChar()
{
    char ch;

    do {
        cin >> ch;
    } while(!((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z')));

    return ch;
}

/*
 * 打印邻接表图
 */
void ListDG::print()
{
    int i,j;
    ENode *node;

    cout << "List Graph:" << endl;
    for (i = 0; i < mVexNum; i++)
    {
        cout << i << "(" << mVexs[i].data << "): ";
        node = mVexs[i].firstEdge;
        while (node != NULL)
        {
            cout << node->ivex << "(" << mVexs[node->ivex].data << ") ";
            node = node->nextEdge;
        }
        cout << endl;
    }
}

int main()
{
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
        {'A', 'B'}, 
        {'B', 'C'}, 
        {'B', 'E'}, 
        {'B', 'F'}, 
        {'C', 'E'}, 
        {'D', 'C'}, 
        {'E', 'B'}, 
        {'E', 'D'}, 
        {'F', 'G'}}; 
    int vlen = sizeof(vexs)/sizeof(vexs[0]);
    int elen = sizeof(edges)/sizeof(edges[0]);
    ListDG* pG;

    // 自定义"图"(输入矩阵队列)
    //pG = new ListDG();
    // 采用已有的"图"
    pG = new ListDG(vexs, vlen, edges, elen);

    pG->print();   // 打印图

    return 0;
}
