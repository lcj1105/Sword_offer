
//求链表倒数第K个节点

struct ListNode{
	int m_nKey;
	ListNode * m_pNext;
}

// 求单链表中结点的个数  
size_t GetListLength(ListNode * pHead)  
{  
    if(pHead == NULL)  
        return 0;  
  
    size_t nLength = 0;  
    ListNode * pCurrent = pHead;  
    while(pCurrent != NULL)  
    {  
        nLength++;  
        pCurrent = pCurrent->m_pNext;  
    }  
    return nLength;  
}  

ListNode *FindKthToTail(ListNode* pListHead , size_t k){	
	//length = GetListLength(pListHead); //用这个不优雅，时间还得加上O(n)
	if (pListHead == NULL || k == 0 ){
		return NULL;
	}
	ListNode * pAhead = pListHead;
	ListNode* pBehind = pListHead;
/*	for (size_t i = 0; i < k-1; ++i){
		pAhead = pAhead->m_pNext;
	}*/
	while( k > 1 && pAhead != NULL ){
		pAhead = pAhead->m_pNext;
		--k;		
	}
	if( k > 1 || pAhead == NULL )
		return NULL;
	
	while( pAhead != NULL ){
		pAhead = pAhead->m_pNext;
		pBehind = pAhead->m_pNext;
	}
	return pBehind;
}