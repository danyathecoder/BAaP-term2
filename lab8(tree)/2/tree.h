struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};

void push(struct tree **node, int a);
void out(struct tree *node, int g);
struct tree *max(struct tree *node);
