#include <iostream>
#include <string>
using namespace std;

int main()
{
    string stuffedFrame;
    string originalFrame = "";
    int count = 0;

    cout << "Enter the stuffed frame: ";
    cin >> stuffedFrame;

    for (int i = 0; i < stuffedFrame.length(); i++)
    {
        originalFrame += stuffedFrame[i];

        if (stuffedFrame[i] == '1')
        {
            count++;

            if (count == 5)
            {
                i++;        // Skip the stuffed 0
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    cout << "\nOriginal frame after Bit De-stuffing: " << originalFrame << endl;

    return 0;
}