#include <iostream>
#include <string>
using namespace std;

int main()
{
string code;

cout << "Enter received Hamming codeword: ";  
cin >> code;  

int n = code.length();  

  
int r = 0;  

while ((1 << r) < (n + 1))  
    r++;  

  
int bit[100];  

for (int pos = 1; pos <= n; pos++)  
{  
    bit[pos] = code[n - pos] - '0';  
}  

cout << "\nNumber of bits in received codeword = " << n;  
cout << "\nNumber of redundant bits = " << r;  

cout << "\n\n--------------------------------";  
cout << "\nAnalyzing Redundant Bits";  
cout << "\n--------------------------------";  

int syndrome = 0;  


for (int p = 1; p <= n; p = p * 2)  
{  
    int parity = 0;  

   
    for (int pos = 1; pos <= n; pos++)  
    {  
        if (pos & p)  
        {  
            parity = parity ^ bit[pos];  
        }  
    }  

    cout << "\n\nR" << p << " - Analyze bits at: ";  

    for (int pos = 1; pos <= n; pos++)  
    {  
        if (pos & p)  
            cout << pos << " ";  
    }  

    cout << "\nParity value = " << parity;  

   
    if (parity == 1)  
        syndrome = syndrome + p;  
}  


cout << "\n\n--------------------------------";  
cout << "\nSyndrome = ";  

 
for (int p = 1; p < (1 << r); p = p * 2)  
{  
   
}  

for (int p = (1 << (r - 1)); p >= 1; p = p / 2)  
{  
    cout << ((syndrome & p) ? 1 : 0);  
}  

cout << "\nDecimal equivalent = " << syndrome;  


if (syndrome == 0)  
{  
    cout << "\n\nNo error detected.";  
    cout << "\nReceived codeword is CORRECT.";  
}  
else if (syndrome > n)  
{  
    cout << "\n\nError position is outside the codeword.";  
    cout << "\nMore than one error may be present.";  
}  
else  
{  
    cout << "\n\nError is located at "  
         << syndrome << "th position.";  

     
    bit[syndrome] = bit[syndrome] ^ 1;  

      
    string corrected = "";  

    for (int pos = n; pos >= 1; pos--)  
    {  
        corrected += char(bit[pos] + '0');  
    }  

    cout << "\nCorrected codeword is: "  
         << corrected;  
}  

cout << endl;  

return 0;

}

/*Enter received Hamming codeword: 10101001111            

Number of bits in received codeword = 11
Number of redundant bits = 4

--------------------------------
Analyzing Redundant Bits
--------------------------------

R1 - Analyze bits at: 1 3 5 7 9 11 
Parity value = 1

R2 - Analyze bits at: 2 3 6 7 10 11 
Parity value = 0

R4 - Analyze bits at: 4 5 6 7 
Parity value = 0

R8 - Analyze bits at: 8 9 10 11 
Parity value = 0

--------------------------------
Syndrome = 0001
Decimal equivalent = 1

Error is located at 1th position.
Corrected codeword is: 10101001110*/