#ifndef Programka
#define Programka
#include <iosfwd>

class Stack
{
public:
	Stack() = default;

	~Stack();

	bool isEmpty();

	void push(const int& x);

	void pop();

	int& top();

	const int& top() const;
private:

	struct Node
	{
		Node* pNext_{ nullptr };
		ptrdiff_t data_{ 0 };
		Node(Node* p_Node, const int x)
		{
			pNext_ = p_Node;
			data_ = x;
		}
	};
	Node* pHead_{ nullptr };
};

#endif // !Programka
