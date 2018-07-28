#include <stack>
#include<iostream>  

using namespace std;

int resultList[100] = { 0 };
bool isUsed[100] = {false};
bool isSitted[100] = { false };

int length;
int lengthTest;
stack <int> s;


void myList(int pos, int use)
{

	if (use == length)
	{
		for (int i = 1; i <= length * 2; i++)
		{
			cout << resultList[i]<<" ";
		}
		cout << endl;
		return;
	}

	if (isSitted[pos] && pos < 2 * length)
	{
		myList(pos + 1, use);
	}
	else
	{
		for (int i = 1; i <= length; i++)
		{
			if (!isUsed[i] && !isSitted[pos + i + 1] && (pos + i + 1) <= 2 * length)
			{
				s.push(resultList[pos]);
				s.push(resultList[pos + i + 1]);

				resultList[pos] = i;
				resultList[pos + i + 1] = i;
				isUsed[i] = true;
				isSitted[pos] = true;
				isSitted[pos + i + 1] = true;

				myList(pos + 1, use + 1);
				resultList[pos + i + 1] = s.top();
				s.pop();
				resultList[pos] = s.top();
				s.pop();
				isUsed[i] = false;
				isSitted[pos] = false;
				isSitted[pos + i + 1] = false;
			}
		}
	}

}

int main()
{
	while (true) {
		cout << "Please enter your length of your sequence(enter 0 to exit)" << endl;

		cin >> lengthTest;
		if (lengthTest == 0) {
			break;
		}
		if ((lengthTest % 4 == 1) || (lengthTest % 4) == 2) {
			cout << "There are no sequence that match the condition" << endl;
			continue;
		}
		else {
			length = lengthTest;
			cout << "All of the possible result sequences are:" << endl;
		}

		myList(1, 0);
		continue;
	}
	
	system("pause");
	return 0;
}

