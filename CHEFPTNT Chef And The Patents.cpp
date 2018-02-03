#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int cases, total = 0;
    cin>>cases;
    vector <int> outF(cases);
    while(total != cases)
    {
        long int n; // Number of Patents
        int m;      // Number of Months
        long x;     // Number of workers each month
        long k;     // Number of workers
        string s;
        cin>>n>>m>>x>>k;
        cin>>s;
        if(s.size() != k)
            outF[total] = 0;
        else if(m*x < n)
            outF[total] = 0;
        else
        {
            long even = 0;
            long odd = 0;
            long i = 0;
            while(s[i] != '\0')
            {
                if(s[i] == 'E')
                    even++;
                if(s[i] == 'O')
                    odd++;
                i++;
            }
            while(m > 0 && n)
            {
                if(m%2 == 0)
                {
                    // Even month
                    if(x > even && even != 0)
                    {
                        n = n - even;
                        even = 0;
                    }
                    else if(even != 0)
                    {
                        even = even - x;
                        n = n - x;
                    }
                    //cout<<" n "<<n<<" m "<<m<<" x "<<x<<" even "<<even<<"\n";
                }
                else
                {
                    // Odd month
                    if(x > odd && odd != 0)
                    {
                        n = n - odd;
                        odd = 0;
                    }
                    else if(odd != 0)
                    {
                        odd = odd - x;
                        n = n - x;
                    }
                    //cout<<" n "<<n<<" m "<<m<<" x "<<x<<" odd "<<odd<<"\n";
                }
                m--;
            }
            if(n <= 0 && m >= 0)
                outF[total] = 1;
            else
                outF[total] = 0;
        }
        total++;
    }
    for(total=0;total<cases;total++)
        if(outF[total] == 0)
            cout<<"no\n";
        else
            cout<<"yes\n";
    return 0;
}
