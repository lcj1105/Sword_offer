
//求链表倒数第K个节点

struct ListNode{
	int m_nKey;
	ListNode * m_pNext;
}

// 求单链表中结点的个数  
unsigned int GetListLength(ListNode * pHead)  
{  
    if(pHead == NULL)  
        return 0;  
  
    unsigned int nLength = 0;  
    ListNode * pCurrent = pHead;  
    while(pCurrent != NULL)  
    {  
        nLength++;  
        pCurrent = pCurrent->m_pNext;  
    }  
    return nLength;  
}  

ListNode *FindKthToTail(ListNode* pListHead , unsigned int k){	
	length = GetListLength(pListHead);
	if (pListHead == NULL || k == 0 || length < k){
		return NULL;
	}
	ListNode * pAhead = pListHead;
	ListNode* pBehind = pListHead;
	for (unsigned int i = 0; i < k-1; ++i){
		pAhead = pAhead->m_pNext;
	}
	while( pAhead != NULL ){
		pAhead = pAhead->m_pNext;
		pBehind = pAhead->m_pNext;
	}
	return pBehind;
}