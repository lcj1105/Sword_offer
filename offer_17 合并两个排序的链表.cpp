struct ListNode{
	int m_nKey;
	ListNode *m_pNext;
	ListNode(int x) : m_nKey(x), m_pNext(NULL) {}
};

ListNode *MergeSortedList(ListNode *l1, ListNode *l2){
	if(l1 == NULL)
		return l2;
	if(l2 == NULL)
		return l1;
	ListNode *pNode = NULL;
	if(l1 -> m_nKey > l2 -> m_nKey){
		pNode = l2;
		pNode -> m_pNext = MergeSortedList(l1 , l2->m_pNext);
	}
	else{
		pNode = l1;
		pNode -> m_pNext = MergeSortedList(l1->m_pNext , l2);
	}
	return pNode;
}