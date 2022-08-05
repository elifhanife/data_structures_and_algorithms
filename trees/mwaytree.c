#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define MIN 1

struct btreeNode {
    char item[MAX + 1];
    int count;
    struct btreeNode* link[MAX + 1];
};

struct btreeNode* root;

struct btreeNode* createNode(char item, struct btreeNode* child) {
    
    struct btreeNode* newNode;
    newNode = (struct btreeNode*)malloc(sizeof(struct btreeNode));
    newNode->item[1] = item;
    newNode->count = 1;
    newNode->link[0] = root;
    newNode->link[1] = child;
    return newNode;
}


void insertValue(char item, int pos, struct btreeNode* node, struct btreeNode* child) {
    
    int j = node->count;
    while (j > pos) {
            node->item[j + 1] = node->item[j];
            node->link[j + 1] = node->link[j];
            j--;
    }
    node->item[j + 1] = item;
    node->link[j + 1] = child;
    node->count++;
}

void splitNode(char item, char* pval, int pos, struct btreeNode* node, struct btreeNode* child, struct btreeNode** newNode) {
    
    int median, j;

    if (pos > MIN)
        median = MIN + 1;
    else
        median = MIN;

    *newNode = (struct btreeNode*)malloc(sizeof(struct btreeNode));
    
    j = median + 1;
    
    while (j <= MAX) {
        (*newNode)->item[j - median] = node->item[j];  
        (*newNode)->link[j - median] = node->link[j];
        j++;
    }
   
    node->count = median;
    (*newNode)->count = MAX - median;

    if (pos <= MIN) {
        insertValue(item, pos, node, child);
    }
    else {
        insertValue(item, pos - median, *newNode, child);
    }
    *pval = node->item[node->count];
    (*newNode)->link[0] = node->link[node->count];
    node->count--;

}


int setNodeValue(char item, char* pval, struct btreeNode* node, struct btreeNode** child) {
   
    int pos;

    if (!node) {
        *pval = item;
        *child = NULL;
        return 1;
    }

    if (item < node->item[1]) {
        pos = 0;
    }
    else {
        for (pos = node->count; (item < node->item[pos] && pos > 1); pos--);
        
        if (item == node->item[pos]) {
            printf("Duplicates not allowed\n");
            return 0;
        }
    }
    if (setNodeValue(item, pval, node->link[pos], child)) {
        if (node->count < MAX) {
            insertValue(*pval, pos, node, *child);
        }
        else {
            splitNode(*pval, pval, pos, node, *child, child);
            return 1;
        }
    }
    return 0;
}


void insertion(char item) {
   
    int flag, i;
    struct btreeNode* child;

    flag = setNodeValue(item, &i, root, &child);
    if (flag)
        root = createNode(i, child);
}

void traversal(struct btreeNode* myNode) {
    int i;
    if (myNode) {
        for (i = 0; i < myNode->count; i++) {
            traversal(myNode->link[i]);
            printf("%c ",myNode->item[i + 1]);
        }
        traversal(myNode->link[i]);
    }
}

int main() {

    char item, ch;
    char arr[20] = { 'A','G','F','B', 'K','D','H','M','J','E','S','I','R','X','C','L','N','T','U','P'};

    for (int i = 0; i < 20; i++) {
        insertion(arr[i]);
        traversal(root);
        printf("\n");
    }

}