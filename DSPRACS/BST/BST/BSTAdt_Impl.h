
node* newNode(Player* item) {
    node *temp =  (node *)malloc(sizeof(node));
    temp->key = *item;
    temp->left = temp->right = NULL;
    return temp;
}

void output(Player temp){
	printf("%s\n", temp.name);

}

void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        output(root->key);
        inorder(root->right);
    }
}

void postorder(node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
	output(root->key);
    }
}

void preorder(node *root) {
    if (root != NULL) {
	output(root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

node* search(node* root, Player key) {

    if (root == NULL || !strcmp(root->key.name, key.name))
       return root;

    if (strcmp(key.name, root->key.name)<0)
       return search(root->right, key);

    return search(root->left, key);
}


node* insert(node* node1, Player* key) {
    if (node1 == NULL) return newNode(key);

    if (strcmp(key->name, node1->key.name)<0)
        node1->left  = insert(node1->left, key);
    else if (strcmp(key->name, node1->key.name)>0)
        node1->right = insert(node1->right, key);

    return node1;
}

node * minValueNode(node* node1) {
    node* current = node1;


    while (current && current->left != NULL)
        current = current->left;

    return current;
}

node* deleteNode(node* root, Player key) {
    if (root == NULL) return root;

    else if (strcmp(key.name, root->key.name)<0)
        root->left = deleteNode(root->left, key);


    if (strcmp(key.name, root->key.name)>0)
        root->right = deleteNode(root->right, key);

    else{

        if (root->left == NULL) {
            node *temp = root->right;
            //free(root);
            return temp;
        }
        else if (root->right == NULL) {
            node *temp = root->left;
            //free(root);
            return temp;
        }

 	node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
