#include <iostream>
#include <string>
using namespace std;

int main()
{
    string ip;

    cout << "Enter IPv4 address: ";
    getline(cin, ip);

    string octet[4];
    int count = 0;
    string temp = "";

    // Separate IPv4 address into four parts
    for (int i = 0; i <= ip.length(); i++)
    {
        if (ip[i] == '.' || i == ip.length())
        {
            if (temp == "")
            {
                cout << "Invalid IPv4 Address" << endl;
                return 0;
            }

            octet[count] = temp;
            count++;
            temp = "";

            if (count > 4)
            {
                cout << "Invalid IPv4 Address" << endl;
                return 0;
            }
        }
        else
        {
            temp = temp + ip[i];
        }
    }

    // Check exactly four octets
    if (count != 4)
    {
        cout << "Invalid IPv4 Address" << endl;
        return 0;
    }

    // Validate each octet
    int value[4];

    for (int i = 0; i < 4; i++)
    {
        // Check numeric only
        for (int j = 0; j < octet[i].length(); j++)
        {
            if (octet[i][j] < '0' || octet[i][j] > '9')
            {
                cout << "Invalid IPv4 Address" << endl;
                return 0;
            }
        }

        // Check leading zero
        if (octet[i].length() > 1 && octet[i][0] == '0')
        {
            cout << "Invalid IPv4 Address" << endl;
            return 0;
        }

        // Convert string to integer
        value[i] = stoi(octet[i]);

        // Check range
        if (value[i] < 0 || value[i] > 255)
        {
            cout << "Invalid IPv4 Address" << endl;
            return 0;
        }
    }

    cout << "\nValid IPv4 Address" << endl;

    // First byte
    int firstByte = value[0];

    cout << "First Byte: " << octet[0] << endl;
    cout << "First Byte as Integer: " << firstByte << endl;

    // Identify class
    char ipClass;

    if (firstByte >= 0 && firstByte <= 127)
    {
        ipClass = 'A';
    }
    else if (firstByte >= 128 && firstByte <= 191)
    {
        ipClass = 'B';
    }
    else if (firstByte >= 192 && firstByte <= 223)
    {
        ipClass = 'C';
    }
    else if (firstByte >= 224 && firstByte <= 239)
    {
        ipClass = 'D';
    }
    else
    {
        ipClass = 'E';
    }

    cout << "Class: " << ipClass << endl;

    // Display Net ID, Host ID and Network Address
    if (ipClass == 'A')
    {
        cout << "Net ID: "
             << value[0] << endl;

        cout << "Host ID: "
             << value[1] << "."
             << value[2] << "."
             << value[3] << endl;

        cout << "Network Address: "
             << value[0] << ".0.0.0" << endl;
    }
    else if (ipClass == 'B')
    {
        cout << "Net ID: "
             << value[0] << "."
             << value[1] << endl;

        cout << "Host ID: "
             << value[2] << "."
             << value[3] << endl;

        cout << "Network Address: "
             << value[0] << "."
             << value[1] << ".0.0" << endl;
    }
    else if (ipClass == 'C')
    {
        cout << "Net ID: "
             << value[0] << "."
             << value[1] << "."
             << value[2] << endl;

        cout << "Host ID: "
             << value[3] << endl;

        cout << "Network Address: "
             << value[0] << "."
             << value[1] << "."
             << value[2] << ".0" << endl;
    }
    else
    {
        cout << "Net ID: Not applicable" << endl;
        cout << "Host ID: Not applicable" << endl;
        cout << "Network Address: Not applicable" << endl;
    }

    return 0;
}