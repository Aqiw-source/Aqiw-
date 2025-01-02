#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ��
typedef struct btnode
{
    int val;
    struct btnode* lchild;
    struct btnode* rchild;
} btnode;

// �����½ڵ�ĺ���
btnode* create(int val)
{
    btnode* newnode = (btnode*)malloc(sizeof(btnode));
    if (newnode == NULL)
    {
        printf("�ڴ����ʧ��!\n");
        return NULL;
    }
    newnode->val = val;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    return newnode;
}

// ǰ�����������ĺ��������������ȷ�汾��
btnode* build()
{
    int val;
    scanf("%d", &val);
    if (val == -1)  // ��-1��ʾ�սڵ�
    {
        return NULL;
    }
    btnode* bt = create(val);
    bt->lchild = build();
    bt->rchild = build();
    return bt;
}

// �����������
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
    printf("�밴��ǰ�������˳������������ڵ��ֵ����-1��ʾ�սڵ㣩��\n");
    btnode* root = build();
    printf("����������Ϊ��\n");
    preorder(root);
    return 0;
}
