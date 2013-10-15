#include <iostream>

using namespace std;

struct mylist
{
	mylist* next;
	int data;
};

mylist* reverseList(mylist* pList)
{
	mylist* pre = pList;
	mylist* cur = pList->next;
	mylist* next = NULL;

	while(cur != NULL)
	{
		next = cur->next;
		cur->next = pre;
		
		pre = cur;
		cur = next;
	}

	pList->next = NULL;
	return pre;
};

mylist* mergeList(mylist* p1, mylist* p2)
{
	if(p1 == NULL) return p2;
	if(p2 == NULL) return p1;
	
	mylist* rst = (p1->data < p2->data ? p1 : p2);

	mylist* idx1 = p1;
	mylist* idx2 = p2;
	mylist* tmp = new mylist;
	mylist* cur = tmp;
	
	while( idx1 != NULL && idx2 != NULL)
	{
		if(idx1->data > idx2->data)
		{
			cur->next = idx1;
			cur = cur->next;
			idx1 = idx1->next;
		}
		else
		{
			cur->next = idx2;
			cur = cur->next;
			idx2 = idx2->next;
		}	
	}

	if(idx1 == NULL)
		cur->next = idx2;
	if(idx2 == NULL)
		cur->next = idx1;
	
	delete tmp;

	return rst;
};

mylist* initList(mylist* plist, int arry[], int len)
{
	plist->data = arry[0];
	mylist* idx = plist;
	
	for(int i = 1; i < len; ++i)
	{
		mylist* tmp = new mylist();
		tmp->data = arry[i];
		idx->next = tmp;
		idx = tmp;
	}
	idx->next = NULL;

	return plist;
};

void printList(mylist* plist)
{
	mylist* idx = plist;
	while(idx != NULL)
	{
		cout << idx->data << "\t";
		idx = idx->next;
	}
	cout <<endl;
}

int main()
{
	int arry1[] = {0,1,2,3,4};
	int arry2[] = {5,6,7,8,9};
	int arry3[] = {0,2,4,6,8};
	int arry4[] = {1,3,5,7,9};
	int arry5[] = {1,2,6,7,9};
	int arry6[] = {0,3,4,5,8};
	
	mylist* one = initList(new mylist, arry1, 5);
	mylist* two = initList(new mylist, arry2, 5);
	mylist* three = initList(new mylist, arry3, 5);
	mylist* four = initList(new mylist, arry4, 5);
	mylist* five = initList(new mylist, arry5, 5);
	mylist* six = initList(new mylist, arry6, 5);

	printList(mergeList(one,two));
	printList(mergeList(two, one));
	printList(mergeList(three, four));
	printList(mergeList(four, three));
	printList(mergeList(five, six));
	printList(mergeList(six, five));
	printList(mergeList(one,three));
	printList(mergeList(two,three));
	printList(mergeList(four, five));
	printList(mergeList(one, six));
	
	return 0;
}
