struct AVLNode {
    int balance_factor;
    char student_name[50];
    struct AVLNode* left;
    struct AVLNode* right;
    struct AVLNode* parent;
};
typedef struct AVLNode AVLNode;
struct AVLTree {
    AVLNode* root;
};
typedef struct AVLTree AVLTree;

void initAVL(AVLTree* tree);
AVLNode* insertNode(AVLTree* tree, AVLNode* node, char* name);
AVLNode* removeNode(AVLTree* tree, AVLNode* node, char* name);
void traverseInorder(AVLNode* node);
void destroyTree(AVLNode* node);