#include "stdio.h"
#include "stdlib.h"

struct node {

    int data = 0;
    struct node* left;
    struct node* right;

};


struct node* creatNode(int key){

    struct node* newNode =(struct node*)malloc(sizeof (struct node));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorderTraversal(struct node* node){

    if(node !=NULL){

        inorderTraversal(node->left);
        printf("data: %d\n",node->data);

        inorderTraversal(node->right);
    }


}

struct node* ArrayToBST(int arr[], int start, int end) {

    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    struct node* root = creatNode(arr[mid]);

    root->left = ArrayToBST(arr, start, mid - 1);

    root->right = ArrayToBST(arr, mid + 1, end);

    return root;
}

int main(){

    int Arr[1000];
    for (int i = 0; i < 1000; i++) {
        Arr[i] = i+1;
    }

    struct node* root = ArrayToBST(Arr, 0, 999);

    inorderTraversal(root);

}