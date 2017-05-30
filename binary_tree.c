#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

typedef int TDataType;

typedef struct TBinaryTree {
    TDataType data;
    struct TBinaryTree *lLink;
    struct TBinaryTree *rLink;
}TBinaryTree, *TPBinaryTree;

#define SIZE 10

typedef TPBinaryTree TStackElementType;

typedef struct TSeqStack {
	TStackElementType stack[SIZE];
    int top;
}TSeqStack;

bool Stack_isEmpty(TSeqStack *stack_);

bool Stack_isFull(TSeqStack *stack_);

void BaniryTree_middelSearch(TPBinaryTree T);

bool Stack_isEmpty(TSeqStack *stack_) {
	return (stack_->top == -1)?true:false;
}

bool Stack_isFull(TSeqStack *stack_) {
	return ((stack_->top + 1) >= SIZE)?true:false;
}

void BaniryTree_middelSearch(TPBinaryTree T) {
    TPBinaryTree P;
	TSeqStack A = {
		{(TStackElementType)0},
		-1
	};

    /* 初始化 */
    P = T;
    
T2:
    if (P == NULL) {
        if(Stack_isEmpty(&A)) {
            return;
        }

        /* 出栈 */
        P = A.stack[A.top--];

        /* visit NODE(P) */
        printf("%d ", P->data);

        P = P->rLink;

        goto T2;
    }
    else {
        if (Stack_isFull(&A)) {
            return;
        }

        /* 入栈 */
        A.stack[++A.top] = P;

        P = P->lLink;

        goto T2;
    }
}

int main(void) {
    TBinaryTree lleft = {
        -2, NULL, NULL
    };
    
    TBinaryTree lright = {
        0, NULL, NULL
    };
    
    TBinaryTree leftNode = {
        -1, &lleft, &lright
    };
    TBinaryTree rightNode = {
        2, NULL, NULL
    };
    
    TBinaryTree root = {
        1, &leftNode, &rightNode
    };

    BaniryTree_middelSearch(&root);
    
    return 0;
}

