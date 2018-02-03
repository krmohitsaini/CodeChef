#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
    int cases, total=0;
    cin>>cases;
    float time[cases];
    while(total != cases)
    {
        int tunnel;
        cin>>tunnel;
        long timeT[tunnel];
        for(int i=0;i<tunnel;i++)
            cin>>timeT[i];
        long c,d,s;
        cin>>c>>d>>s;
        time[total] = 0.000000;
        float matrix[c+1][tunnel+1];
        for(int i=0;i<tunnel+1;i++)
            matrix[0][i] = 0;
        for(int i=0;i<c+1;i++)
            matrix[i][0] = 0;
        for(int i=1;i<c+1;i++)
            for(int j=1;j<tunnel+1;j++)
            {
                if(matrix[i][j-1] < matrix[i-1][j])
                    matrix[i][j] = matrix[i-1][j] + timeT[j-1];
                else
                    matrix[i][j] = matrix[i][j-1] + timeT[j-1];
            }
        time[total] = (float)matrix[c][tunnel]-(float)matrix[1][tunnel];
        total++;
    }
    cout<<fixed;
    cout<<setprecision(6);
    for(int i=0;i<cases;i++)
        cout<<time[i]<<"\n";
    return 0;
}
