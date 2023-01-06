#include <stdio.h>

int main()
{
    int row, col;
    printf("Enter the no of rows : ");
    scanf("%d", &row);

    printf("Enter the no of columns : ");
    scanf("%d", &col);

    int sparseMatrix[row][col];

    printf("\nEnter elements of matrix\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &sparseMatrix[i][j]);
        }
    }

    // calc non zero elements
    int size = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (sparseMatrix[i][j] != 0)
                size++;
        }
    }

    if(size >= (row*col/2))
    {
        printf("Given Matrix/Array is not sparse\n");
        return 0;
    }

    int compactMatrix[size][3];

    int k = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (sparseMatrix[i][j] != 0)
            {
                compactMatrix[k][0] = i;
                compactMatrix[k][1] = j;
                compactMatrix[k][2] = sparseMatrix[i][j];
                k++;
            }
        }
    }

    printf("\n\ni: row no\nj: col no\ne: element at index (i,j) in original matrix\n\ni j e\n");

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", compactMatrix[i][j]);

        printf("\n");
    }
    return 0;
}
