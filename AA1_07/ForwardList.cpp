#include "ForwardList.h"

ForwardList::ForwardList() 
{
	m_size = 0;
	m_first = nullptr;
	m_last = nullptr;
}

ForwardList::~ForwardList()
{
	if (m_first != nullptr)
	{
		delete m_first;
		delete m_last;
	}
}

void ForwardList::PushBack(int value)
{
	Node* node = new Node(value, nullptr);

	if (IsEmpty())
	{
		m_first = node;
		m_last = node;
	}
	else
	{
		m_last->m_next = node;
		m_last = node;
	}

	++m_size;
}

void ForwardList::PopBack()
{
	if (IsEmpty()) 
	{
		return;
	}

	if (m_first == m_last)
	{
		delete m_first;
		m_first = nullptr;
		m_last = nullptr;
	}
	else
	{
		Node* node = m_first;

		while (node->m_next != m_last)
		{
			node = node->m_next;
		}
		delete m_last;
		m_last = node;
		m_last->m_next = nullptr;
	}

	--m_size;
}

void ForwardList::PushFront(int value)
{
	Node* node = new Node(value, m_first);
	m_first = node;

	if (m_last == nullptr)
	{
		m_last = node;
	}

	++m_size;
}

void ForwardList::PopFront()
{
	if (IsEmpty())
	{
		return;
	}

	Node* node = m_first;
	m_first = m_first->m_next;

	delete node;

	--m_size;
}

bool ForwardList::IsEmpty() const 
{
	return m_size == 0;
}

int ForwardList::Front() const
{
	int i;

	if (m_first == nullptr)
	{
		i = -1;
	}
	else
	{
		i = m_first->m_value;
	}
	return i;
}

int ForwardList::Back() const
{
	int val;
	if (m_last == nullptr)
	{
		val = -1;
	}
	else 
	{
		val = m_last->m_value;
	}

	return val;
}

int ForwardList::Size() const
{
	return m_size;
}

void ForwardList::Erase(int value)
{
	if (IsEmpty()) return;

	Node* node = m_first;
	Node* prevNode = nullptr;
	while (node != nullptr)
	{
		if (node->m_value == value)
		{
			Node* node2 = node;
			if (prevNode == nullptr)
			{
				m_first = node->m_next;
			}
			else
			{
				prevNode->m_next = node->m_next;
			}
			
			node = node->m_next;
			
			delete node2;
			--m_size;
		}
		else
		{
			prevNode = node;
			node = node->m_next;
		}
	}

	m_last = node;
}

void ForwardList::Insert(int value, int position)
{
	if (position < 0 || position > m_size) return;

	if (position == 0)
	{
		PushFront(value);
	}
	else if (position == m_size)
	{
		PushBack(value);
	}
	else
	{
		Node* node = m_first;
		for (int i = 0; i < position; ++i)
		{
			node = node->m_next;
		}

		Node* node2 = new Node(value, node->m_next);
		node->m_next = node2;
		++m_size;
	}
}

bool operator==(const ForwardList& l1, const ForwardList& l2)
{
	if (l1.m_size != l2.m_size) return false;

	ForwardList::Node* node = l1.m_first;
	ForwardList::Node* node2 = l2.m_first;

	while (node != nullptr) {
		if (node->m_value != node2->m_value) return false;
		node = node->m_next;
		node2 = node->m_next;
	}

	return true;
}

std::ostream& operator<<(std::ostream& o, const ForwardList& l)
{
	ForwardList::Node* node = l.m_first;
	while (node != nullptr) {
		o << node->m_value << " ";
		node = node->m_next;
	}

	return o;
}