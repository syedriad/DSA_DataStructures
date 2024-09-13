
#include <iostream>
#include <queue>  
using namespace std;

class node{

public:
    int data ;
    node* left ;
    node* right ;

    node(int d){
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }

};

node* buildTree(node* root){

    cout << "Enter the data: " << endl ;
    int data ;
    cin >> data ;

    if(data == -1){
        return nullptr ;
    }

    root = new node(data) ;

    cout << "Enter the value for Left of " << data <<endl ;
    root->left = buildTree(root->left );

    cout << "Enter the value for right of " << data << endl ;
    root->right = buildTree(root->right) ;

    return root ;
 
}

// level order traversal

void levelOrderTraversal(node* root){

    queue <node*> q; 
    q.push(root) ;
    q.push(nullptr) ;
    
    while(!q.empty()){

        node* temp = q.front() ;
        q.pop() ;

        if (temp == nullptr){
            // porana level complete traverse hochuka hai

            cout << endl ;
            if( !q.empty()){

                //queue still has some child nodes
                q.push(nullptr) ;
            }
        }
        else{
        cout << temp->data << " " ;
            if(temp->left){
                q.push(temp->left) ;
            }
            if(temp->right){
                q.push(temp->right) ;
            }
        }
    }
}

void inOrder(node* root){

    //base case
    if (root == nullptr){
        return ;
    }

    inOrder(root->left);
    cout << root->data << " " ;
    inOrder(root-> right) ;
}


void preOrder(node* root){

    //base case
    if (root == nullptr){
        return ;
    }

    cout << root->data << " " ;
    preOrder(root->left);
    preOrder(root-> right) ;
}


void postOrder(node* root){

    //base case
    if (root == nullptr){
        return ;
    }

    postOrder(root->left);
    postOrder(root-> right) ;
    cout << root->data << " " ;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

int main(){

    node* root = nullptr ;

    // creating a tree
    root = buildTree(root);

    cout << "printing the level order traversal" << endl;
    levelOrderTraversal(root) ;

    cout << "InOrder Traversal: " ;
    inOrder(root) ;


    cout <<  endl << "preOrder Traversal: " ;
    preOrder(root) ;


    cout << endl <<"postOrder Traversal: " ;
    postOrder(root) ;

}