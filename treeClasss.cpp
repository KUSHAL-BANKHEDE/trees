#include<bits/stdc++.h>
using namespace std;
template <typename T>

class treeNode{
    public:
    int data;
    vector<treeNode<T>*> childran;
   
   treeNode(T d){
    this -> data = d;
    
   }

};

treeNode <int> * takeInput(){
    int rootData;
    cout<<"enter the root data"<endl;

    cin>>rootData;
   treeNode<int>* root = new treeNode(rootData);
    
    int n;;
    cout<<"enter the number of children"<<rootData<<endl;
    cin>>n;
    for(int i =0 ; i<n ; i++){
        //resisersion call
       treeNode<int> * child = takeInput();
       root->childran.push_back(child);
    }
    return root;


}

void printTree(treeNode<int>*root){
    cout<<root->data<<":";
    for( int i =0 ; i< root->childran.size() ; i++){
        cout<<root -> childran[i]->data<< ",";
    }
    cout<<endl;
    for(int i=0 ; i<root->childran.size() ; i++){
        printTree(root->childran[i]);
    }
}

int main(){

// treeNode<int> * root = new treeNode<int>(1);
// treeNode<int> * node1 = new treeNode<int>(2);
// treeNode<int> * node2 = new treeNode<int>(3);

// root->childran.push_back(node1);
// root->childran.push_back(node2);

treeNode<int>* root = takeInput();

printTree(root);

    return 0;
}