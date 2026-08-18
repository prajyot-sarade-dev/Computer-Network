#include <iostream>
#include <string>
using namespace std;

int main()
{
    string frame;
    string stuffedFrame = "";
    int count = 0;

    cout << "Enter the frame bits: ";
    cin >> frame;

    for (int i = 0; i < frame.length(); i++)
    {
        stuffedFrame += frame[i];

        if (frame[i] == '1')
        {
            count++;
            if (count == 5)
            {
                stuffedFrame += '0'; // Stuff a 0
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    cout << "\nFrame after Bit Stuffing: " << stuffedFrame << endl;

    return 0;
}