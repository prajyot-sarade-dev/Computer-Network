#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Enter the total no. of frame: ";
    cin >> a;
    if (a <= 0)
    {
        cout << "Invalid frames ";
        return 0;
    }

    int b = 1;
    while (b <= a)
    {
        cout << "sending frames:" << b << endl;

        if (b == 1 || b == 2)
        {
            cout << "frame " << b << " received successfully" << endl;
            cout << " ACK " << b << " received successfully" << endl;
            b++;
            cout << endl;
        }

        else if (b == 3)
        {
            cout << "frame " << b << "is lost ";

            cout << " Timeout timer expired! No ACK received." << endl;
            cout << " Retransmitting Frame 3 " << endl;

            cout << " Sending Frame 3 (Retransmission) " << endl;
            cout << " Frame 3 received successfully." << endl;

            cout << " ACK 3 received successfully " << endl;
            b++;
            cout << endl;
        }

        else if (b == 4)
        {
            cout << " Frame 4 received successfully." << endl;
            cout << " Sending ACK 4" << endl;
            cout << " ACK 4  LOST in transit" << endl;
            cout << " Timeout timer expired! ACK not received." << endl;
            cout << " Retransmitting Frame 4" << endl;

            cout << " Sending Frame 4 (Retransmission)" << endl;
            cout << " Duplicate Frame 4 detected! Discarding frame copy." << endl;

            cout << " ACK 4 received successfully" << endl;
            b++;
            cout << endl;
        }
        else
        {
            cout << "frame " << b << " received successfully" << endl;
            cout << " ACK " << b << " received successfully" << endl;
            b++;
            cout << endl;
        }
    }
      cout << " Transmission Completed Successfully " << endl;

    return 0;
}