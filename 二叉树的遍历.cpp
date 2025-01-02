#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
typedef struct btnode
{
    int val;
    struct btnode* lchild;
    struct btnode* rchild;
} btnode;

// 创建新节点的函数
btnode* create(int val)
{
    btnode* newnode = (btnode*)malloc(sizeof(btnode));
    if (newnode == NULL)
    {
        printf("内存分配失败!\n");
        return NULL;
    }
    newnode->val = val;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    return newnode;
}

// 前序建立二叉树的函数（修正后的正确版本）
btnode* build()
{
    int val;
    scanf("%d", &val);
    if (val == -1)  // 用-1表示空节点
    {
        return NULL;
    }
    btnode* bt = create(val);
    bt->lchild = build();
    bt->rchild = build();
    return bt;
}

// 先序遍历函数
void preorder(btnode* bt)
{
    if (bt == NULL)
    {
        return;
    }
    printf("%-4d", bt->val);
    preorder(bt->lchild);
    preorder(bt->rchild);
}

int main()
{
    printf("请按照前序遍历的顺序输入二叉树节点的值（用-1表示空节点）：\n");
    btnode* root = build();
    printf("先序遍历结果为：\n");
    preorder(root);
    return 0;
}
