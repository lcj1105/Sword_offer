struct ListNode{
	int m_nValue;
	ListNode *m_pNext;
}

//末尾添加节点
void AddToTail(ListNode ** pHead, int value){
	ListNode * pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext - NULL;
	if(*pHead == NULL){
		*pHead = pNew;
	}
	else{
		ListNode *pNode = *pHead;
		while(pNode->m_pNext != NULL){
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pNew;
	}
}

//找到一个含有某值的结点并删除之
void removeNode(ListNode ** pHead,int value){
	if(pHead ==NULL || *pHead == NULL)
		return;
	//ListNode *delTemp = new ListNode();
	ListNode *delTemp == NULL;
	if( (*pHead)->m_nValue == value){
		delTemp = *pHead;
		*pHead =  (*pHead)->m_pNext;
	}
	else{
		ListNode *pNode = *pHead;

		while(pNode->m_pNext!=NULL && pNode->m_pNext->m_nValue != value){
			pNode = pNode -> m_pNext;
		}
		if(pNode->m_pNext !=NULL && pNode->m_pNext->m_nValue == value){
			delTemp = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}

/*		while(pNode->m_pNext->m_pNext != NULL && pNode->m_pNext->m_nValue == value){
			delTemp = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
		if(pNode->m_pNext!=NULL && pNode->m_pNext->m_nValue == value){
			delTemp = pNode->m_pNext;
			pNode->m_pNext == NULL;
		}*/
	}
	if(delTemp!= NULL){
		delete delTemp;
		delTemp == NULL;
	}
}

//从尾到头打印链表,利用栈
void printListReversed(ListNode *pHead){
	if( pHead == NULL )
		return;
	ListNode *pNode = pHead;
	std::stack<ListNode*> nodes;
	while(pNode!=NULL ){
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	while(nodes!=NULL){
		pNode = nodes.top();
		printf("%d\n",pNode->m_nValue );
		nodes.pop();
	}
}

//从尾到头打印链表,利用递归，优美, 但链表大时不建议用
void printListReversed2(ListNode *pHead){
	if(pHead!==NULL){
		if(pHead->m_pNext != NULL){
			printListReversed2(pHead->m_pNext);
		}
		printf("%d\n",pHead->m_nValue );
	}
}