typedef struct { 
    char name[100];
    char role[100];
    float rr;
}Player; 

typedef struct pnode { 
    Player key;
    struct pnode *left, *right;
}node; 

node* newNode(Player* item);
void inorder(node *root);
void postorder(node *root);
void preorder(node *root);
node* search(node* root, Player key);
node* insert(node* node, Player* key);
node* minValueNode(node* node);
node* deleteNode(node* root, Player key);
