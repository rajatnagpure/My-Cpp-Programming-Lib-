// Recursive solution
vector<int> s;

void itrative(vector<bool>& v,int i){
    if(i==v.size()){
        for(int i=0;i<v.size();i++){
            if(v[i]){
                cout<<s[i]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    v[i] = 1;
    itrative(v,i+1);
    v[i] = 0;
    itrative(v,i+1);
}

void solve(){
    s = {2,3,11,13};
    vector<bool> v(4,0);
    itrative(v,0);
}




// Iterative solution
int n; // set = {0,1,2,3,4,...........,n-1}
vector<int> s{2,3,11,13,......,n-1 set elements};
for(int b = 0; b < (1 << n); ++b)
{
     vector<int> indices;
     for(int k = 0; k < n; ++k)
     {
          if(b & (1 << k))
          {
               cout<<s[k]<<" ";
          }
     }
     cout<<endl;
}

