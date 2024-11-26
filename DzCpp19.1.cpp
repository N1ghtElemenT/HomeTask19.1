#include <iostream>
using namespace std;

class String 
{
private:
	char* str;
	int length;
public:
	String()
	{
		const char* defaultStr = "HelloWorld";
		length = 80;
		str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			str[i] = defaultStr[i];
		}
		str[length] = '\0';
	}

	String(int size)
	{
		if (size <= 0)
		{
			cout << "Invalid." << endl;
			size = 80;
		}
		length = size;
		str = new char[length + 1];
		cout << "Enter the string: ";
		cin >> str;
	}

	String(const char* inputStr)
	{
		length = 0;
		while (inputStr[length] != '\0')
		{
			length++;
		}
		str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			str[i] = inputStr[i];
		}
		str[length] = '\0';
	}

	~String()
	{
		delete[] str;
	}

	void display() const
	{
		cout << "String: " << str << endl;
	}
};

int main()
{
	String str;
	str.display();

	int size;

	cout << "Enter the length of the string: ";
	cin >> size;

	String strSize(size);
	strSize.display();

	char userInput[100];
	cout << "Enter the string for initialization: ";
	cin >> userInput;

	String strInitialized(userInput);
	strInitialized.display();

	return 0;
}