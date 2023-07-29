#pragma once

#include <memory>

template<typename T>
class Stack
{
private:
	using UT = std::unique_ptr<T>;

	UT stack[100];
	int top;

public:
	Stack();
	void push(const T&);
	void pop();
	T& peek() const;
	bool is_empty() const;
	size_t size() const;
	void clear();
};

template<typename T>
inline Stack<T>::Stack() : top(0)
{
	
}

template<typename T>
inline void Stack<T>::push(const T& element)
{
	stack[top] = std::make_unique<T>(element);
	++top;
}

template<typename T>
inline void Stack<T>::pop()
{
	if (top > 0) {
		stack[top].reset();
		--top;
	}
}

template<typename T>
inline T& Stack<T>::peek() const
{
	try {
		if (top > 0)
			return *stack[top - 1];
		throw std::exception("Empty stack.");
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n\n";
	}
}

template<typename T>
inline bool Stack<T>::is_empty() const {
	return this->top == 0;
}

template<typename T>
inline size_t Stack<T>::size() const {
	return top;
}

template<typename T>
inline void Stack<T>::clear() {
	while(!is_empty())
		this->pop();
}