#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


class node {
    public:
        int val = 0;
        node* left = nullptr;
        node* right = nullptr;

        node(int value) {
            val = value;
        }

        node(int value, node* l, node* r) {
            val = value;
            left = l;
            right = r;
        }
};

void preOrder(vector<int>& pre, node* point) {
    if(point == nullptr) {
        return;
    }

    pre.push_back(point->val);
    preOrder(pre, point->left);
    preOrder(pre, point->right);
    
}

void postOrder(vector<int>& po, node* point) {
    if(point == nullptr) {
            return;
        }

    postOrder(po, point->left);
    postOrder(po, point->right);
    po.push_back(point->val);
}

void inOrder(vector<int>& in, node* point) {
    if(point == nullptr) {
            return;
        }

    inOrder(in, point->left);
    in.push_back(point->val);
    inOrder(in, point->right);
}

vector<int> bfsQueue(node* root) {
    vector<int> ans;
    if(root == nullptr) {
        return ans;
    }

    queue<node*> nav;
    ans.push_back(root->val);
    nav.push(root);

    while(!nav.empty()) {
        if(nav.front()->left != nullptr) {
            ans.push_back(nav.front()->left->val);
            nav.push(nav.front()->left);
        }
        if(nav.front()->right != nullptr) {
            ans.push_back(nav.front()->right->val);
            nav.push(nav.front()->right);
        }
        nav.pop();
    }

    return ans;

}

int main() {

    node* root = new node(0);
    root->left = new node(1);
    root->right = new node(2);
    root->right->left = new node(3);
    root->right->right = new node(4);

    vector<int> pre;
    vector<int> post;
    vector<int> in;

    preOrder(pre, root);
    postOrder(post, root);
    inOrder(in, root);

    cout << "Preorder tree is: " << endl;

    for(auto elem : pre) {
        cout << elem << " ";
    }

    cout << "\nPostorder tree is: " << endl;

    for(auto elem : post) {
        cout << elem << " ";
    }

    cout << "\nInorder tree is: " << endl;

    for(auto elem : in) {
        cout << elem << " ";
    }

    vector<int> bfs; 

    bfs = bfsQueue(root);

    cout << "\nbfs nav is: " << endl;

    for(auto elem : bfs) {
        cout << elem << " ";
    }

    cout << "\nAll order type traversals are basically dfs except level order." << endl;


}



