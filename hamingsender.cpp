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

/*Enter data bits: 1011001

Data Word: 1011001
Number of Data Bits: 7
Number of Redundant Bits: 4
Total Number of Bits in Codeword: 11

R1 - Analyze bits at: 1 3 5 7 9 11 
Bits excluding R1: 10111
Set R1 = 0

R2 - Analyze bits at: 2 3 6 7 10 11 
Bits excluding R2: 10101
Set R2 = 1

R4 - Analyze bits at: 4 5 6 7 
Bits excluding R4: 001
Set R4 = 1

R8 - Analyze bits at: 8 9 10 11 
Bits excluding R8: 101
Set R8 = 0
10101001110*/