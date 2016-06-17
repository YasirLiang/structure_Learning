#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef int key_t;
typedef int data_t;

typedef enum color_t
{
    RED = 0,
    BLACK = 1
}color_t;

typedef struct rb_node_t
{
    struct rb_node_t *left, right, *parent;
    key_t key;
    data_t data;
    color_t color;
}rb_node_t;

// 1.将旋转节点的右孩子变成旋转节点的右孩子的左孩子。先设node的右孩子
// 2.将旋转节点的右孩子的左孩子变成旋转节点
// 3.设置旋转节点的父母的左右孩子是旋转节点右孩子
// 4.设置旋转节点的父亲是旋转节点的右孩子
static rb_node_t* rb_rotate_left( rb_node_t* node, rb_node_t* root )
{
    rb_node_t* right = node->right;

    if( (node->right = right->left))// right的左子数变成node的右子树 right 左变右
    {
        right->left->parent = node;// node成为right左子树的父母
    }

    right->left = node;// node成为right的左孩子

    if( (right->parent = node->parent) )// node 的父亲成为right的父亲
    {
        if( node == node->parent->right )
        {// node为右孩子
            node->parent->right = right;// right成为node父亲的右孩子
        }
        else
        {// node为左孩子
            node->parent->left = right;// right 成为node父亲的左孩子
        }
    }
    else
    {
        root = right;// right成为根节点
    }

    node->parent = right;

    return root;
}

// 1.设置旋转节点的左右节点为右左节点的左右节点（左或右旋）
// 2.设置左右节点的右左节点为旋转节点（左或右旋）
// 3.设置左右节点父节点为旋转节点的父节点与父节点的左右节点（左或右旋）
// 4.设置旋转节点的父节点为右左节点（左或右旋）
// 5.左右旋记忆：左旋right 左变右;右旋left右变左
static rb_node_t* rb_rotate_right( rb_node_t* node, rb_node_t* root )
{
    rb_node_t* left = node->left;

    if( node->left = left->right )// left 右变左
    {
        left->right->parent = node;
    }

    left->right = node;

    if( left->parent = node->parent )
    {
        if( node == node->parent->left )
        {
            node->parent->left = left;
        }
        else
        {
            node->parent->right = left;
        }
    }

    node->parent = left;
    
    return root;
}
