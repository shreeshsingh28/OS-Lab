#include <bits/stdc++.h>
using namespace std;

int choice, track, no_req, head, head1, distance;
int disc_req[100], finish[100];

void sstf()
{
    int min, diff;
    int pending = no_req;
    int i, distance = 0, index;
    head = head1;

    for (i = 0; i < no_req; i++)
    {
        finish[i] = 0;
    }

    cout << "\n"
         << head << "=>";

    while (pending > 0)
    {
        min = 9999;

        for (i = 0; i < no_req; i++)
        {
            diff = abs(head - disc_req[i]);
            if (finish[i] == 0 && diff < min)
            {                                     //getting index of min distance diff.
                min = diff;
                index = i;
            }
        }
        finish[index] = 1;
        distance += abs(head - disc_req[index]);
        head = disc_req[index];
        pending--;
        cout << head << "=>";
    }
    cout << "End";
    cout << "\n\nTotal Distance Traversed = " << distance;
}

void scan()
{
    int index, dir;
    int i, distance = 0;
    head = head1;
    cout << "\nEnter the direction of head \n1 - Towars higher disc(Right)\n0 - towards lower disc(left): ";
    cin >> dir;
    
    std::sort(disc_req, disc_req + no_req);
    cout << "\nSorted Disc requests are: ";
    for (i = 0; i < no_req; i++)
        cout << "  " << disc_req[i];

    i = 0;
    while (head >= disc_req[i])
    {
        index = i;
        i++;
    }
    cout << "\nindex=" << index;
    cout << "\n"
         << head << "=>";
    
    if (dir == 1)
    {
        for (i = index + 1; i < no_req; i++)
        {
            cout << disc_req[i] << "=>";
            distance += abs(head - disc_req[i]);
            head = disc_req[i];
        }
        distance += abs(head - (track - 1));
        cout << track - 1 << "=>";
        head = track - 1;
        for (i = index; i >= 0; i--)
        {
            cout << disc_req[i] << "=>";
            distance += abs(head - disc_req[i]);
            head = disc_req[i];
        }
    }
    else
    {
        for (i = index; i >= 0; i--)
        {
            cout << disc_req[i] << "=>";
            distance += abs(head - disc_req[i]);
            head = disc_req[i];
        }
        distance += abs(head - 0);
        head = 0;
        cout << "0=>";
        for (i = index + 1; i < no_req; i++)
        {
            cout << disc_req[i] << "=>";
            distance += abs(head - disc_req[i]);
            head = disc_req[i];
        }
    }
    cout << "End";
    cout << "\nTotal Distance Traversed = " << distance;
}

void clook()
{
    int index, dir;
    int i, distance = 0;
    head = head1;
    cout << "\n Enter the direction of head \n 1 - Towars higher disc \n 0 -towards lower disc";
    cin >> dir;
    
    std::sort(disc_req, disc_req + no_req);
    cout << "\n Sorted Disc requests are: ";
    for (i = 0; i < no_req; i++)
        cout << "  " << disc_req[i];
    
    i = 0;
    while (head >= disc_req[i])
    {
        index = i;
        i++;
    }
    
    cout << "\n index=" << index;
    cout << "\n"
         << head << "=>";
    
    if (dir == 1)
    {
        for (i = index + 1; i < no_req; i++)
        {
            cout << disc_req[i] << "=>";
            distance += abs(head - disc_req[i]);
            head = disc_req[i];
        }
        for (i = 0; i <= index; i++)
        {
            cout << disc_req[i] << "=>";
            distance += abs(head - disc_req[i]);
            head = disc_req[i];
        }
    }
    else
    {
        for (i = index; i >= 0; i--)
        {
            cout << disc_req[i] << "=>";
            distance += abs(head - disc_req[i]);
            head = disc_req[i];
        }
        for (i = (no_req - 1); i > index; i--)
        {
            cout << disc_req[i] << "=>";
            distance += abs(head - disc_req[i]);
            head = disc_req[i];
        }
    }
    cout << "End";
    cout << "\n Total Distance Traversed=" << distance;
}

int main()
{
    int i;
    cout << "Enter total number of tracks: ";
    cin >> track;
    cout << "Enter total number of disc requests: ";
    cin >> no_req;
    cout << "\nEnter disc requests in FCFS order: ";
    for (i = 0; i < no_req; i++)
    {
        cin >> disc_req[i];
    }
    cout << "\nEnter current head position: ";
    cin >> head1;

    while (1)
    {
        cout << "\n\n********MENU********";
        cout << "\n1. SSTF\n2. SCAN\n3. C-LOOK\n4. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            sstf();
            break;
        case 2:
            scan();
            break;
        case 3:
            clook();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "\n Enter valid choice";
            break;
        }
    }

    return 0;
}
