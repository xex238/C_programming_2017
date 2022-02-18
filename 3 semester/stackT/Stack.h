#ifndef Programka
#define Programka
#include <iosfwd>

template <typename T>
class Stack
{
public:
	Stack() = default;

	~Stack();

	bool isEmpty();

	void push(const T& x);

	void pop();

	T& top();

	const T& top() const;
private:

	struct Node
	{
		Node* pNext_{ nullptr };
		T data_{ 0 };
		Node(Node* p_Node, const T x)
		{
			pNext_ = p_Node;
			data_ = x;
		}
	};
	Node* pHead_{ nullptr };
};

template<typename T>
Stack<T>::~Stack()
{
	while (!isEmpty())
	{
		pop();
	}
}

template<typename T>
bool Stack<T>::isEmpty()
{
	return (pHead_ == nullptr);
}

template<typename T>
void Stack<T>::push(const T& x)
{
	pHead_ = new Node(pHead_, x);
}

template<typename T>
void Stack<T>::pop()
{
	if (!isEmpty())
	{
		Node* pdeleted(pHead_);
		pHead_ = pdeleted->pNext_;
		delete pdeleted;
	}
}

template<typename T>
T& Stack<T>::top()
{
	return pHead_->data_;
}

template<typename T>
const T& Stack<T>::top() const
{
	return pHead_->data_;
}

#endif // !Programka
