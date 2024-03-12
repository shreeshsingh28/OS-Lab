#include <iostream>
#include <cstdlib>
using namespace std;

void print(int x[][10], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        cout << endl;
        for (j = 0; j < m; j++)
        {
            cout << x[i][j] << "\t";
        }
    }
}

// Resource Request algorithm
void res_request(int A[10][10], int N[10][10], int AV[10][10], int pid, int m)
{
    cout << "Resource-Request Algorithm";
    int reqmat[1][10];
    int i;
    cout << "\nEnter additional request :- \n";
    for (i = 0; i < m; i++)
    {
        cout << N[pid][i] << " Request for resource " << i + 1 << " : ";
        cin >> reqmat[0][i];
    }

    for (i = 0; i < m; i++)
    {
        if (reqmat[0][i] > N[pid][i])
        {
            cout << "\nError encountered.\n";
            exit(0);
        }
    }

    for (i = 0; i < m; i++)
    {
        if (reqmat[0][i] > AV[0][i])
        {
            cout << "\nResources unavailable.\n";
            exit(0);
        }
    }

    for (i = 0; i < m; i++)
    {
        AV[0][i] -= reqmat[0][i];
        A[pid][i] += reqmat[0][i];
        N[pid][i] -= reqmat[0][i];
    }
}

// Safety algorithm
int safety(int A[][10], int N[][10], int AV[1][10], int n, int m, int a[])
{
    cout << "Safety Algorithm";
    int i, j, k = 0, x = 0;
    int Finish[10], W[1][10];
    int pflag = 0, flag = 0;
    for (i = 0; i < n; i++)
        Finish[i] = 0;
    for (i = 0; i < m; i++)
        W[0][i] = AV[0][i];

    while(k < n)
    {
        for (i = 0; i < n; i++)
        {
            if (Finish[i] == 0)
            {
                flag = 1;
                for (j = 0; j < m; j++)
                {
                    if (N[i][j] > W[0][j])
                        flag = 0;
                }
                if (flag)
                {
                    for (j = 0; j < m; j++)
                        W[0][j] += A[i][j];

                    Finish[i] = 1;
                    pflag++;
                    a[x++] = i;
                }
            }
        }
        k++;
    }
    if (pflag == n)
        return 1;
    else
        return 0;
}

void accept(int A[][10], int N[][10], int M[10][10], int W[1][10], int *n, int *m)
{
    int i, j;
    cout << "\nEnter total no. of processes : ";
    cin >> *n;
    cout << "\nEnter total no. of resources : ";
    cin >> *m;
    for (i = 0; i < *n; i++)
    {
        cout << "\nProcess " << i << endl;
        for (j = 0; j < *m; j++)
        {
            cout << "Allocation for resource " << j + 1 << " : ";
            cin >> A[i][j];
            cout << "Maximum for resource " << j + 1 << " : ";
            cin >> M[i][j];
        }
    }
    cout << "\nAvailable resources : \n";
    for (i = 0; i < *m; i++)
    {
        cout << "Resource " << i << " : ";
        cin >> W[0][i];
    }

    for (i = 0; i < *n; i++)
        for (j = 0; j < *m; j++)
            N[i][j] = M[i][j] - A[i][j];

    cout << "\nAllocation Matrix\n";
    print(A, *n, *m);
    cout << "\nMaximum Requirement Matrix\n";
    print(M, *n, *m);
    cout << "\nNeed Matrix\n";
    print(N, *n, *m);
}

int banker(int A[][10], int N[][10], int W[1][10], int n, int m)
{
    int j, i, a[10];
    j = safety(A, N, W, n, m, a);
    if (j != 0)
    {
        cout << "\n\n";
        for (i = 0; i < n; i++)
            cout << "P" << a[i] << "  ";
        cout << "\nA safety sequence has been detected.\n";
        return 1;
    }
    else
    {
        cout << "\nDeadlock has occurred.\n";
        return 0;
    }
}

int main()
{
    int ret;
    int A[10][10];
    int M[10][10];
    int N[10][10];
    int W[1][10];
    int n, m, pid, ch;
    cout << "\nDEADLOCK AVOIDANCE USING BANKER'S ALGORITHM\n";
    accept(A, N, M, W, &n, &m);
    ret = banker(A, N, W, n, m);
    if (ret != 0)
    {
        cout << "\nDo you want make an additional request ? (1=Yes|0=No)";
        cin >> ch;
        if (ch == 1)
        {
            cout << "\nEnter process no. : ";
            cin >> pid;
            res_request(A, N, W, pid, m);
            ret = banker(A, N, W, n, m);
            if (ret == 0)
                exit(0);
        }
    }
    else
        exit(0);
    return 0;
}
