#include <iostream>

using namespace std;

void getNext(const string &str,int *next){
    next[0] = -1;
    int j  = 0, k = -1;
    while(j < str.length()){
        if( k == -1 || str[j] == str[k] ){
            next[++j] = ++k;
        }else{
            k = next[k];
        }
    }
}

int KMP(const string &str1,const string &str2,int next[]){
    int i=0, j=0,count=0;
    while(i < str1.length()){
        int len = str2.length();
        while(j < len && i < str1.length() ){
            if(j == -1 || str1[i] == str2[j]){
                i++;
                j++;
            }else{
                j=next[j];
            }
        }
        if(j == str2.length()){
            count++;
            j=next[j];
        }
    }
    return count;
}

int main02(){
    int n;
    while(scanf("%d",&n) != EOF){
        int word=0;
        while(word<n){
            string s1,s2;
            cin>>s1;
            cin>>s2;
            int next[s1.length()]={0},count=0;
            getNext(s1,next);
            for (int i = 0; i < s1.length(); ++i) {
                cout<<next[i]<<" ";
            }
            cout<<endl;
            count=KMP(s2,s1,next);
            cout<<count<<endl;
            word++;
        }
    }
    return 0;
}
