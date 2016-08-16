
void Delete(ListNode * pHead, ListNode * pToBeDeleted){
	if(pToBeDeleted == NULL)
		return NULL;
	if(pToBeDeleted -> m_pNext != NULL ){
		ListNode *temp = pToBeDeleted;
		pToBeDeleted->m_nKey = pToBeDeleted -> m_pNext ->m_nKey;
		pToBeDeleted->m_pNext = pToBeDeleted ->m_pNext->m_pNext;
		delete temp;
	}
	else{ //要删除节点为尾结点情况
		if(pHead == pToBeDeleted){
		 	pHead == NULL;
			delete pToBeDeleted;
		}
		ListNode *pNode = pHead;
		while(pNode -> m_pNext !=  pToBeDeleted)
			pNode = pNode->m_pNext;  
		pNode ->m_pNext = NULL;
		delete pToBeDeleted;
	}
}