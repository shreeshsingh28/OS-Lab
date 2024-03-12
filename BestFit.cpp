#include <iostream>
using namespace std;

int main()
{
    int block_size[10], process_size[10], allocation[10],full[10];
    int nblocks, nprocess, i, j, best_block;

    for (int i = 0; i < 10; i++)
        allocation[i] = -1;

    cout << "Enter the number of memory blocks: ";
    cin >> nblocks;

    cout << "Enter the size of each block: ";
    for (i = 0; i < nblocks; i++)
    {
        cin >> block_size[i];
        full[i] = 0;
    }
    

    cout << "Enter the number of processes: ";
    cin >> nprocess;

    cout << "Enter the size of each process: ";
    for (i = 0; i < nprocess; i++)
        cin >> process_size[i];


    // allocate memory to each process
    for (i = 0; i < nprocess; i++)
    {
        best_block = -1;                    //to find best block for the process
        for (j = 0; j < nblocks; j++)
        {
            if (block_size[j] >= process_size[i] && full[j] == 0)
            {
                if (best_block == -1 || block_size[j] < block_size[best_block]) //for worst fit change comparission sign
                {
                    best_block = j;
                }
            }
        }
            full[best_block] = 1;
            allocation[i] = best_block;
    }

    // print allocation
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (i = 0; i < nprocess; i++)
    {
        cout << " " << i + 1 << "\t\t" << process_size[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1;
        }
        else
        {
            cout << "Not Allocated";
        }
        cout << endl;
    }

    return 0;
}
