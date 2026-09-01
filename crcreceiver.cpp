#include <iostream>
#include <string>
using namespace std;

string xorOperation(string a, string b)
{
    string result = "";

    for (int i = 1; i < a.length(); i++)
    {
        if (a[i] == b[i])
            result += '0';
        else
            result += '1';
    }

    return result;
}

string divide(string data, string generator)
{
    int n = generator.length();
    string temp = data.substr(0, n);

    for (int i = n; i < data.length(); i++)
    {
        if (temp[0] == '1')
            temp = xorOperation(generator, temp);
        else
            temp = xorOperation(string(n, '0'), temp);

        temp += data[i];
    }

    if (temp[0] == '1')
        temp = xorOperation(generator, temp);
    else
        temp = xorOperation(string(n, '0'), temp);

    return temp;
}

int main()
{
    string data, generator;

    cout << "Enter Received Codeword: ";
    cin >> data;

    cout << "Enter Generator: ";
    cin >> generator;

    string remainder = divide(data, generator);

    cout << "Remainder: " << remainder << endl;

    bool error = false;

    for (int i = 0; i < remainder.length(); i++)
    {
        if (remainder[i] == '1')
        {
            error = true;
            break;
        }
    }

    if (error)
        cout << "Error Detected!" << endl;
    else
        cout << "No Error Detected!" << endl;

    return 0;
}