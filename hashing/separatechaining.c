#include<stdio.h>
#include<stdlib.h>

#define size 7

struct node
{
    int data;
    struct node* next;
};

struct node* chain[size];

void init_chain()
{
    int i;
    for (i = 0; i < size; i++)
        chain[i] = NULL;
}

void insert(int value)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    int key = value % size;

    if (chain[key] == NULL) {
        chain[key] = newNode;
    }
    else
    {
        struct node* temp = chain[key];
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int search(int value)
{
    int key = value % size;
    struct node* temp = chain[key];
    while (temp)
    {
        if (temp->data == value) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int del(int value)
{
    int key = value % size;
    struct node* temp = chain[key], * dealloc;
    
    if (temp != NULL)
    {
        if (temp->data == value) //bastan silme
        {
            dealloc = temp;
            temp = temp->next;
            free(dealloc);
            return 1;
        }
        else //aradan silme
        {
            while (temp->next)
            {
                if (temp->next->data == value)
                {
                    dealloc = temp->next;
                    temp->next = temp->next->next;
                    free(dealloc);
                    return 1;
                }
                temp = temp->next;
            }
        }
    }

    return 0;
}


void print()
{
    int i;

    for (i = 0; i < size; i++)
    {
        struct node* temp = chain[i];
        printf("chain[%d]-->", i);
        while (temp)
        {
            printf("%d -->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    init_chain();
    int arr[6] = { 7,0,3,10,4,5 };
    int size_arr = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < size_arr; i++) {
        insert(arr[i]);
    }

    print();

    printf("\nSearching element 10\n");

    if (search(10))
        printf("Search Found\n");
    else
        printf("Search Not Found\n");

    if (del(10))
    {
        printf("\nAfter Deletion of 10\n");
        print();
    }
    else
        printf("\nValue Not Present\n");


    return 0;
}