#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long best;
vector<int> answer, best_answer;
int step;
const int LIMIT = 1e5;
const int INF = 1 << 30;
bool smaller(const vector<int>& A, const vector<int>& B)
{
    for (int i = 0; i < A.size(); ++i)
        if (A[i] > B[i]) return false;
    return true;
}
bool search(const vector<vector<int> >&A, vector<int> &C, long long sum, int now)
{
    if(sum<best)
    {
        best = sum;
        best_answer = answer;
        return false;
    }
    step++;
    if(step * C.size() >= LIMIT)
        return true;
    for(int i=now;i<A.size();i++)
        if(smaller(A[i],C))
        {
            for (int j = 0; j < C.size(); ++j)
            {
                C[j] -= A[i][j];
                sum -= A[i][j];
            }
            answer.push_back(i);
            if(search(A,C,sum,i+1))
                return true;
            for(int j=0;j<C.size();j++)
            {
                sum += A[i][j];
                C[j] += A[i][j];
            }
        }
        return false;
}
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > B(n,vector<int> (m));
        vector<pair<int,int> > b(n);
        for(int i=0;i<n;i++)
        {
            b[i].first = 0;
            for(int j=0;j<m;j++)
            {
                cin>>B[i][j];
                b[i].first += B[i][j];
            }
            b[i].second = i;
        }
        sort(b.begin(),b.end(),greater<pair<int,int> >());
        vector<vector<int> > A(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            int k = b[i].second;
            copy(B[k].begin(),B[k].end(),A[i].begin());
        }
        vector<int> C(m);
        long long sum = 0;
        for(int i=0;i<m;i++)
        {
            cin>>C[i];
            sum += C[i];
        }
        best = sum;
        best_answer.clear();
        answer.clear();
        step = 0;
        search(A,C,sum,0);
        vector<int> ret;
        for(auto &it:best_answer)
            ret.push_back(b[it].second + 1);
        sort(ret.begin(),ret.end());
        cout<<ret.size()<<"\n";
        for(int i=0;i<ret.size();i++)
            cout<<ret[i]<<"\n";
    }
    return 0;
}
