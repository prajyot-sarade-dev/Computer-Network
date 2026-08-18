#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    int n;

    // Timer fixed at 3 seconds
    const int TIMEOUT = 3;

    cout << "Stop and Wait ARQ\n\n";

    // User decides number of frames
    cout << "Enter the number of frames to be sent: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of frames.\n";
        return 0;
    }

    srand(time(0));

    // Randomly select one frame to be lost
    int lostFrame = rand() % n + 1;

    for (int i = 1; i <= n; i++)
    {
        cout << "Sending Frame " << i << "...\n";

        // Simulate frame loss
        if (i == lostFrame)
        {
            cout << "Frame " << i << " lost!\n";

            cout << "Timer started for "
                 << TIMEOUT << " seconds...\n";

            // Wait for 3 seconds
            this_thread::sleep_for(
                chrono::seconds(TIMEOUT)
            );

            cout << "Timeout occurred.\n";
            cout << "Retransmitting Frame " << i << "...\n";

            cout << "Frame " << i
                 << " received successfully.\n";

            cout << "ACK " << i << " received.\n\n";
        }
        else
        {
            cout << "Frame " << i
                 << " received successfully.\n";

            cout << "ACK " << i << " received.\n\n";
        }
    }

    cout << "Transmission completed successfully.\n";

    return 0;
}

/*Stop and Wait ARQ

Enter the number of frames to be sent: 5
Sending Frame 1...
Frame 1 received successfully.
ACK 1 received.

Sending Frame 2...
Frame 2 received successfully.
ACK 2 received.

Sending Frame 3...
Frame 3 lost!
Timer started for 3 seconds...
Timeout occurred.
Retransmitting Frame 3...
Frame 3 received successfully.
ACK 3 received.

Sending Frame 4...
Frame 4 received successfully.
ACK 4 received.

Sending Frame 5...
Frame 5 received successfully.
ACK 5 received.

Transmission completed successfully.*/