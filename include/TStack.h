#ifndef TSTACK_H
#define TSTACK_H

#include <string>
using namespace std;

template<typename ValueType>
class TStack {
private:
    int maxsize;
    ValueType* pMem;
    int top;
public:
    TStack(int);
    TStack(const TStack&);
    ~TStack();

    void Push(ValueType);
    void Pop();
    bool IsEmpty()const;
    bool IsFull()const;
    ValueType Top()const;

    void print() const;
};


/////////////////////////////////////////

template<typename ValueType>
TStack<ValueType>::TStack(int _maxsize)
{
    if (_maxsize <= 0)
        throw "Incorrect max size";
    maxsize = _maxsize;
    pMem = new ValueType[maxsize];
    top = -1;
    for (int i = 0; i < maxsize; i++)
        pMem[i] = 0;
}

template<typename ValueType>
TStack<ValueType>::TStack(const TStack& s)
{
    maxsize = s.maxsize;
    top = s.top;
    pMem = new ValueType[maxsize];
    for (int i = 0; i < maxsize; i++)
        pMem[i] = s.pMem[i];
}


template<typename ValueType>
TStack<ValueType>::~TStack()
{
    delete[] pMem;
}

template<typename ValueType>
void TStack<ValueType>::Push(ValueType a) {
    if (IsFull())
    {
        throw "The stack is full";
    }
    pMem[++top] = a;
}

template<typename ValueType>
void TStack<ValueType>::Pop() {
    if (IsEmpty())
        throw "The stack is empty";
    top--;
}

template<typename ValueType>
bool TStack<ValueType>::IsEmpty() const
{
    return (top == -1);
}

template<typename ValType>
bool TStack<ValType>::IsFull() const
{
    return ((maxsize - 1) == top);
}

template<class ValueType>
ValueType TStack<ValueType>::Top()const
{
    return pMem[top];
}

template<class ValueType>
void TStack<ValueType>::print() const
{
    TStack post(*this);

    char tmp[20];
    int i = 0;
    while (!post.IsEmpty())
    {
        tmp[i] = post.Top();
        post.Pop();
        i++;
    }
    for (int j = i; j < 20; j++)
        tmp[j] = '\0';

    std::string str = std::string(tmp);

    for (int j = 0; j < i / 2; j++)
        swap(str[j], str[i - j - 1]);
    cout << str << '\n';
}


#endif
