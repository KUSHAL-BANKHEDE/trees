#include<bits/stdc++.h>
using namespace std ;

class Node {
    public:
    int data;
    Node* left ;
    Node* right;

    Node(int d){
        data =d;
        left= NULL;
        right = NULL;
    }
};

Node * insertIntoBST(Node* root , int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if ( d> root-> data){
        //right part me insert karna hai
        root->right = insertIntoBST(root->right , d);
    }

    else{
        root->left = insertIntoBST (root->left ,d);
    }

    return root;

}

void takeInput( Node* & root){
    int data ;
    cin>>data;
    while(data != -1){
       root = insertIntoBST(root , data);
        cin>>data;
    }
}

void levelOrderPrinting(Node * root){
    queue <Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if ( temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else 
        {
            cout<<temp->data<<" ";

        // aagar temp ka left non null hai to usko q me push kr do
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                 q.push(temp->right);
            }
        }
    }
}

//in case of bst inorder give shorted BST;
//LNR
void inorder(Node * root){
    //base case
    if(root == NULL ){
        return ;
    }

    //left call
    inorder(root->left);

    // node
    cout<<root->data<<" ";

    //right call

    inorder(root->right);

}


Node* minVal(Node * root ){
    Node* temp = root;
    while(temp->left != NULL ){
        temp= temp->left;
    }
    return temp;
}


Node* maxVal(Node * root ){
    Node* temp = root;
    while(temp ->right != NULL){
        temp= temp->right;
    }
    return temp;
}


Node* deleteFromBST(Node * root , int d){
    //base case
    if(root == NULL){
        return root;
    }

    if(root->data == d){
        //0 child
        
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
            
        // 1 child
        

        //left child
        if( root->left != NULL && root -> right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if( root->right != NULL && root -> left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }


        //2 child

        if(root->left != NULL && root -> right != NULL){
            int mini = minVal(root->right) ->data;
            root->data = mini;
            root->right = deleteFromBST(root->right , mini);
            return root;
        }



    }

    else if( root->data > d){
        // left part me chale gaye
        root->left = deleteFromBST(root->left , d);
        return root;    
    }
    else {
        //right part me chale gaye
        root->right = deleteFromBST(root->right , d);;
        return root;
    }
}

// 50 20 70 10 30 90 110

int main(){
    Node * root = NULL;

    cout<<"Enter data to createe BST"<<endl;
    
    takeInput(root);
    levelOrderPrinting(root);
    cout<<endl<<"inorder trvelsal  "<<endl;
    inorder(root);
    cout<<endl;
     
    cout<<"MIN VALUE "<< minVal(root)->data<<endl;
    cout<<"max VALUE "<< maxVal(root)->data<<endl;
    
    return 0;
}