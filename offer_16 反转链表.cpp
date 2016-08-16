struct ListNode{
	int m_nKey;
	ListNode *m_pNext;
	ListNode(int x) : m_nKey(x), m_pNext(NULL) {}
};

ListNode ReverseList(ListNode *pHead){
	if( pHead == NULL || pHead -> m_pNext == NULL)
		return pHead;
	ListNode *pNode = pHead;
	ListNode *reverseNode = NULL;

	while(pNode != NULL){
		ListNode *temp = pNode ;
		pNode = pNode -> m_pNext;
		temp->m_pNext = reverseNode;
		reverseNode = temp;
	}
	return reverseNode;
}