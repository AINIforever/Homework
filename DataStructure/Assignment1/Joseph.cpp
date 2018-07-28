#include <iostream>
using namespace std;

struct Node {
	Node(int data) :m_data(data), m_pNext(NULL) {}
	int m_data;
	Node *m_pNext;
};

class Joseph {
public:
	Joseph(int N, int R) :m_N(N), m_R(R) {
		createList();
		resultList();
	}
protected:
	void createList();
	void resultList();
private:
	Node *m_pHead;
	int m_N;
	int m_R;
};
void Joseph::createList() {
	Node *pre = NULL;
	Node *current = NULL;
	Node *p = new Node(1);
	m_pHead = p;
	current = p;
	//create the list and each node, this is one-direction
	for (int i = 2; i <= m_N; i++) {
		p = new Node(i);
		pre = current;
		current = p;
		pre->m_pNext = p;
	}
	//let the list be a circle
	current->m_pNext = m_pHead;

}
void Joseph::resultList() {
	Node *pBegin = m_pHead;
	Node *pTemp = pBegin;
	Node *pPre = NULL;
	Node *pOut = NULL;

	while (pTemp->m_pNext != pTemp) {
		//find the leave man
		int count = 1;
		while (count < m_R) {
			pPre = pTemp;
			pTemp = pTemp->m_pNext;
			count++;
		}
		pOut = pTemp;
		pTemp = pTemp->m_pNext;
		pPre->m_pNext = pTemp;
		cout << pOut->m_data << endl;
	}
	cout << pTemp->m_data << endl;
}

int main() {
	int Num;
	int R;
	cout << "How many people in the ring?" << endl;
	cin >> Num;
	cout << "What's your R?" << endl;
	cin >> R;
	Joseph joseph(Num, R);
	getchar();
	return 0;
}