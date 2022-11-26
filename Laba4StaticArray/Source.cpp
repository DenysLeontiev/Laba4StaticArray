#include<iostream>
#include<time.h>
#include <vector>

using namespace std;

const int arrSize = 5;

void generate2DArray(const int& size, int  static2DArr[arrSize][arrSize]);
void outputArray(const int& size, int  static2DArr[arrSize][arrSize]);
//int getLeftMinimal(int** arr, int arraySize);
//int getRightMaximum(int** arr, int arraySize);
void swapAndGetLeftMinRightMax(int arr[][arrSize], int arraySize, int& leftMin, int& rightMax);
float averageValue(int a, int b);

void main()
{
	srand(time(NULL)); // NULL == 0

	int static2DArr[arrSize][arrSize];
	generate2DArray(arrSize, static2DArr);

	cout << "Before Swap" << endl;
	cout << endl;
	outputArray(arrSize, static2DArr);
	cout << endl;

	int leftMin;
	int rightMax;

	swapAndGetLeftMinRightMax(static2DArr, arrSize, leftMin, rightMax);

	cout << "leftMin = " << leftMin << endl;
	cout << "rightMax = " << rightMax << endl;
	cout << endl;

	cout << "After Swap" << endl;
	cout << endl;

	outputArray(arrSize, static2DArr);
	cout << endl;

	double averageValue = (double)(leftMin + rightMax) / 2;
	cout << "Average value is equal to " << averageValue;
	cout << endl;

	system("pause");
}

void outputArray(const int& size, int  static2DArr[arrSize][arrSize])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << static2DArr[i][j] << "\t";
		}

		cout << endl;
	}
}

void generate2DArray(const int& size, int  static2DArr[arrSize][arrSize])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			static2DArr[i][j] = rand() % 20;
		}
	}
}

void swapAndGetLeftMinRightMax(int arr[][arrSize], int arraySize, int& leftMin, int& rightMax)
{
	int iMin = 1, jMin = 0;
	int iMax = 0, jMax = 1;


	leftMin = arr[1][0];
	rightMax = arr[0][1];

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			if (i > j)
			{
				if (leftMin > arr[i][j])
				{
					leftMin = arr[i][j];
					iMin = i;
					jMin = j;
				}
			}
			else if (j > i)
			{
				if (rightMax < arr[i][j])
				{
					rightMax = arr[i][j];
					iMax = i;
					jMax = j;
				}
			}
		}
	}

	int temp = arr[iMin][jMin];
	arr[iMin][jMin] = arr[iMax][jMax];
	arr[iMax][jMax] = temp;
}

float averageValue(int a, int b)
{
	return (float)(a + b) / 2;
}

//int getLeftMinimal(int** arr, int arraySize)
//{
//	int leftMin = arr[1][0];
//	for (int i = 0; i < arraySize; i++)
//	{
//		for (int j = 0; j < arraySize; j++)
//		{
//			if (i > j)
//			{
//				if (leftMin > arr[i][j])
//				{
//					leftMin = arr[i][j];
//				}
//			}
//		}
//	}
//
//	return leftMin;
//}
//
//int getRightMaximum(int** arr, int arraySize)
//{
//	int rightMax = arr[0][1];
//	for (int i = 0; i < arraySize; i++)
//	{
//		for (int j = 0; j < arraySize; j++)
//		{
//			if (j > i)
//			{
//				if (rightMax < arr[i][j])
//				{
//					rightMax = arr[i][j];
//				}
//			}
//		}
//	}
//
//	return rightMax;
//}

