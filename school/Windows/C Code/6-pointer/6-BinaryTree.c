/*
File: 07-BinaryTree.c
Date: 29-04-2024  12:53
Author: Leon A.
File Description: ---

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct note_strc{
    int num;

    struct note_strc *left;
    struct note_strc *right;
}NODE;


void add_Node_recur(NODE **root, int value);
void delete_Node(NODE **root, int value);
void print_Nodes_Prefix(NODE *root);
void print_Nodes_Infix(NODE *root);
void print_Nodes_Postfix(NODE *root);
void free_all(NODE *root);
void UI(NODE *root);
int search_smallest(NODE *root);
NODE *search_Node(NODE *root, int value);


int main(int argc, char* argv[]){
    NODE *root = NULL;
    printf("\n This Code represents a BST");

    UI(root);

    free_all(root);
    return 0;
}


void UI(NODE *root){
    while(4){ //UI for choosing
        printf("\n\n\n [1] Add Node");
        printf("\n [2] Print Nodes");
        printf("\n [3] Search Node");
        printf("\n [4] Delete Node");
        printf("\n [5] Exit");
        printf("\n\n Enter your choice: ");
        int choice = 0;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\n Enter value for new Node: ");
                int value5 = 0;
                scanf("%d", &value5);

                add_Node_recur(&root, value5);
                break;
            case 2:
                if(root == NULL){ printf("\n No nodes to print"); break; }
                printf("\nPrefix order: ");
                print_Nodes_Prefix(root);
                printf("\nInfix order: ");
                print_Nodes_Infix(root);
                printf("\nPostfix order: ");
                print_Nodes_Postfix(root);
                break;
            case 3:
                if(root == NULL){ printf("\n No nodes to search"); break; } //search for node (value
                printf("\n Enter the number to search: ");
                int value = 0;
                scanf("%d", &value);

                NODE *temp = search_Node(root, value);
                if(temp != NULL){ printf("\n Node found: %d", temp->num); }
                else{ printf("\n Node not found"); }

                break;
            case 4:
                if(root == NULL){ printf("\n No nodes to delete"); break; } //delete node
                printf("\n Enter the number to delete: ");
                int value1 = 0;
                scanf("%d", &value1);

                delete_Node(&root, value1);
                break;
            case 5: //close program
                return;
                break;
            default:
                printf("\n Invalid choice");
        }
    }
}


void add_Node_recur(NODE **root, int value){
    if(*root == NULL){
        *root = (NODE *)malloc(sizeof(NODE));
        (*root)->num = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else{
        if((*root)->num <= value){
            add_Node_recur(&(*root)->right, value);
        }
        else{
            add_Node_recur(&(*root)->left, value);
        }
    }
}


NODE *search_Node(NODE *root, int value){ //searches for the Node recursivly
    if(root != NULL){ //retrun if Null (everything goes into this  since recursivly eventually)
        if(root->num == value){ //if value of current node is right
            return root;
        }
        NODE *temp = search_Node(root->left, value); //recall function with new node
        if(temp != NULL){
            return temp; //if value found
        }
        NODE *temp1 = search_Node(root->right, value); //recall function with new node
        if(temp1 != NULL){ //if value found
            return temp1;
        }
    }
    return NULL;
}


int search_smallest(NODE *root){ //searches for the smallest node
    if(root->left == NULL){
        return root->num;
    }
    return search_smallest(root->left);
}


void delete_Node(NODE **root, int value){
    if(*root != NULL){
        if((*root)->num == value){
            if((*root)->left == NULL && (*root)->right == NULL){
                free(*root);
                *root = NULL;
            }else if((*root)->left == NULL){
                NODE *temp = *root;
                *root = (*root)->right;
                free(temp);
            }else if((*root)->right == NULL){
                NODE *temp = *root;
                *root = (*root)->left;
                free(temp);
            }else{ //delete if both sides have a pointer and replace with smallest from right side
                (*root)->num = search_smallest((*root)->right);
                delete_Node(&(*root)->right, (*root)->num);
            }
        }else if((*root)->num < value){
            delete_Node(&(*root)->right, value);
        }else{
            delete_Node(&(*root)->left, value);
        }
    }
}
           

//printing nodes
void print_Nodes_Prefix(NODE *root){
    if(root == NULL){ return; }
    printf("%d, ", root->num);
    print_Nodes_Prefix(root->left);
    print_Nodes_Prefix(root->right);
}

void print_Nodes_Infix(NODE *root){
    if(root == NULL){ return; }
    print_Nodes_Infix(root->left);
    printf("%d, ", root->num);
    print_Nodes_Infix(root->right);
}

void print_Nodes_Postfix(NODE *root){
    if(root == NULL){ return; }
    print_Nodes_Postfix(root->left);
    print_Nodes_Postfix(root->right);
    printf("%d, ", root->num);
}


void free_all(NODE *root){
    if(root != NULL){
        free_all(root->left);
        free_all(root->right);
        free(root);
    }
}
