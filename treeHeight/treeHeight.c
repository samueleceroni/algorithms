/*
typedef int elemType;

typedef struct treenode{
    elemType data;
    struct treenode *left; //elems smaller than data
    struct treenode *right; //elems greater than data
}treenodetype;

*/

int treeHeight(treenodetype *head){
    int r, l;
    if ( !head )
        return 0;
    else{

        r = treeHeight(head->right);
        l = treeHeight(head->left);

        return 1 + (r >= l ? r : l);      //ternary condition that returns the max between r and l
    }
}