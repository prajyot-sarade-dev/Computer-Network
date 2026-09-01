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

    cout << "Enter Data: ";
    cin >> data;

    cout << "Enter Generator: ";
    cin >> generator;

   
    string zeros = string(generator.length() - 1, '0');
    string dataWithZeros = data + zeros;

   
    string remainder = divide(dataWithZeros, generator);

 
    string codeword = data + remainder;

    cout << "CRC Remainder: " << remainder << endl;
    cout << "Codeword to Send: " << codeword << endl;

    return 0;
}