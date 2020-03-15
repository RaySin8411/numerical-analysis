/*
One nice feature of a table of ordinary differences is that an error in an entry for f (x)
can be readily detected. Such an error causes a disruption(斷絕) to the regular progression
of values in the columns of differences. 
(使用一般差分表的一個好處，是 f (x) 值的輸入錯誤可以被偵測知道。
因為錯誤的 f (x) 值會破壞差分表各欄位中數值變化的規則性。)
*/


#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find the product term 
float proterm(int i, float value, float x[]) 
{ 
    float pro = 1; 
    for (int j = 0; j < i; j++) { 
        pro = pro * (value - x[j]); 
    } 
    return pro; 
} 
  
// Function for calculating 
// divided difference table 
void dividedDiffTable(float x[], float y[][10], int n) 
{ 
    for (int i = 1; i < n; i++) { 
        for (int j = 0; j < n - i; j++) { 
            y[j][i] = (y[j][i - 1] - y[j + 1] 
                         [i - 1]) / (x[j] - x[i + j]); 
        } 
    } 
} 
  
// Function for applying Newton's 
// divided difference formula 
float applyFormula(float value, float x[], 
                   float y[][10], int n) 
{ 
    float sum = y[0][0]; 
  
    for (int i = 1; i < n; i++) { 
      sum = sum + (proterm(i, value, x) * y[0][i]); 
    } 
    return sum; 
} 
  
// Function for displaying  
// divided difference table 
void printDiffTable(float y[][10],int n) 
{ 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n - i; j++) { 
            cout << setprecision(4) <<  
                                 y[i][j] << "\t "; 
        } 
        cout << "\n"; 
    } 
} 
  
// Driver Function 
int main() 
{ 
    // number of inputs given 
    int n = 4; 
    float value, sum, y[10][10]; 
    float x[] = { 5, 6, 9, 11 }; 
  
    // y[][] is used for divided difference 
    // table where y[][0] is used for input 
    y[0][0] = 12; 
    y[1][0] = 13; 
    y[2][0] = 14; 
    y[3][0] = 16; 
  
    // calculating divided difference table 
    dividedDiffTable(x, y, n); 
  
    // displaying divided difference table 
    printDiffTable(y,n); 
  
    // value to be interpolated 
    value = 7; 
  
    // printing the value 
    cout << "\nValue at " << value << " is "
               << applyFormula(value, x, y, n) << endl; 
    return 0; 
} 
