#include <iostream>
using namespace std;
 
// 스택 클래스 생성
class Stack {
public:
	int stack[10000];
	int size;
 
	Stack() { size = 0; }
 
	void push(int data) {
		stack[size] = data;
		size += 1;
	}
 
	bool empty() {
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
 
	int pop() {
		if (empty())
		{
			return -1;
		}
		else
		{
			stack[size - 1] = 0;
			size -= 1;
			return stack[size];
		}
	}
 
	int top() {
		if (empty())
		{
			return -1;
		}
		else
		{
			return stack[size - 1];
		}
	}
	
 
};
 
int main() {
	int N;
	cin >> N;
 
	Stack st;
 
	for (int i = 0; i < N; i++)
	{
		string cmd;
		cin >> cmd; 

		if (cmd == "push")
		{
			int data;
			cin >> data;
			st.push(data);
		}
		else if (cmd == "pop")
		{
			cout << (st.empty() ? -1 : st.top()) << '\n';
			if (!st.empty())
			{
				st.pop();
			}
		}
		else if (cmd =="size")
		{
			cout << st.size << '\n';
		}
		else if (cmd =="empty")
		{
			cout << st.empty() << '\n';
		}
		else if (cmd == "top")
		{
			cout << st.top() << '\n';
		}
	}
 
	return 0;
 
}