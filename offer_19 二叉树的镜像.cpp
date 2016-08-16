struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

//大神解答
TreeNode *MirrorRecursively(TreeNode *pRoot){
	if( pRoot == NULL )
		return NULL;
	TreeNode *temp = pRoot -> left;
	pRoot -> left = MirrorRecursively(pRoot -> right);
	pRoot -> right = MirrorRecursively(temp);
	return pRoot;
}

//书上解答，写的更易懂
void MirrorRecursively(TreeNode *pRoot){
	if(pRoot == NULL)
		return;
	if(pRoot -> left == NULL || pRoot -> right == NULL )
		return;
	TreeNode *temp = pRoot -> left;
	pRoot -> left = pRoot -> right;
	pRoot -> right = temp;
	if(pRoot -> left)
		MirrorRecursively(pRoot -> left);
	if(pRoot -> right)
		MirrorRecursively(pRoot -> right);
}