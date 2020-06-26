#include<iostream>
#include<fstream>
#include "TireTree.h"
using namespace std;
 
void test(TrieTree<char>* t)
{
	char* charbuffer = new char[50];
	char* cb = charbuffer;
 
	fstream fin("d:\\words.txt");
	if (!fin){
		cout << "File open error!\n";
		return;
	}
	char c;
	int num = 0;
	while ((c = fin.get()) != EOF)
	{
		if (c >= '0'&&c <= '9')
			num = num * 10 + c - '0';
		if (c >= 'a'&&c <= 'z')
			*cb++ = c;
		if (c == '\n')
		{
			*cb = NULL;
			t->Insert(charbuffer, num);
			cb = charbuffer;
			num = 0;
		}
	}
	fin.close();
}
 
 
int main()
{
	TrieTree<char>* t = new TrieTree<char>(26);
	char* c1 = "she";
	char* c2 = "shee";
	char* c3 = "he";
	char* c4 = "e";
 
	char* s = "shee";//要匹配的串
	t->Insert(c1);
	t->Insert(c2);
	t->Insert(c3);
	t->Insert(c4);
 
	//test(t);
	t->SetFailedPointer();
	t->PrintALL();
	cout << endl << "The matching result is:" << endl;
	int result = t->MatchKMP(s);
	cout << "Total matching " << result << " Pattern string" << endl;
	system("pause");
    return 0;
}
