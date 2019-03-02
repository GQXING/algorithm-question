#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;


struct TrieNode
{
    struct TrieNode *son[26]={NULL}; // 当前节点的所有孩子节点
    int num;    //有多少单词通过这个节点,即由根至该节点组成的字符串模式出现的次数
    char val;   //字母值
    bool isEnd=false;
};

TrieNode* root;

void init(){
    root = new TrieNode();
    root->num=1;
}

char* toCharArray(const string &str){
    int len=str.length();
    char *c=new char[len];
    for (int i = 0; i < len; ++i) {
       c[i]=str[i];
    }
    return c;
}

void creatTree(const string &str){
    if(str == "" || str.length() == 0){
        return;
    }
    TrieNode* node=root;
    char *c=toCharArray(str);
    for (int i = 0; i < str.length(); i++) {
        int pos = c[i] - 'a';
        if(node->son[pos] == NULL ){
            node->son[pos] = new TrieNode();
            node->son[pos]->val = c[i];
            node->son[pos]->num=1;
        }else{
            node->son[pos]->num++;
        }
        node=node->son[pos];
    }
    node->isEnd=true;
}

int query(const string &str){
    if(str == "" || str.length() == 0){
        return 0;
    }
    TrieNode* node = root;
    char *c = toCharArray(str);
    for (int i = 0; i < str.length(); i++) {
        int pos = c[i] - 'a';
        if( node->son[pos] == NULL){
            return 0;
        }else{
            node = node->son[pos];
        }
    }
    return node->num;
}

int main01(){
    init();
    int n,m,count;
    string str;
    while( scanf("%d",&n) != EOF){
        for (int i = 0; i < n; ++i) {
            cin>>str;
            creatTree(str);
        }
        while( scanf("%d",&m) != EOF){
            for (int i = 0; i < m; ++i) {
                cin>>str;
                count=query(str);
                cout<<count<<endl;
            }
        }
    }
    return 0;
}
