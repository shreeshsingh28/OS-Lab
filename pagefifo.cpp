#include <iostream>
using namespace std;

int main()
{
    int nframe, npage, hit = 0, fault = 0, index = 0;
    int flag = 0;

    cout << "Enter the number of frames: ";
    cin >> nframe;
    int frame[nframe];
    for (int i = 0; i < nframe; i++)
    {
        frame[i] = -1;
    }

    cout << "Enter the number of pages: ";
    cin >> npage;
    int page[npage];

    cout << "Enter the page reference string: ";
    for (int i = 0; i < npage; i++)
    {
        cin >> page[i];
    }

    for (int i = 0; i < npage; i++)
    {
        flag = 0;
        for (int j = 0; j < nframe; j++)
        {
            if (frame[j] == page[i])
            {
                hit++;
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            frame[index] = page[i];
            index = (index + 1) % nframe;
            fault++;
        }
    }

    cout << "Number of page hits: " << hit << endl;
    cout << "Number of page faults: " << fault << endl;

    return 0;
}
