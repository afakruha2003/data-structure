// #include <iostream>
// #include <iomanip>
// #include <algorithm>
// #include <array>
// #include <string>
// using namespace std;

// int main()
// {
//     int row1, column1, row2, column2;

//     cout << "please enter dimentions for first matrix" << endl;
//     cin >> row1 >> column1;
//     int **mat1 = new int *[row1];
//     mat1[row1] = new int[column1];
//     cout << "please enter the matrix values" << endl;
//     for (size_t i = 0; i < row1; i++)
//     {
//         for (size_t j = 0; j < column1; j++)
//         {
//             cin >> mat1[i][j];
//         }
//         cout << endl;
//     }
   
//     cout << "please enter dimentions for second matrix" << endl;
//     cin >> row2 >> column2;
//     int **mat2 = new int *[row2];
//     mat2[row2] = new int[column2];
//     cout << "please enter the matrix values" << endl;
//     for (size_t a = 0; a < row2; a++)
//     {
//         for (size_t b = 0; b < column2; b++)
//         {
//             cin >> mat2[a][b];
//         }
//         cout << endl;
//     }
// delete[] mat2;
//     if ((row1 == row2) && (column1 == column2))
//     {
//         int **result = new int *[row2];
//         result[row2] = new int[column2];

//         for (size_t i = 0; i < row2; i++)
//         {
//             for (size_t j = 0; j < column2; j++)
//             {
//                 result[i][j] = mat1[i][j] + mat2[i][j];
//             }
//         }
//         cout << "the result of the sum of the matrices " << endl;
//         for (size_t a = 0; a < row1; a++)
//         {
//             for (size_t b = 0; b < column1; b++)
//             {
//                 cout << result[a][b];
//             }
//             cout << endl;
//         }
//     }
//      delete[] mat1;
// }


#include <iostream>
using namespace std;

int main()
{
    int row1, column1, row2, column2;

    // İlk matrisin boyutlarını al
    cout << "Please enter dimensions for first matrix (rows and columns): ";
    cin >> row1 >> column1;

    // İlk matris için bellek tahsisi
    int **mat1 = new int *[row1];
    for (int i = 0; i < row1; i++)
    {
        mat1[i] = new int[column1];
    }

    // İlk matrisin elemanlarını al
    cout << "Please enter the values for the first matrix:" << endl;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column1; j++)
        {
            cin >> mat1[i][j];
        }
    }

    // İkinci matrisin boyutlarını al
    cout << "Please enter dimensions for second matrix (rows and columns): ";
    cin >> row2 >> column2;

    // İkinci matris için bellek tahsisi
    int **mat2 = new int *[row2];
    for (int i = 0; i < row2; i++)
    {
        mat2[i] = new int[column2];
    }

    // İkinci matrisin elemanlarını al
    cout << "Please enter the values for the second matrix:" << endl;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < column2; j++)
        {
            cin >> mat2[i][j];
        }
    }

    // Eğer matrisler aynı boyutta ise toplama işlemini yap
    if (row1 == row2 && column1 == column2)
    {
        // Sonuç matrisi için bellek tahsisi
        int **result = new int *[row1];
        for (int i = 0; i < row1; i++)
        {
            result[i] = new int[column1];
        }

        // Matrisleri topla
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < column1; j++)
            {
                result[i][j] = mat1[i][j] + mat2[i][j];
            }
        }

        // Sonuç matrisini yazdır
        cout << "The result of the sum of the matrices is:" << endl;
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < column1; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }

        // Sonuç matrisinin belleğini serbest bırak
        for (int i = 0; i < row1; i++)
        {
            delete[] result[i];
        }
        delete[] result;
    }
    else
    {
        cout << "Matrices must have the same dimensions to be added." << endl;
    }

    // Matrislerin belleğini serbest bırak
    for (int i = 0; i < row1; i++)
    {
        delete[] mat1[i];
    }
    delete[] mat1;

    for (int i = 0; i < row2; i++)
    {
        delete[] mat2[i];
    }
    delete[] mat2;

    return 0;
}




