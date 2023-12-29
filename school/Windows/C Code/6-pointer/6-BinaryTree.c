#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define SIZEARR 100
//
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;

} NODE;

int nodeCounter = 0;
int *list_ptr;
NODE *root = NULL;
NODE *temp = NULL;
NODE *temp2 = NULL;

// INHALTSANGABE
void UI();
void readData(int decision);
NODE *createNode(int data);
void addNode(int data);
void delNode(int data);
void searchData(int decision);
void free_all(NODE *root1);
void fancyPrint(NODE *root, int space);
void printTree();
void inOrderPrint(NODE *root1);
void preOrderPrint(NODE *root1);
void postOrderPrint(NODE *root1);
void addRNJesus();

int main()
{
    system("cls");
    printf("\n This Programm is represent a Tree \n-----j-o-e-_-m-a-m-a-_-h-o-t-----\n");
    UI();
    free_all(root);

    return 0;
}

void UI()
{
    int decision = 1;
    printf("[1]Add Node\t[2]Delete Node\t[3]Print Tree\t[4]Fancy Print\t[5]Add Random\t[6]Search Data\t[0]EXIT\n> ");
    scanf("%d", &decision);
    while (decision)
    {
        switch (decision)
        {
        case 1:
            readData(1);
            break;
        case 2:
            readData(2);
            break;
        case 3:
            printTree();
            break;
        case 4:
            system("cls");
            printf("\n Fancyprint: \n\n");
            fancyPrint(root, 0);
            printf("\n\n");
            break;
        case 5:
            addRNJesus();
            break;
        case 6:
            readData(3);
            break;
        }
        printf("[1]Add Node\t[2]Delete Node\t[3]Print Tree\t[4]Fancy Print\t[5]Add Random\t[6]Search Data\t[0]EXIT\n> ");
        scanf("%d", &decision);
    }
}

void readData(int decision)
{
    int data;
    system("cls");
    if (decision == 1)
    {
        printf("\nEnter a value (0-999)\n> ");
        scanf("%d", &data);
        system("cls");
        addNode(data);
    }
    else if (decision == 2)
    {
        printf("\nWhich node do you want to delete\n> ");
        scanf("%d", &data);
        system("cls");
        delNode(data);
    }
    else if (decision == 3)
    {
        printf("\nWhich number do you want to search\n> ");
        scanf("%d", &data);
        system("cls");
        searchData(data);
    }
}

NODE *createNode(int data)
{
    NODE *newNode = malloc(sizeof(NODE));
    if (newNode == NULL)
    {
        printf("Failed to allocate node\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addNode(int data)
{
    NODE *addedNote = createNode(data);
    NODE *current = root;
    if (root != NULL)
    {
        while (1)
        {
            if (current->data <= data)
            {
                if (current->right == NULL)
                {
                    current->right = addedNote;
                    printf("Added note on right of %d\n", current->data);
                    break;
                }
                current = current->right;
            }
            else
            {
                if (current->left == NULL)
                {
                    current->left = addedNote;
                    printf("Added note on left of %d\n", current->data);
                    break;
                }
                current = current->left;
            }
        }
    }
    else
    {
        root = addedNote;
        printf("Root is now %d\n", addedNote->data);
    }
}

NODE *findMin(NODE *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

void delNode(int data)
{

    NODE *current = root;

    if (root == NULL)
    {
        printf("root is NULL\n");
        return;
    }

    while (1)
    {
        if (current->data < data)
        {
            if (current->right != NULL)
            {
                if ((current->right)->data == data)
                {
                    NODE *deleted = current->right;
                    current->right = deleted->left;
                }
            }
        }
    }
}

void searchData(int decision)
{
    int pos = 0;

    NODE *current = root;
    for (int i = 0; current->data != decision; i++)
    {
        if (current->data >= decision)
        {
            if (current->right == NULL)
            {
                printf("\nNumber not in Maokai\n");
                return;
            }
            current = current->right;
        }
        else if (current->data < decision || current->left != NULL)
        {
            if (current->left == NULL)
            {
                printf("\nNumber not in Maokai\n");
                return;
            }
            current = current->left;
        }
        pos++;
    }
    printf("\nFound data in position %d\n", pos);
}

void free_all(NODE *root1)
{
    if (root1 != NULL)
    {
        free_all(root1->left);
        free(root1);
        free_all(root1->right);
        nodeCounter--;
    }
}

void fancyPrint(NODE *ptr, int space)
{

    if (ptr == NULL)
        return;

    space += 10;

    fancyPrint(ptr->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", ptr->data);

    fancyPrint(ptr->left, space);
}

void printTree() // get values
{
    printf("\n Pre-Order: ");
    preOrderPrint(root);
    printf("\n In-Order: ");
    inOrderPrint(root);
    printf("\n Post-Order: ");
    postOrderPrint(root);
    printf("\n");
}

void inOrderPrint(NODE *root1)
{
    if (root1 != NULL)
    {
        inOrderPrint(root1->left);
        printf("%d ", root1->data);
        inOrderPrint(root1->right);
    }
}

void preOrderPrint(NODE *root1)
{
    if(root1 != NULL){
        printf("%d ", root1->data);
        preOrderPrint(root1->left);
        preOrderPrint(root1->right);
    }
}

void postOrderPrint(NODE *root1)
{
    if (root1 != NULL){  
        postOrderPrint(root1->left);
        postOrderPrint(root1->right);
        printf("%d ", root1->data);
    }
}

void addRNJesus()
{
    int numbers[SIZEARR] = {0};
    int index;

    srand(time(NULL));

    for (int i = 1; i <= SIZEARR; i++)
    {
        // rando
        index = rand() % SIZEARR;

        if (numbers[index] = 0)
        {
            numbers[index] = i;
        }
        else
        {
            i--;
        }
    }

    for (int i = 0; i < SIZEARR; i++)
        addNode(numbers[i]);
}