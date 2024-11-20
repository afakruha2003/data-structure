#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <string>
#include <math.h>
using namespace std;
static int x{0};
const int size1{5};
int maxNumber(int *);
double average(int *);
void swap(int *, int *);
int occurTimes(int *, int);
double standartDeviation(int *);
int *shiftOnePosition(int *);
int *shiftManyPosition(int *, int);


array<int, size1> array1;

int main()
{

    int numbers[size1];
    for (size_t i = 0; i < 5; i++)
    {
        cout << "enter number" << i + 1 << "  ";
        cin >> numbers[i];
    }

    for (size_t i = 0; i < 5; i++)
    {
        cout << "the array's " << i + 1 << ".  value is : " << numbers[i] << endl;
    }
    sort(numbers, numbers + size1);
    cout << "the standart deviation : " << standartDeviation(numbers) << endl;
    cout << "the minimum value is : " << numbers[0] << endl;
    cout << "the max value is : " << maxNumber(numbers) << endl;
    cout << "the average value is : " << average(numbers) << endl;
    shiftOnePosition(numbers);
    for (size_t i = 0; i < 5; i++)
    {
        cout << "the array's " << i + 1 << ".  value  after shifting is : " << numbers[i] << endl;
    }
    int shiftNum;
    cout << "what the number you want to shift ? " << endl;
    cin >> shiftNum;
    shiftManyPosition(numbers, shiftNum);
    for (size_t i = 0; i < 5; i++)
    {
        cout << "the array's " << i + 1 << ".  value  after shifting is : " << numbers[i] << endl;
    }
    int occur;
    cout << "enter the number the you want to know its occur times" << endl;
    cin >> occur;
    cout << occurTimes(numbers, occur) << endl;

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int maxNumber(int *array1)
{
    for (size_t i = 0; i < size1; i++)
    {
        if (array1[i] > array1[i + 1])
        {
            swap(array1[i], array1[i + 1]);
        }
    }
    return array1[size1 - 1];
}

double average(int *array1)
{
    double total{0};
    for (size_t i = 0; i < 5; i++)
    {
        total += array1[i];
    }
    double averge = total / 5;
    return averge;
}
int occurTimes(int *array1, int num = 0)
{

    int count{0};

    for (size_t j = 0; j < 5; j++)
    {

        if (num == array1[j])
        {

            count++;
        }
    }
    cout << num << " number occur " << count << " times" << endl;
    return count;
}
double standartDeviation(int *array1)
{
    double total{0};
    for (size_t i = 0; i < size1; i++)
    {

        total += pow(array1[i] - average(array1), 2);
    }
    double value{0};
    value = total / size1;
    return sqrt(value);
}
int *shiftOnePosition(int *array1)
{

    for (size_t i = 0; i < 4; i++)
    {
        swap(array1[0], array1[i + 1]);
    }

    return array1;
}
int *shiftManyPosition(int *array1, int a)
{
    for (size_t i = 0; i < a-1 ; i++)
    {

        for (size_t j = 0; j < 4; j++)
        {
            swap(array1[0], array1[j + 1]);
        }
    }

    return array1;
}
