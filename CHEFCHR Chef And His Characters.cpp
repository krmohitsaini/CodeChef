#include<iostream>
#include<string>
#include<queue>
using namespace std;
bool isNotInside(char str[4], char ch)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == ch)
            return 0;
        i++;
    }
    return 1;
}
int main()
{
    int cases,t;
    cin>>cases;
    t = cases;
    int lovelyCount[cases];
    while(cases--)
    {
        string sentence;
        cin>>sentence;
        int i = 0, lovely = 0;
        char check[4];
        check[0] = '0';
        check[1] = '0';
        check[2] = '0';
        check[3] = '0';
        while(sentence[i] != '\0')
        {
            char ch = sentence[i];
            if(ch == 'c' || ch == 'h' || ch == 'e' || ch == 'f')
            {
                check[i%4]= ch;
                i++;
            }
            if(!(ch == 'c' || ch == 'h' || ch == 'e' || ch == 'f'))
            {
                int j = 0;
                while(j != 4)
                {
                    check[j] = '0';
                    j++;
                }
                i++;
            }
            if(!(isNotInside(check,'c')) && !(isNotInside(check,'h')) && !(isNotInside(check,'e')) && !(isNotInside(check,'f')))
                lovely++;
        }
        lovelyCount[cases] = lovely;
    }
    for(cases=t-1;cases>=0;cases--)
        if(lovelyCount[cases])
            cout<<"lovely "<<lovelyCount[cases]<<"\n";
        else
            cout<<"normal\n";
    return 0;
}
