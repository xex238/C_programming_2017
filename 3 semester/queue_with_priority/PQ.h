#ifndef Programka
#define Programka

template<typename T>
struct PQ
{
public:
	PQ() = default;

	~PQ();

	void pop();

	//int& top();

	const T& top() const;

	bool isEpmty() const;

	void insert(const T& a);

	void insert(const PQ& a);

	PQ& operator=(const PQ& a);

private:
	struct Node
	{
		Node* pNext_{ nullptr };
		T data_{ 0 };
		Node(Node* pNode, const T& a) : pNext_{ pNode }, data_{ a } {}
	};
	Node* pHead_{ nullptr };
};

template<typename T>
PQ<T>::~PQ()
{
	while (!isEpmty())
	{
		pop();
	}
}

template<typename T>
void PQ<T>::pop()
{
	if (!isEpmty())
	{
		Node* pDel(pHead_);
		pHead_ = pHead_->pNext_;
		delete pDel;
	}
}

//int & PQ::top()
//{
//	return pHead_->data_;
//}

template<typename T>
const T & PQ<T>::top() const
{
	return pHead_->data_;
}

template<typename T>
bool PQ<T>::isEpmty() const
{
	return pHead_ == nullptr;
}

template<typename T>
void PQ<T>::insert(const T & q1)
{
	if (isEpmty() || q1 > pHead_->data_)
	{
		pHead_ = new Node(pHead_, q1);
		return;
	}
	Node* q2 = pHead_;
	Node* q3 = pHead_->pNext_;
	while (q3 != nullptr && q3->data_ > q1)
	{
		q2 = q3;
		q3 = q3->pNext_;
	}
	q2->pNext_ = new Node(q2->pNext_, q1);
}

template<typename T>
void PQ<T>::insert(const PQ & q1)
{
	Node* q2 = q1.pHead_;
	while (q2 != nullptr)
	{
		insert(q2->data_);
		q2 = q2->pNext_;
	}
}

template <typename T>
PQ<T> & PQ<T>::operator=(const PQ & q1)
{
	while (!isEpmty())
	{
		pop();
	}
	if (!q1.isEpmty())
	{
		pHead_ = new Node(nullptr, q1.pHead_->data_);
		Node* q2 = pHead_;
		Node* q3 = q1.pHead_->pNext_;
		while (q3 != nullptr)
		{
			q2->pNext_ = new Node(nullptr, q3->data_);
			q3 = q3->pNext_;
			q2 = q2->pNext_;
		}
	}
	return *this;
}

#endif // !Programka
