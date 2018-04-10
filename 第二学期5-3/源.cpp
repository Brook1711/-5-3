#include<iostream>
#include<stack>
#include<string>

using namespace std;

class Queue
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		int result;
		if (stack2.empty()) {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		if (stack2.empty() && stack1.empty())
		{
			result = -1;
		}
		else
		{
			result = stack2.top();
			stack2.pop();
		}

		return result;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	Queue q;
	string s1 = "PUSH";
	string s2 = "POP";

	int count(0);
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		string s = "";
		cin >> s;
		if (s.compare(s1) == 0)
		{
			int temp(0);
			cin >> temp;
			q.push(temp);
		}
		else if (s.compare(s2) == 0)
		{
			cout << q.pop()<<endl;
		}
		else
		{
			cout << "error";
		}
	}


	//system("pause");
	return 0;
}