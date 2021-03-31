#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 10000

class Array
{
public:
	int arr[MAX_SIZE];
	int index;
	Array()
	{
		for (int i = 0; i < MAX_SIZE; i++)
			arr[i] = 0; //0은 비어있음을 뜻함
		index = 0;
	}
	int at(int index)
	{
		return arr[index];
	}
	void set(int index, int data)
	{
		if (index > this->index)
			cout << "0" << endl;
		else
			arr[index] = data;
	}
	void add(int index, int data)
	{
		if (index > this->index)
			arr[this->index++] = data;
		else
		{
			for (int i = this->index; i > index; i--)
				arr[i + 1] = arr[i];
			arr[index] = data;
			this->index++;
		}
	}
};

int main()
{
	int m;
	cin >> m;

	Array *arr = new Array();

	while (m--)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "at")
		{
			int index;
			cin >> index;
			cout << arr->at(index) << endl;
		}
		else if (cmd == "set")
		{
			int index, data;
			cin >> index >> data;
			arr->set(index, data);
		}
		else if (cmd == "add")
		{
			int index, data;
			cin >> index >> data;
			arr->add(index, data);
		}
	}

	return 0;
}