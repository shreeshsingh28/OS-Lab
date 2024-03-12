#include <iostream>
using namespace std;

int main()
{
    int bSize[10], pSize[10], bCount, pCount, allocation[10], i, j, full[10];
    for (i = 0; i < 10; i++)
        allocation[i] = -1; // -1 means not allocated

    cout << "Enter the number of blocks: ";
    cin >> bCount;
    cout << "Enter the size of each block: ";
    for (i = 0; i < bCount; i++)
    {
        cin >> bSize[i];
        full[i] = 0;
    }

    cout << "Enter the number of processes: ";
    cin >> pCount;
    cout << "Enter the size of each process: ";
    for (i = 0; i < pCount; i++)
        cin >> pSize[i];

    // First Fit algorithm
    for (i = 0; i < pCount; i++)
    {
        for (j = 0; j < bCount; j++)
        {
            if (bSize[j] >= pSize[i] && full[j] == 0)
            {
                full[j] = 1;
                allocation[i] = j;
                break;
            }
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock No.\n";
    for (i = 0; i < pCount; i++)
    {
        cout << " " << i + 1 << "\t\t" << pSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }

    return 0;
}
