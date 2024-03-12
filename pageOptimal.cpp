#include <iostream>
using namespace std;

int main()
{
    int nframe, npage, hit = 0, fault = 0, index = 0;

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
        int j, k, max = -1;
        int flag = 0;

        for (j = 0; j < nframe; j++)
        {
            if (frame[j] == page[i])     //page found in frame.
            {
                hit++;                  
                flag = 1;
                break;
            } 
        }
        if (!flag)                       //page not found in frames
        {
            fault++;
            for (j = 0; j < nframe; j++)        //goal - to find which frame index to replace
            {
                int found = 0;
                for (k = i + 1; k < npage; k++)
                {
                    if (frame[j] == page[k])
                    {
                        found = 1;
                        if (max < k)
                        {
                            max = k;
                            index = j;
                        }
                        break;              //compare values in each frame 
                    }
                }
                if (!found)
                {
                    index = j;
                    break;
                }
            }
            frame[index] = page[i];
        }
    }

    cout << "Number of page hits: " << hit << endl;
    cout << "Number of page faults: " << fault << endl;

    return 0;
}
