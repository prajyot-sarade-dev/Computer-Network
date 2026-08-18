#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main()
{
    int n;

    cout << "=============================\n";
    cout << "      Stop and Wait ARQ\n";
    cout << "=============================\n\n";

    cout << "Enter number of frames: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int frame;

        cout << "\nEnter frame number: ";
        cin >> frame;

        cout << "\nSending Frame " << frame << "...\n";

        // Start timer
        cout << "Timer started for Frame " << frame << "...\n";

        // Simulate Frame 2 as lost
        if (frame == 2)
        {
            cout << "Frame " << frame << " lost!\n";

            // Wait for timeout
            this_thread::sleep_for(chrono::seconds(3));

            cout << "Timeout occurred after 3 seconds.\n";
            cout << "Retransmitting Frame " << frame << "...\n";

            // Restart timer
            cout << "Timer restarted for Frame " << frame << "...\n";

            this_thread::sleep_for(chrono::seconds(1));

            cout << "Frame " << frame << " received successfully.\n";
            cout << "ACK " << frame << " received.\n";
            cout << "Timer stopped.\n";
        }
        else
        {
            // Simulate receiver response
            this_thread::sleep_for(chrono::seconds(1));

            cout << "Frame " << frame << " received successfully.\n";
            cout << "ACK " << frame << " received.\n";
            cout << "Timer stopped.\n";
        }
    }

    cout << "\nTransmission completed successfully.\n";

    return 0;
}