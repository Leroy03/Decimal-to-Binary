//
//  main.cpp
//  etutor
//
//  Created by Leroy on 02/04/2019.
//  Copyright © 2019 Leroy. All rights reserved.
//
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int cal(int a[],int tmp) //Translate Decimal to Binary
{
    int z = 0;
    while(tmp)
    {
        a[z++] = tmp % 2;
        tmp /= 2;
    }
    return *a;
}
int check(int a[])
{
    a[0] += 1;
    
    for(int i = 7;i>=0;i--)
        if(a[i] > 1)
        {
            a[i] = 0;
            a[i-1] += 1;
        }
    return *a;
}

int if_neg(int a[], int x)  // Check out negative or not
{
    int tmp = abs(x);
    if(x < 0)   // If negative need to change 0 to 1 and 1 to 0
    {
        *a = cal(a,tmp);
        for(int i = 0 ; i < 8; i++) //two's complement
            if(a[i] == 1)
                a[i] = 0;
            else
                a[i] = 1;
        return check(a);
    }
    
    *a = cal(a,tmp);
    
    return *a;
}

int main(){
    int x;
    while(cin>>x&&x)
    {
        int tmp = x;
        int a[8];
        
        for(int i=0;i<8;i++)
            a[i]=0;
        *a = if_neg(a, tmp);
        
        for(int i=7;i>=0;i--)
            cout<<a[i];
        cout<<endl;
    }
    return 0;
}
