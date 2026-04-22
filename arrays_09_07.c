#include <stdio.h>
#include <stdlib.h>

void ex_1()
{
    int lines, cols;
    printf("Enter lines and columns: ");
    scanf("%d %d", &lines, &cols);

    int **array;

    array = malloc(lines * sizeof(int *));

    for (int line = 0; line < lines; line++)
    {
        array[line] = malloc(cols * sizeof(int));
    }

    for (int i = 0; i < lines; i++)
        for (int j = 0; j < cols; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }

    for (int i = 0; i < lines; i++)
        for (int j = 0; j < cols - 1; j++)
            if (array[i][j] >= array[i][j + 1])
            {
                printf("Row %d is NOT ascending!\n", i);
                break;
            }

    for (int j = 0; j < cols; j++)
        for (int i = 0; i < lines - 1; i++)
            if (array[i][j] <= array[i + 1][j])
            {
                printf("Column %d is NOT descending!\n", j);
                break;
            }
}

void ex_2()
{
    int lines, cols;
    printf("Enter Lines and Columns: ");
    scanf("%d %d", &lines, &cols);

    int **array;

    array = malloc(lines * sizeof(int *));

    for (int line = 0; line < lines; line++)
    {
        array[line] = malloc(cols * sizeof(int));
    }

    for (int i = 0; i < lines; i++)
        for (int j = 0; j < cols; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }

    int max_sum = -99999999;
    int max_i = 0;
    int max_j = 0;

    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int sum = 0;
            // loop through all 8 neighbors using offsets
            for (int di = -1; di <= 1; di++)
            {
                // create offsets of [-1; 0; 1], going all through the matrix
                for (int dj = -1; dj <= 1; dj++)
                {
                    if (di == 0 && dj == 0)
                    {
                        continue; // skip self
                    }

                    int ni = i + di;

                    int nj = j + dj;

                    if ((ni >= 0 && ni < lines) && (nj >= 0 && nj < cols))
                        sum += array[ni][nj];
                }
            }
            if (sum > max_sum)
            {
                max_sum = sum;
                max_i = i;
                max_j = j;
            }
        }
    }

    printf("Element: %d at [%d][%d] with neighbor sum: %d\n",
           array[max_i][max_j], max_i, max_j, max_sum);
}

void ex_3()
{
    int n, m;
    printf("Enter N and M: ");
    scanf("%d %d", &n, &m);

    int **array;

    array = malloc(n * sizeof(int *));

    for (int line = 0; line < n; line++)
    {
        array[line] = malloc(m * sizeof(int));
    }

    int max_val = array[0][0], min_val = array[0][0];
    int max_row = 0, min_row = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (array[i][j] > max_val)
            {
                max_val = array[i][j];
                max_row = i;
            }
            if (array[i][j] < min_val)
            {
                min_val = array[i][j];
                min_row = i;
            }
        }

    // swap the two rows element by element
    for (int j = 0; j < m; j++)
    {
        int temp = array[max_row][j];
        array[max_row][j] = array[min_row][j];
        array[min_row][j] = temp;
    }

    printf("Result:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }
}

// For each person store their friends dynamically
void ex_4()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int *friend_count = calloc(n + 1, sizeof(int));
    int **friends = calloc(n + 1, sizeof(int *));
    for (int i = 0; i <= n; i++)
        friends[i] = malloc(m * sizeof(int)); // worst case everyone is friends

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        // friendship goes both ways
        friends[a][friend_count[a]++] = b;
        friends[b][friend_count[b]++] = a;
    }

    int person;
    printf("Query person: ");
    scanf("%d", &person);
    printf("%d has %d friends: ", person, friend_count[person]);
    for (int i = 0; i < friend_count[person]; i++)
        printf("%d ", friends[person][i]);
    printf("\n");

    for (int i = 0; i <= n; i++)
        free(friends[i]);
    free(friends);
    free(friend_count);
}

int main()
{
    //ex_2();

    return 0;
}
