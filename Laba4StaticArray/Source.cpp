#include<iostream>
#include<time.h>
#include <vector>

using namespace std;

const int arrSize = 5;

void generate2DArray(int, int [][arrSize]);
void outputArray(int size, int  static2DArr[arrSize][arrSize]);
void swapAndGetLeftMinRightMax(int arr[][arrSize], int arraySize, int& leftMin, int& rightMax);
float averageValue(int a, int b);
int setValue(const char v[]);

int main()
{
	int actualSize = 0;
	do
	{
		actualSize = setValue("actualSize");
	} while (actualSize > arrSize || actualSize <= 1);

	srand((unsigned)time(NULL)); // NULL == 0

	int static2DArr[arrSize][arrSize];
	generate2DArray(actualSize, static2DArr);

	cout << "Before Swap" << endl;
	cout << endl;
	outputArray(actualSize, static2DArr);
	cout << endl;

	int leftMin;
	int rightMax;

	swapAndGetLeftMinRightMax(static2DArr, actualSize, leftMin, rightMax);

	cout << "leftMin = " << leftMin << endl;
	cout << "rightMax = " << rightMax << endl;
	cout << endl;

	cout << "After Swap" << endl;
	cout << endl;

	outputArray(actualSize, static2DArr);
	cout << endl;

	double averageValue = (double)(leftMin + rightMax) / 2;
	cout << "Average value is equal to " << averageValue;
	cout << endl;

	system("pause");
	return 0;
}

void outputArray(int actualSize, int  static2DArr[arrSize][arrSize])
{
	for (int i = 0; i < actualSize;i++)
	{
		for (int j = 0; j < actualSize; j++)
		{
			cout << *(*(static2DArr + i) + j) << "\t";
			//cout << static2DArr[i][j] << "\t";
		}

		cout << endl;
	}
}

void generate2DArray(int size, int  static2DArr[][arrSize])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			//static2DArr[i][j] = rand() % 20;
			*(*(static2DArr + i) + j) = rand() % 20;
		}
	}
}

void swapAndGetLeftMinRightMax(int arr[][arrSize], int actualSize, int& leftMin, int& rightMax)
{
	int iMin = 1, jMin = 0;
	int iMax = 0, jMax = 1;


	leftMin = *(*(arr + 1) + 0);
	rightMax = *(*(arr + 0) + 1);
	//leftMin = arr[1][0];
	//rightMax = arr[0][1];

	for (int i = 0; i < actualSize; i++)
	{
		for (int j = i + 1; j < actualSize; j++)
		{
			if (arr[i][j] > rightMax)
			{
				iMax = i;
				jMax = j;
				rightMax = arr[i][j];
			}
			if (arr[j][i] < leftMin)
			{
				leftMin = arr[j][i];
				iMin = j;
				jMin = i;
			}
			//if (i > j)
			//{
			//	if (leftMin > /*arr[i][j]*/ *(*(arr + i) + j))
			//	{
			//		//leftMin = arr[i][j];
			//		leftMin = *(*(arr + i) + j);
			//		iMin = i;
			//		jMin = j;
			//	}
			//}
			//else if (j > i)
			//{
			//	if (rightMax < /*arr[i][j]*/ *(*(arr + i) + j))
			//	{
			//		//rightMax = arr[i][j];
			//		rightMax = *(*(arr + i) + j);
			//		iMax = i;
			//		jMax = j;
			//	}
			//}
		}
	}

	/*int temp = arr[iMin][jMin];
	arr[iMin][jMin] = arr[iMax][jMax];
	arr[iMax][jMax] = temp;*/

	int temp = *(*(arr + iMin) + jMin);
	*(*(arr + iMin) + jMin) = *(*(arr + iMax) + jMax);
	*(*(arr + iMax) + jMax) = temp;
}

float averageValue(int a, int b)
{
	return (float)(a + b) / 2;
}

int setValue(const char v[])
{
	int error;
	int value;
	do
	{
		error = 0;
		cout << "Please enter " << v << " = ";
		cin >> value;
		if (cin.fail())
		{
			cout.clear();
			cout << "Please enter a valid number" << endl;
			error = 1;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error == 1);

	return value;
}