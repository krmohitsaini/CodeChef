#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int a = 1; a <= cases; a++)
    {
        int n, m, i, j;
        string str_1, str_2;
        cin >> n >> str_1;
        cin >> m >> str_2;
        int matrix[n+1][m+1];
        for(i = 0; i <= n; i++)
            for(j = 0; j <= m; j++)
            {
                if(i == 0 || j == 0)
                    matrix[i][j] = 0;
                else if(str_1[i-1] == str_2[j-1])
                    matrix[i][j] = 1 + matrix[i-1][j-1];
                else
                    matrix[i][j] = max(matrix[i-1][j],matrix[i][j-1]);
            }
        int len = matrix[n][m];
        int ind_1[len], ind_2[len], in = 0, z = 0;
        string seq = "";
        i = n;
        j = m;
        while(i > 0 && j > 0)
        {
            if(str_1[i-1] == str_2[j-1])
            {
                seq += str_1[i-1];
                i--;
                j--;
            }
            else if(matrix[i-1][j] < matrix[i][j-1])
                j--;
            else
                i--;
        }
        reverse(seq.begin(), seq.end());
        for(i = 0; i < str_1.size(); i++)
            if(seq[in] == str_1[i])
            {
                ind_1[z] = i + 1;
                z++;
                in++;
            }
        in = 0;
        z = 0;
        for(i = 0; i < str_2.size(); i++)
            if(seq[in] == str_2[i])
            {
                ind_2[z] = i + 1;
                z++;
                in++;
            }
        if(seq.size() > 1)
        {
            cout << "case" << a <<" Y"<<"\n";
            cout << seq.size() <<"\n";
            for(i = 0; i < seq.size(); i++)
                cout << seq[i] <<" "<<ind_1[i]<<" "<<ind_2[i]<<"\n";
        }
        else
            cout << "case" << a <<" N"<<"\n";
    }
    return 0;
}
