#include <stdio.h>

void inputMatrix(int arr[10][10], int r, int c)
{
    printf("Elements : ");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

void inputRnC(int *r1, int *c1, int *r2, int *c2)
{
    printf("Enter rows and column for 1st matrix : ");
    scanf("%d %d", r1, c1);
    printf("Enter rows and column for 2nd matrix : ");
    scanf("%d %d", r2, c2);
}
void print(int arr[10][10], int r, int c)
{
    printf("\n<---Result--->\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void add(int arr1[10][10], int arr2[10][10], int res[10][10], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            res[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

void transpose(int arr[10][10], int r, int c)
{
    for (int i = 1; i < r; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
}

void multiply(int arr1[10][10], int arr2[10][10], int res[10][10], int r1, int c1, int r2, int c2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

int main()
{
    int Matrix_1[10][10], Matrix_2[10][10], Result[10][10];
    int r1, c1, r2, c2;

    int option, flag = 1;

    while (flag)
    {
        printf("Matrix operations menu.\n1. Addition\n2. Transpose\n3. Multiplication\n4. Exit\nChoose a matrix operation : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            inputRnC(&r1, &c1, &r2, &c2);
            if (r1 != r2 || c1 != c2)
            {
                printf("The rows and columns do not match.\n ");
                break;
            }
            inputMatrix(Matrix_1, r1, c1);
            inputMatrix(Matrix_2, r2, c2);
            add(Matrix_1, Matrix_2, Result, r1, c1);
            print(Result, r1, c1);
            break;

        case 2:
            printf("Enter rows and columns for matrix : ");
            scanf("%d %d", &r1, &c1);
            if (r1 != c1)
            {
                printf("Invalid input.\n");
                break;
            }
            inputMatrix(Result, r1, c1);
            transpose(Result, r1, c1);
            print(Result, r1, c1);
            break;

        case 3:
            inputRnC(&r1, &c1, &r2, &c2);
            if (c1 != r2)
            {
                printf("The rows and columns do not match.\n ");
                break;
            }
            inputMatrix(Matrix_1, r1, c1);
            inputMatrix(Matrix_2, r2, c2);
            multiply(Matrix_1, Matrix_2, Result, r1, c1, r2, c2);
            print(Result, r1, c1);
            break;

        case 4:
            flag = 0;
            break;

        default:
            printf("Choose a valid option.\n");
            break;
        }
    }

    return 0;
}