#include "Stack.h"

Stack::~Stack()
{
	while (!isEmpty())
	{
		pop();
	}
}

bool Stack::isEmpty()
{
	return (pHead_ == nullptr);
}

void Stack::push(const int & x)
{
	pHead_ = new Node(pHead_, x);
}

void Stack::pop() 
{
	if (!isEmpty())
	{
		Node* pdeleted(pHead_);
		pHead_ = pdeleted->pNext_;
		delete pdeleted;
	}
}

int & Stack::top()
{
	return pHead_->data_;
}

const int & Stack::top() const
{
	return pHead_->data_;
}


