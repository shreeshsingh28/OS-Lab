#include <iostream>
#include <queue>
using namespace std;

int main() {
    int nframe, npage, hit = 0, fault = 0;
    int flag = 0;

    cout << "Enter the number of frames: ";
    cin >> nframe;
    int frame[nframe];
    for (int i = 0; i < nframe; i++) {
        frame[i] = -1;
    }

    cout << "Enter the number of pages: ";
    cin >> npage;
    int page[npage];

    cout << "Enter the page reference string: ";
    for (int i = 0; i < npage; i++) {
        cin >> page[i];
    }

    queue<int> q;

    for (int i = 0; i < npage; i++) {
        flag = 0;
        for (int j = 0; j < nframe; j++) {
            if (frame[j] == page[i]) {
                hit++;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            if (q.size() == nframe) {
                int index = -1, val = -1;
                for (int j = 0; j < nframe; j++) {
                    int k;
                    for (k = i + 1; k < npage; k++) {
                        if (frame[j] == page[k]) {
                            if (k > val) {
                                val = k;
                                index = j;
                            }
                            break;
                        }
                    }
                    if (k == npage) {
                        index = j;
                        break;
                    }
                }
                frame[index] = page[i];
                q.pop();
                q.push(frame[index]);
            } else {
                frame[q.size()] = page[i];
                q.push(frame[q.size()]);
            }
            fault++;
        }
    }

    cout << "Number of page hits: " << hit << endl;
    cout << "Number of page faults: " << fault << endl;

    return 0;
}
