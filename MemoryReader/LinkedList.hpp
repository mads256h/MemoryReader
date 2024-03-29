#pragma once
#include "ListNode.hpp"
#include "new.hpp"


template<typename T>
class LinkedList
{
	ListNode<T>* head_ = nullptr;
	ListNode<T>* tail_ = nullptr;
	size_t count_ = 0;

public:
	~LinkedList();
	ListNode<T>* head() const;
	ListNode<T>* tail() const;
	size_t count() const;
	void insert(T data);
	void remove(ListNode<T>* node);
};

template <typename T>
LinkedList<T>::~LinkedList()
{
	if (head_ == nullptr) return;

	for (ListNode<T>* i = head_; i != nullptr; )
	{
		auto p = i->next;
		DebugLog("Removed, %p", i);
		remove(i);
		i = p;
	}
}

template <typename T>
ListNode<T>* LinkedList<T>::head() const
{
	return head_;
}

template <typename T>
ListNode<T>* LinkedList<T>::tail() const
{
	return tail_;
}

template <typename T>
size_t LinkedList<T>::count() const
{
	return count_;
}

template <typename T>
void LinkedList<T>::insert(T data)
{
	count_++;

	if (head_ == nullptr)
	{
		head_ = new ListNode<T>(data, nullptr, nullptr);
		tail_ = head_;
		return;
	}

	ListNode<T>* p = new ListNode<T>(data, tail_, nullptr);
	tail_->next = p;
	tail_ = p;
}

template <typename T>
void LinkedList<T>::remove(ListNode<T>* node)
{
	if (node == head_)
	{
		head_ = node->next;
	}
	if (node == tail_)
	{
		tail_ = node->prev;
	}

	if (node->next != nullptr)
	{
		node->next->prev = node->prev;
	}

	if (node->prev != nullptr)
	{
		node->prev->next = node->next;
	}

	delete node;

	count_--;
}


