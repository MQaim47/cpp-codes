#include<iostream>
using namespace std;
int main()
{
	int number = 0, index = 0, length = 0;
	int RollNumber[5] = {}, maths[5] = {}, CS[5] = {}, percentage[5] = {};
	char ch = 'y';
	cout << "**************************WELCOME TO ADMIN PANEL*********************************" << endl << endl << endl;
	while ((length < 5 && ch == 'y' || ch == 'Y'))
	{
		cout << "Enter Roll Number of Student " << length + 1 << ":";
		cin >> RollNumber[length];
		do
		{
			cout << "Enter Mathematics Marks of Student " << length + 1 << " within 100:";
			cin >> maths[length];
			cout << "Enter Computer Science Marks of Student " << length + 1 << " within 100:";
			cin >> CS[length];
			cout << endl;
		} while (maths[length]>100 || CS[length]>100);
		length++;
		if (length < 5)
		{
			cout << "Press Y/y to continue or N/n to stop---";
			cin >> ch;
			cout << endl << endl;
		}
	}
	char grade[5] = {};
	for (int i = 0; i < length; i++)
		percentage[i] = ((maths[i] + CS[i]) / 2);
	for (int i = 0; i < length; i++)
	{
		if (percentage[i] >= 50 && percentage[i] <= 59)
			grade[i] = 'D';
		else if (percentage[i] >= 60 && percentage[i] <= 74)
			grade[i] = 'C';
		else if (percentage[i] >= 75 && percentage[i] <= 89)
			grade[i] = 'B';
		else if (percentage[i] >= 90 && percentage[i] <= 100)
			grade[i] = 'A';
		else
			grade[i] = 'F';
	}
	cout << "Do you want to continue to perform advance operations?" << endl;
	cout << "Press Y/y for yes..." << endl;
	cout << "Press N/n for no..." << endl;
	cin >> ch;
	cout << endl;
	if (ch == 'n' || ch == 'N')
	{
		cout << "Roll Number    " << "Maths Marks    " << "Computer Science Marks   " << "Percentage    " << "   Grade ";
		for (int i = 0; i < length; i++)
		{
			cout << endl;
			cout << "     " << RollNumber[i];
			cout << "         " << maths[i];
			cout << "             " << CS[i];
			cout << "                      " << percentage[i];
			cout << "		" << grade[i] << endl << endl;
		}

	}
	else if (ch == 'y' || ch == 'Y')
	{
		while (1)
		{
			cout << "Press '1' to update the roll number of a student" << endl;
			cout << "Press '2' to update Maths marks of a student" << endl;
			cout << "Press '3' to update the Maths marks of all students" << endl;
			cout << "Press '4' to update Computer Science marks of a student" << endl;
			cout << "Press '5' to update Computer Science of all student" << endl;
			cout << "Press '6' to Sort the Data by percentages" << endl;
			cout << "Press '7' to Delete the data of a student" << endl << endl;
			cout << "--- ";
			cin >> ch;
			cout << endl;
			if (ch >= '1'&& ch <= '7')
				break;
			else
				cout << "Invalid Value" << endl;
		}
		if (ch == '3' || ch == '5')
		{
			if (ch == '3')
			for (int i = 0; i < length; i++)
			{
				cout << "Enter Maths Marks of a Student" << i << " within 100 ";
				cin >> maths[i];
				if (maths[i]>100)
					i--;
			}
			else
			for (int i = 0; i < length; i++)
			{
				cout << "Enter Computer Scince Marks of a Student" << i << " within 100 ";
				cin >> CS[i];
				if (CS[i]>100)
					i--;
			}
		}
		else if (ch == '6')
		{
			int temp;
			for (int i = 0; i < length; i++)
			{
				for (int j = i + 1; j < length; j++)
				{
					if (percentage[i]>percentage[j])
					{
						temp = RollNumber[i];
						RollNumber[i] = RollNumber[j];
						RollNumber[j] = temp;

						temp = maths[i];
						maths[i] = maths[j];
						maths[j] = temp;

						temp = CS[i];
						CS[i] = CS[j];
						CS[j] = temp;

						temp = percentage[i];
						percentage[i] = percentage[j];
						percentage[j] = temp;

						temp = grade[i];
						grade[i] = grade[j];
						grade[j] = temp;
					}
				}
			}
		}
		else
		{
			cout << "Enter the Student Roll Number:: ";
			cin >> number;
			cout << endl << endl;
			for (int i = 0; i < length; i++)
			if (RollNumber[i] == number)
			{
				index = i;
				break;
			}
			switch (ch)
			{
			case '1':
				cout << "Enter new Roll Number a student: ";
				cin >> RollNumber[index];
				break;

			case '2':
				while (1)
				{
					cout << "Enter new Maths marks of a student which should be less than 100: ";
					cin >> maths[index];
					if (maths[index] <= 100)
						break;

			case '4':
				while (1)
				{
					cout << "Enter new Computer Science marks of a student which should be less than 100 : ";
					cin >> CS[index];
					if (CS[index] <= 100)
						break;


			case '7':
				int temp;
				for (int i = index; i < (length - 1); i++)
				{
					temp = RollNumber[i];
					RollNumber[i] = RollNumber[i + 1];
					RollNumber[i + 1] = temp;

					temp = maths[i];
					maths[i] = maths[i + 1];
					maths[i + 1] = temp;

					temp = CS[i];
					CS[i] = CS[i + 1];
					CS[i + 1] = temp;

					temp = percentage[i];
					percentage[i] = percentage[i + 1];
					percentage[i + 1] = temp;

					temp = grade[i];
					grade[i] = grade[i + 1];
					grade[i + 1] = temp;
				}
				cout << "The Data of Roll Number: " << number << "is deleted" << endl << endl;
				length--;
				break;
				}
				}
			}
			cout << endl;
			cout << "Roll Number    " << "Maths Marks    " << "Computer Science Marks   " << "Percentage    " << "   Grade ";
			for (int i = 0; i < length; i++)
			{

				cout << endl;
				cout << "     " << RollNumber[i];
				cout << "         " << maths[i];
				cout << "             " << CS[i];
				cout << "                      " << percentage[i];
				cout << "		" << grade[i] << endl << endl;
			}
		}
	}

	return 0;
}