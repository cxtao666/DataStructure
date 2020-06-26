#pragma once
#include<iostream>
using namespace std;
 
template<class T>
class TrieTreeNode
{
public:
	TrieTreeNode(int MaxBranch)//用于构造根节点
	{
		MaxBranchNum = MaxBranch;
		ChildNodes = new TrieTreeNode<T>*[MaxBranchNum];
		for (int i = 0; i < MaxBranchNum; i++)
			ChildNodes[i] = NULL;
		word = NULL;
		wordlen = 0;
		FailedPointer = NULL;
		Freq = 0;
		ID = -1;
	}
public:
	int MaxBranchNum;//最大分支数；
	char* word;//单词字符串的指针
	int wordlen;
	TrieTreeNode<T> **ChildNodes;
	int Freq;//词频统计
	int ID;//构建TrieTree树时的插入顺序，可用来记录字符串第一次出现的位置
	TrieTreeNode<T> *FailedPointer;
};