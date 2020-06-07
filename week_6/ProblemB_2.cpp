////
//// Created by abahnasy on 01.06.20.
////
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//#define pb push_back
//
//
//
//
//int n,m;
//
//bool cmp(const vector<int>& lhs, const vector<int>& rhs)
//{
//    return lhs.size() < rhs.size();
//}
//
//bool solve(vector<vector<int> > judge, vector<int>& cook, int J)
//{
//    cout << "satisfying judge " << J <<"\n";
//    if(J == n)
//    {
//        return 1;
//    }
//
//    for(int i=0;i<judge[J].size();i++)
//    {
//        if (i == judge[J].size()-1)
//            cout << "hit max\n";
//        int muf = abs(judge[J][i]), old = cook[muf];
//        if(cook[muf] == 0 || cook[muf] == judge[J][i])
//        {
//            cook[muf] = judge[J][i];
//
//            if(solve(judge, cook, J+1))
//                return 1;
//
//            cook[muf] = old;
//
//        }
//    }
//    return 0;
//}
//
//int main()
//{
//
//
//    // redirect input stream to samples files
////    freopen("../week_6/samples_06/muffinqueen/1.in", "r", stdin);
////    freopen("../week_6/samples_06/muffinqueen/2.in", "r", stdin);
//    freopen("../week_6/samples_06/muffinqueen/unit_test.in", "r", stdin);
//    int T, put = 0, skip = 0;
//    ios::sync_with_stdio(0);
//    cin>>T;
//    string s;
//    for(int t=1; t<=T;++t)
//    {
//        vector<int> cook(100,0);
//        vector<vector<int> > judge;
//        cin>>m>>n;
////        memset(cook, 0, sizeof(cook));
//        judge.clear();
//        judge.resize(n);
//        int x;
//        for(int i=0;i<n;i++)
//        {
//            cin>>x;
//            while(x!=0)
//            {
//                judge[i].pb(x);
//                cin>>x;
//            }
//        }
//        sort(judge.begin(), judge.end(), cmp);
//        cout<<"Case #"<<t<<": ";
//        if(solve(judge, cook, 0))
//            cout<<"yes\n";
//        else
//            cout<<"no\n";
//
//    }
//}
//
