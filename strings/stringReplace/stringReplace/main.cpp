//
//  main.cpp
//  stringReplace
//
//  Created by ChengnanHu on 2/19/21.
//

#include <iostream>
#include <string>

using namespace std;

void replaceSpace(char *str,int length);

int main()
{
    string test_s = "We are happyQQQQ";
    char *str = new char[16];
    strcpy(str, test_s.c_str());
    replaceSpace(str, 12);
    printf("%s", str);
}

void replaceSpace(char *str,int length)
{
    int zero_count = 0;
    for (int i=0; i<=length-1; i++)
    {
        zero_count += int(str[i] == ' ');
    }
    
    for (int j=length-1; j>=0; j--)
    {
        if (str[j] != ' ')
            str[j+zero_count*2] = str[j];
        
        else
        {
            str[j+zero_count*2] = '0';
            str[j+zero_count*2-1] = '2';
            str[j+zero_count*2-2] = '%';
            
            zero_count--;
        }
    }
}
