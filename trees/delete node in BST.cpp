Node *findMin(Node *root) {
    while(root->left!=NULL) {
        root=root->left;
    }
    return root;
}
Node *deleteNode(Node *root, int x) {
    // your code goes here
    if(root == NULL) {
        return root;
    }
    if(root->data > x) {
        root->left = deleteNode(root->left, x);
        return root;
    }
    else if(root->data < x) {
        root->right = deleteNode(root->right, x);
        return root;
    }
    else{
        if(root->left==NULL && root->right == NULL) {
            delete root;
            root = NULL;
            
        }
        else if(root->left==NULL) {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right==NULL) {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else {
            // if both right and left child are present then we should set the root data to be min value of the right sub tree;
            // after setting it delete the right sub tree
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, root->data);
        }
        return root;
    }
    return root;
}