#include <iostream>
#include <string>
using namespace std;

int main()
{
string data;

cout << "Enter data bits: ";  
cin >> data;  

int m = data.length();  
int r = 0;  

  
while ((1 << r) < (m + r + 1))  
    r++;  

int n = m + r;  

cout << "\nData Word: " << data;  
cout << "\nNumber of Data Bits: " << m;  
cout << "\nNumber of Redundant Bits: " << r;  
cout << "\nTotal Number of Bits in Codeword: " << n;  


int bit[100] = {0};  



int j = m - 1;  

for (int pos = 1; pos <= n; pos++)  
{  
    
    if ((pos & (pos - 1)) == 0)  
    {  
        bit[pos] = 0;      
    }  
    else  
    {  
        bit[pos] = data[j] - '0';  
        j--;  
    }  
}  
  

for (int p = 1; p <= n; p = p * 2)  
{  
    int parity = 0;  

    cout << "\n\nR" << p << " - Analyze bits at: ";  

    for (int pos = 1; pos <= n; pos++)  
    {  
        if (pos & p)  
        {  
            cout << pos << " ";  

             
            if (pos != p)  
                parity = parity ^ bit[pos];  
        }  
    }  

    bit[p] = parity;  

    cout << "\nBits excluding R" << p << ": ";  

    for (int pos = 1; pos <= n; pos++)  
    {  
        if ((pos & p) && pos != p)  
            cout << bit[pos];  
    }  

    cout << "\nSet R" << p << " = " << bit[p];  
}  



cout << "\n";  

for (int pos = n; pos >= 1; pos--)  
{  
    cout << bit[pos];  
}  

cout << endl;  

return 0;

}