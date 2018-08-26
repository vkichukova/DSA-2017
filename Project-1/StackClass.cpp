#include <iostream>
 
using namespace std;
const int MAX = 100;
template<class T>
class Stack
{
    int top; // index of the top
    int length; // number of elements in stack
    T * elements; // the elements of the stack
 
    void copyStack(const Stack<T>& other)
    {
        top = other.top;
        length = other.length;
        elements = new T[MAX];
        for(int i = 0; i < length; i++)
            elements[i] = other.elements[i];
    }
    void deleteStack()
    {
        delete [] elements;
    }
public:
    Stack<T>()
    {
        top = -1;
        length = 0;
        elements = new T[MAX];
    }
    Stack<T>(const Stack<T>& other)
    {
        copyStack(other);
    }
    Stack<T>& operator=(const Stack<T>& other)
    {
        if(this != &other)
        {
            deleteStack();
            copyStack(other);
        }
        return *this;
    }
    bool isEmpty()
    {
        return top < 0;
    }
    bool isFull()
    {
        return top == MAX - 1;
    }
    int size()
    {
        return length;
    }
    void push(T element)
    {
        if(!isFull())
        {
            elements[++top] = element;
            length++;
        }
        else
        {
            cout << "The stack is full!";
        }
    }
    void pop()
    {
        if(!isEmpty())
        {
            top--;
            length--;
        }
        else
            cout << "The stack is empty!";
    }
    T peek() //top()
    {
        if(!isEmpty())
            return elements[top];
        else
            cout << "The stack is empty.";
    }
    void swap(int first, int second)
    {
        if(first!=second && first>=0 && second>=0)
        {
            T tmp = elements[first];
            elements[first] = elements[second];
            elements[second] = tmp;
        }
    }
    void swapStack(Stack<T>& other)
    {
        Stack tmp = *this;
        *this = other;
        other = tmp;
        tmp.deleteStack();
    }
    friend ostream& operator<<(ostream& os, const Stack<T>& s)
    {
        for (int i = 0; i < s.length; i++)
        {
            os << s.elements[i] << " ";
        }
        return os;
    }
};
 
int main()
{
    Stack<int> s1; // testing default constructor
    for(int i = 0; i < 10; i++)     // testing push()
        s1.push(i);
    cout << "S1: " << s1 << endl;
    cout << s1.peek() << endl;      // testing peek()
    s1.swap(1,2);                   // testing swap()
    cout << "S1: " << s1 << endl;
    Stack<int> s2 = s1, s3;         // testing copy constructor
    cout << "S2: " << s2 << endl;
    s3 = s1;                        // testing operator=
    cout << "S3: " << s3 << endl;
    s3.pop();                       //testing pop()
    cout << "S3: " << s3 << endl;
    s3.swapStack(s1);               // testing swapStack()
    cout << "S1: " << s1 << endl;
    cout << "S3: " << s3 << endl;
    return 0;
}
