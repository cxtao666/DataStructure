#pragma once
#include <cstring>
#include <string.h>
#include<iostream>
#include"TrieTreeNode.h"
#include<queue>
using namespace std;
 
template<class T>
class TrieTree
{
	//Insert时为节点代表的单词word分配内存，Delete时只修改Freq而不删除word，Search时以Freq的数值作为判断依据，而不是根据word是否为NULL
public:
	TrieTree(const int size);
	~TrieTree(){ Destroy(root); };
	void Insert(const T* str);//插入单词str
	void Insert(const T* str, const int num);//插入单词str，带有编号信息
	int Search(const T* str);//查找单词str，返回出现次数
	bool Delete(const T* str);//删除单词str
	void PrintALL();//打印trie树中所有节点对应的单词
	void PrintPre(const T* str);//打印以str为前缀的单词
	void SetFailedPointer();//设置匹配失效时的跳转指针
	int MatchKMP(char* str);//返回str中出现在该TrieTree中的单词个数
private:
	void Print(const TrieTreeNode<T>* p);
	void Destroy(TrieTreeNode<T>* p);//由析构函数调用，释放以p为根节点的树的空间
private:
	TrieTreeNode<T>* root;
	int MaxBranchNum;//最大分支数
};
 
 
template<class T>
void TrieTree<T>::Destroy(TrieTreeNode<T>* p)
{
	if (!p)
		return;
	for (int i = 0; i < MaxBranchNum; i++)
		Destroy(p->ChildNodes[i]);
	if (!p->word)
	{
		delete[] p->word;//只是释放了char数组word的空间，指针word本身的空间未释放，由后续的delete p释放
		p->word = NULL;
	}
	delete p;//释放节点空间
	p = NULL;//节点指针置为空
	//以上的置NULL的两句无太大意义，但是：编程习惯
}
 
template<class T>
bool TrieTree<T>::Delete(const T* str)
{
	TrieTreeNode<T>* p = root;
	if (!str)
		return false;
	for (int i = 0; str[i]; i++)
	{
		int index = str[i] - 'a';
		if (p->ChildNodes[index])
			p = p->ChildNodes[index];
		else return false;
	}
	p->Freq = 0;
	p->ID = -1;
	return true;
}
 
template<class T>
void TrieTree<T>::PrintPre(const T* str)
{
	TrieTreeNode<T>* p = root;
	if (!str)
		return;
	for (int i = 0; str[i]; i++)
	{
		int index = str[i] - 'a';
		if (p->ChildNodes[index])
			p = p->ChildNodes[index];
		else return;
	}
	cout << "以" << str << "为前缀的单词有:" << endl;
	Print(p);
}
 
template<class T>
int TrieTree<T>::Search(const T* str)
{
	TrieTreeNode<T>* p = root;
	if (!str)
		return -1;
	for (int i = 0; str[i]; i++)
	{
		int index = str[i] - 'a';
		if (p->ChildNodes[index])
			p = p->ChildNodes[index];
		else return 0;
	}
	return p->Freq;
}
 
template<class T>
TrieTree<T>::TrieTree(const int size)
{
	MaxBranchNum = size;
	root = new TrieTreeNode<T>(MaxBranchNum);//根节点不储存字符
	root->FailedPointer = root;//设置失配指针
}
 
template<class T>
void TrieTree<T>::Insert(const T* str)
{
	TrieTreeNode<T>* p = root;
	int i;
	for (i = 0; str[i]; i++)
	{
		if (str[i]<'a' || str[i]>'z')
		{
			cout << "格式错误！" << endl;
			return;
		}
		int index = str[i] - 'a';//下溯的分支编号
		if (!p->ChildNodes[index])
			p->ChildNodes[index] = new TrieTreeNode<T>(MaxBranchNum);
		p = p->ChildNodes[index];
	}
	if (!p->word)//该词以前没有出现过
	{
		p->word = new char[strlen(str) + 1];
		strcpy(p->word , str);
		p->wordlen = i;//设置单词长度
	}
	p->Freq++;
}
 
template<class T>
void TrieTree<T>::Insert(const T* str, const int num)
{
	TrieTreeNode<T>* p = root;
	int i;
	for (i = 0; str[i]; i++)
	{
		if (str[i]<'a' || str[i]>'z')
		{
			cout << "格式错误！" << endl;
			return;
		}
		int index = str[i] - 'a';//下溯的分支编号
		if (!p->ChildNodes[index])
			p->ChildNodes[index] = new TrieTreeNode<T>(MaxBranchNum);
		p = p->ChildNodes[index];
	}
	if (!p->word)//该词以前没有出现过
	{
		p->word = new char[strlen(str) + 1];
		strcpy(p->word , str);
		p->wordlen = i;
	}
	p->Freq++;
	if (num < p->ID || p->ID == -1)//取最小的num作为当前节点代表的单词的ID
		p->ID = num;
}
 
template<class T>
void TrieTree<T>::PrintALL()
{
	Print(root);
}
 
template<class T>
void TrieTree<T>::Print(const TrieTreeNode<T>* p)
{
	if (p == NULL)
		return;
	if (p->Freq > 0)
	{
		cout << "单词:" << p->word << "	频数:" << p->Freq;
		if (p->ID >= 0)
			cout << "		ID:" << p->ID;
		cout << endl;
	}
	for (int i = 0; i < MaxBranchNum; i++)
	{
		if (p->ChildNodes[i])
		{
			Print(p->ChildNodes[i]);
		}
	}
}
 
template<class T>
int TrieTree<T>::MatchKMP(char* str)
{
	int count = 0;//str中出现的TrieTree中的单词个数
	char* p = str;//str中指针
	TrieTreeNode<T>* node = root;//TrieTree的节点指针
	while (*p)
	{
		if (node->ChildNodes[*p - 'a'])//当前字符匹配成功
		{
			TrieTreeNode<T>* temp = node->ChildNodes[*p - 'a']->FailedPointer;
			while (temp != root)//在匹配的情况下，仍然沿FailedPointer搜索，可检索出所有模式。
			{
				if (temp->Freq > 0)
				{
					count++;
					//cout << "temp->wordlen:" << temp->wordlen << endl;
					cout << (int)(p - str) - temp->wordlen + 1 << "	" << temp->word << endl;//打印已匹配的模式的信息
				}
				temp = temp->FailedPointer;
			}
			node = node->ChildNodes[*p - 'a'];
			p++;
			if (node->Freq > 0)
			{
				count++;
				//cout << "node->wordlen:" << node->wordlen << endl;
				cout << (int)(p - str) - node->wordlen << "	" << node->word << endl;//打印已匹配的模式的信息
			}
		}
		else//失配，跳转
		{
			if (node == root)
				p++;
			else
				node = node->FailedPointer;
		}
	}
	return count;
}
 
template<class T>
void TrieTree<T>::SetFailedPointer()
{
	queue<TrieTreeNode<T>*> q;
	q.push(root);
	while (!q.empty())
	{
		TrieTreeNode<T>* father = q.front();//父节点
		q.pop();
		for (int i = 0; i < MaxBranchNum; i++)//对每一个子节点设置FailedPointer
		{
			if (father->ChildNodes[i])
			{
				TrieTreeNode<T>* child = father->ChildNodes[i];
				q.push(child);
				TrieTreeNode<T>* candidate = father->FailedPointer;//从father->FailedPointer开始游走的指针
				while (true)
				{
					if (father == root)
					{
						candidate = root;
						break;
					}
					if (candidate->ChildNodes[i])//有与child代表的字母相同的子节点
					{
						candidate = candidate->ChildNodes[i];
						break;
					}
					else
					{
						if (candidate == root)
							break;
						candidate = candidate->FailedPointer;//以上两句顺序不能交换，因为在root仍可以做一次匹配
					}
				}
				child->FailedPointer = candidate;
			}
		}
	}
};