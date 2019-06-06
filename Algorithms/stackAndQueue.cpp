#include<bits/stdc++.h>
using namespace std;
template<typename T>
class stk
{
	public:
	stk* head;
	stk* next;
	T val;
	stk()
	{
		head = NULL;
		next = NULL;
	}
	T top()
	{
		return head->val;
	}
	bool empty()
	{
		return head == NULL;
	}
	void push(T x)
	{
		stk* node = new stk();
		node->val = x;
		node->next = head;
		head = node;
	}
	void pop()
	{
		head = head->next;
	}
};
template<typename T>
class que
{
	public:
		
		que* fr;
		que* rear;
		que* next;
		T val;
		que()
		{
			fr = NULL;
			rear = NULL;
		}
		bool empty()
		{
			return fr == NULL;
		}
		void push(T x)
		{
			que* node = new que();
			node->val = x;
			if(fr==NULL)
			{
				fr = node;
				rear = fr;
			}
			else
			{
				rear->next = node;
				rear = node;
			}
		}
		void pop()
		{
			if(fr==rear)
			{
				fr = NULL;
				rear = NULL;
			}
			else fr = fr->next;
		}
		T front()
		{
			return fr->val;
		}
};
int main()
{
	que<pair<int, int> > q;
	q.push(make_pair(1,0));
	q.push(make_pair(2,0));
	while(!q.empty())
	{
		cout<<q.front().first<<" "<<q.front().second<<endl;
		q.pop();
	}
}