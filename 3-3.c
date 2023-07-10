//平衡二叉树的构建及其逐层遍历

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

struct BSTNode
{
    int data;
    struct BSTNode *pLchild;
    struct BSTNode *pRchild;
    struct BSTNode *pParent;
};

/** 链队列的节点定义，包含一个数据域和下一个节点的指针 */
typedef struct QueueNode {
    struct BSTNode * data;
    struct QueueNode* next;
}QueueNode;

/**  链队列的定义，包含队头和队尾指针*/
typedef struct {
    QueueNode* front;
    QueueNode* rear;
}LinkQueue;

/** 链队列的初始化 */
LinkQueue* InitQueue()
{
    LinkQueue* queue = (LinkQueue*)malloc(sizeof(LinkQueue));
    if (!queue)
    {
        printf("init queue error!\n");
        exit(0);
    }
    queue->front = (QueueNode*)malloc(sizeof(QueueNode));
    queue->front->next = NULL;
    queue->rear = queue->front;
    return queue;
}

/** 入队 */
void EnQueue(LinkQueue* queue, struct BSTNode * node)
{
    QueueNode* queueNode = (QueueNode*)malloc(sizeof(QueueNode));
    queueNode->data = node;
    queueNode->next = NULL;
    queue->rear->next = queueNode;
    queue->rear = queueNode;
}

/** 出队 */
struct BSTNode * DeQueue(LinkQueue* queue)
{
    if (queue->front == queue->rear)//队列为空
        return NULL;
    QueueNode* p = queue->front->next;
    struct BSTNode * node = p->data;
    queue->front = p;
    return node;
}

void displayData(struct BSTNode *T)
{
    printf("%d\n",T->data);
}

void PreOrderTraverse(struct BSTNode *T)
{
    if(T)
    {
        displayData(T);
        PreOrderTraverse(T->pLchild);
        PreOrderTraverse(T->pRchild);
    }
}

void MidOrderTraverse(struct BSTNode *T)
{
    if(T)
    {
        MidOrderTraverse(T->pLchild);
        displayData(T);
        MidOrderTraverse(T->pRchild);
    }
}

void PostOrderTraverse(struct BSTNode *T)
{
    if(T)
    {
        PostOrderTraverse(T->pLchild);
        PostOrderTraverse(T->pRchild);
        displayData(T);
    }
}

struct BSTNode* SearchBSTree(struct BSTNode* pBST, int keynum)   //查找关键值，若查找成功则返回该节点的地址
{
    if(pBST == NULL)
        return NULL;
    else if(keynum < pBST->data)
        return SearchBSTree(pBST->pLchild,keynum);
    else if(keynum > pBST->data)
        return SearchBSTree(pBST->pRchild,keynum);
    else
        return pBST;
}


void DeleteBSTree(struct BSTNode *pBST,int DeleteVal)  //根据关键值删除二叉树中的结点  好复杂.......
{
    struct BSTNode *pTem = SearchBSTree(pBST,DeleteVal);
    if(pTem == NULL)
    {
        printf("没有找到要删除的元素！\n");
        exit(-1);
    }

    if(NULL == pTem ->pLchild && NULL == pTem ->pRchild) //删除节点无左右孩子
    {
        if(pTem == pTem ->pParent ->pLchild)  //删除节点是其父节点的左孩子
        {
            pTem ->pParent ->pLchild = NULL;
        }
        else              //删除节点是其父节点的右孩子
        {
            pTem ->pParent ->pRchild =NULL;
        }
        free(pTem);
        pTem = NULL;
    }

    else if(NULL == pTem ->pLchild)    //删除节点无左孩子
    {
        if(pTem == pTem ->pParent ->pLchild)  //删除节点为其父节点的左孩子
        {
            pTem ->pParent ->pLchild = pTem ->pRchild;
            pTem ->pRchild ->pParent =pTem ->pParent;
        }
        else                                 //删除节点为其父节点的右孩子
        {
            pTem ->pParent ->pRchild = pTem ->pRchild;
            pTem ->pRchild ->pParent =pTem ->pParent;
        }
        free(pTem);
        pTem = NULL;
    }

    else if(NULL == pTem ->pRchild) //删除节点无右孩子
    {
        if(pTem == pTem ->pParent->pLchild)  //删除节点为其父节点的左孩子
        {
            pTem ->pParent ->pLchild = pTem ->pLchild;
            pTem ->pLchild ->pParent = pTem ->pParent;
        }
        else   //删除节点为其父节点的右孩子
        {
            pTem ->pParent ->pRchild = pTem ->pLchild;
            pTem ->pLchild ->pParent = pTem ->pParent;
        }
        free(pTem);
        pTem = NULL;
    }
    else    //删除节点有左右孩子，用删除节点左字树中的最大值或者右子树中最小值来代替删除节点
        //本例中用右子树中最小值来代替
    {
        struct BSTNode *pTial = pTem ->pRchild;
        while(NULL != pTial ->pLchild)  //查找右子树中的最小值
        {
            pTial = pTial ->pLchild;
        }
        printf("\n\t右子树中值最小的节点为%d\t\n",pTial->data);
        if(pTem == pTial ->pParent)  //右子树中的最小值的父节点是删除节点
        {
            if(pTem == pTem ->pParent ->pLchild)  //删除节点为其父节点的左孩子
            {
                pTem ->pParent ->pLchild = pTial;
                pTial ->pLchild = pTem ->pLchild;
                pTem ->pLchild->pParent = pTial;
            }
            else
            {
                pTem ->pParent ->pRchild = pTial;
                pTial ->pLchild = pTem ->pLchild;
                pTem ->pLchild->pParent = pTial;
            }
            free(pTem);
            pTem = NULL;
        }
        else   
        {
            if(pTial->pRchild)
            {
                pTial ->pRchild ->pParent = pTial ->pParent;
                pTial ->pParent ->pLchild = pTial ->pRchild;
            }
            pTem->data = pTial->data;
            pTial->pParent->pLchild = NULL;
            free(pTial);
            pTial = NULL;
        }
    }
}

int getNodeDepth(struct BSTNode *T)
{
    if(T==NULL)
    {
        return 0;
    }
    int lenleft=getNodeDepth(T->pLchild)+1;
    int lenright=getNodeDepth(T->pRchild)+1;
    if(lenleft>lenright)
    {
        return lenleft;
    }
    else
    {
        return lenright;
    }
}

int getBalanceFactor(struct BSTNode *T)    //获取结点平衡因子（左子树深度 - 右子树深度）
{
    return getNodeDepth(T->pLchild) - getNodeDepth(T->pRchild);
}


struct BSTNode * left_left_rotation(struct BSTNode *T)   //LL型旋转  
{
    struct BSTNode *pTeml = T->pLchild;
    if(T->pParent)
    {
        T->pLchild->pParent = T->pParent;
        if(T == T->pParent->pLchild)
            T->pParent->pLchild = T->pLchild;
        else
            T->pParent->pRchild = T->pLchild;
        if(pTeml->pRchild==NULL)
            T->pLchild = NULL;
        else
        {
            T->pLchild = pTeml->pRchild;
            pTeml->pRchild->pParent = T;
        }
        pTeml->pRchild = T;
        T->pParent = pTeml;
    }
    else
    {
        T->pParent = pTeml;
        T->pLchild = pTeml->pRchild;
        pTeml->pRchild = T;
        pTeml->pParent = NULL;
    }
    return pTeml;
}

struct BSTNode * right_right_rotation(struct BSTNode *T)   //RR型旋转    
{
    struct BSTNode *pTemr = T->pRchild;
    if(T->pParent)
    {
        T->pRchild->pParent = T->pParent;
        if(T == T->pParent->pLchild)
            T->pParent->pLchild = T->pRchild;
        else
            T->pParent->pRchild = T->pRchild;
        if(pTemr->pLchild==NULL)
            T->pRchild = NULL;
        else
        {
            T->pRchild = pTemr->pLchild;
            pTemr->pLchild->pParent = T;
        }
        pTemr->pLchild = T;
        T->pParent = pTemr;
    }
    else
    {
        T->pParent = pTemr;
        T->pRchild = pTemr->pLchild;
        pTemr->pLchild = T;
        pTemr->pParent = NULL;
    }
    return pTemr;
}

struct BSTNode * left_right_rotation(struct BSTNode *T)   //LR型旋转   
{
    struct BSTNode *pTeml = T->pLchild;
    struct BSTNode *pTemlr = T->pLchild->pRchild;
    if(T->pParent)
    {
        //先进行一次逆时针旋转
        pTemlr->pParent = T;
        T->pLchild = pTemlr;
        pTeml->pParent = pTemlr;
        pTeml->pRchild = pTemlr->pLchild;
        pTemlr->pLchild = pTeml;
        //再进行一次顺时针旋转
        pTemlr->pParent = T->pParent;
        if(T->pParent->pLchild == T)
            T->pParent->pLchild = pTemlr;
        else
            T->pParent->pRchild = pTemlr;
        T->pLchild = pTemlr->pRchild;
        T->pParent = pTemlr;
        pTemlr->pRchild = T;
    }
    else
    {
        //先进行一次逆时针旋转
        pTemlr->pParent = T;
        T->pLchild = pTemlr;
        pTeml->pParent = pTemlr;
        pTeml->pRchild = pTemlr->pLchild;
        pTemlr->pLchild = pTeml;
        //再进行一次顺时针旋转
        pTemlr->pParent = NULL;
        T->pLchild = pTemlr->pRchild;
        T->pParent = pTemlr;
        pTemlr->pRchild = T;
    }
    return pTemlr;
}

struct BSTNode * right_left_rotation(struct BSTNode *T)   //RL型旋转
{
    struct BSTNode *pTemr = T->pRchild;
    struct BSTNode *pTemrl = T->pRchild->pLchild;
    if(T->pParent)
    {
        //先进行一次顺时针旋转
        pTemrl->pParent = T;
        T->pRchild = pTemrl;
        pTemr->pParent = pTemrl;
        pTemr->pLchild = pTemrl->pRchild;
        pTemrl->pRchild = pTemr;
        //再进行一次逆时针旋转
        pTemrl->pParent = T->pParent;
        if(T->pParent->pLchild == T)
            T->pParent->pLchild = pTemrl;
        else
            T->pParent->pRchild = pTemrl;
        T->pRchild = pTemrl->pLchild;
        T->pParent = pTemrl;
        pTemrl->pLchild = T;
    }
    else
    {
        //先进行一次逆时针旋转
        pTemrl->pParent = T;
        T->pRchild = pTemrl;
        pTemr->pParent = pTemrl;
        pTemr->pLchild = pTemrl->pRchild;
        pTemrl->pRchild = pTemr;
        //再进行一次顺时针旋转
        pTemrl->pParent = NULL;
        T->pRchild = pTemrl->pLchild;
        T->pParent = pTemrl;
        pTemrl->pLchild = T;
    }
    return pTemrl;
}

struct BSTNode * enBalance(struct BSTNode *T)  //判断是何种失衡并进行平衡化旋转  已经过测试应该没问题
{
    if(abs(getBalanceFactor(T)) < 2) //平衡
    {
        return T;
    }
    else
    {
        if(getBalanceFactor(T) > 0)
        {
            if(getNodeDepth(T->pLchild->pLchild) > getNodeDepth(T->pLchild->pRchild)) //LL型
            {
                return left_left_rotation(T);
            }
            else
            {
                return left_right_rotation(T);
            }
        }
        else
        {
            if(getNodeDepth(T->pRchild->pRchild) > getNodeDepth(T->pRchild->pLchild)) //LL型
            {
                return right_right_rotation(T);
            }
            else
            {
                return right_left_rotation(T);
            }
        }
    }
}

struct BSTNode * InsertBSTree(struct BSTNode *pBST,int NUM) //插入元素   返回新插入的结点
{
    struct BSTNode *pRoot = pBST;//记录根节点地址
    struct BSTNode *pNew = (struct BSTNode *)malloc(sizeof(struct BSTNode));
    if(NULL == pNew)
        exit(-1);
    pNew ->data = NUM;
    pNew ->pLchild = pNew ->pRchild = NULL;
    struct BSTNode *pTmp = NULL;
    while(NULL != pBST )
    {
        pTmp = pBST;
        if(pNew ->data < pBST ->data)
            pBST = pBST ->pLchild;
        else
            pBST = pBST ->pRchild;
    }
    pNew->pParent = pTmp;
    if(NULL == pTmp)  //当树为空时，将插入节点的地址赋给根节点
        *pRoot = *pNew;
    else if(pNew ->data <= pTmp ->data)
        pTmp ->pLchild = pNew;
    else
        pTmp ->pRchild = pNew;

    return pNew;
}

void LayerOrderBiTreep(struct BSTNode *T)   //二叉树的逐层遍历 利用一个辅助队列
{
    int curLayerCount = 0; //当前层中的节点数
    int nextLayerCount = 0; //下一层中的节点数
    LinkQueue *queue = InitQueue();
    EnQueue(queue, T);
    curLayerCount++;
    struct BSTNode * p;
    while (p = DeQueue(queue))
    {
        curLayerCount--;
        printf("%d ", p->data);
        if (p->pLchild)
        {
            EnQueue(queue, p->pLchild);
            nextLayerCount++;
        }
        if (p->pRchild)
        {
            EnQueue(queue, p->pRchild);
            nextLayerCount++;
        }
        if (curLayerCount == 0)//一层已经遍历完毕
        {
            curLayerCount = nextLayerCount;
            nextLayerCount = 0;
        }
    }
}

int main()
{
    int n = 5;
    int i;
    int a[5];
    struct BSTNode *pRoot;
    struct BSTNode *Temp;
    struct BSTNode *Record,*Record2;
    Record = NULL;
    pRoot = (struct BSTNode *)malloc(sizeof(struct BSTNode));
    pRoot->pParent = NULL;
    pRoot->pLchild = pRoot->pRchild = NULL;
    for(i = 0; i < n; i++)         //数据的输入
    {
        scanf("%d",&a[i]);
    }
    pRoot->data = a[0];
    for(i = 1; i < n; i++)
    {
        if(!pRoot->pParent)
            Temp = InsertBSTree(pRoot,a[i]);
        else
            Temp = InsertBSTree(Record,a[i]);
        if(i >= 2)
        {
            if(abs(getBalanceFactor(Temp->pParent->pParent)) >= 2)
            {
                Record2 = Record;
                Record = enBalance(Temp->pParent->pParent);
                if(Record->pParent != NULL)
                    Record = Record2;
            }
        }
    }
    LayerOrderBiTreep(Record);
    return 0;
}
