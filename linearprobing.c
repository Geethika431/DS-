#include <stdio.h>

#define MAX 100

int HT[MAX];
int m;


int hashFunction(int key)
{
    return key % m;
}


void insert(int key)
{
    int index = hashFunction(key);
    int start = index;

    while (HT[index] != -1)
    {
        index = (index + 1) % m;

        if (index == start)
        {
            printf("Hash Table is Full. Cannot insert key %d\n", key);
            return;
        }
    }

    HT[index] = key;
    printf("Key %d inserted at address %d\n", key, index);
}


void display()
{
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++)
    {
        if (HT[i] == -1)
            printf("HT[%d] = EMPTY\n", i);
        else
            printf("HT[%d] = %d\n", i, HT[i]);
    }
}

int main()
{
    int n, key;

    printf("Enter size of Hash Table (m): ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
        HT[i] = -1;

    printf("Enter number of employee records (N): ");
    scanf("%d", &n);

    printf("Enter %d employee keys (4-digit):\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}
