#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, head, sum = 0;
    cout << "Enter the number of requests: ";
    cin >> n;
    int requests[n];
    cout << "Enter the requests: ";
    for (int i = 0; i < n; i++)
    {
        cin >> requests[i];
    }
    cout << "Enter the initial head position: ";
    cin >> head;
    int current = head;
    bool visited[n] = {false};
    for (int i = 0; i < n; i++)
    {
        int index, min_distance = 9999999;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && abs(requests[j] - current) < min_distance)
            {
                index = j;
                min_distance = abs(requests[j] - current);
            }
        }
        visited[index] = true;
        sum += min_distance;
        current = requests[index];
    }
    cout << "Total head movement: " << sum << endl;
    return 0;
}
