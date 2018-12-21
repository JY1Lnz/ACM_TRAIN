 #include<iostream>
 #include<stack>
 using namespace std;

 int main()
 {
     int n;
     cin>>n;
     long long x;
     long long sum = 0;
     stack<long long> st;
     for (int i = 0;i<n;i++)
     {
         cin>>x;
         while(!st.empty()&&x>=st.top())
             st.pop();
         sum += st.size();
         st.push(x);
     }
     cout<<sum<<endl;


     return 0;
 }
