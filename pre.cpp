#pragma GCC optimize(3)
#include<map>
#include<string>
#include<iostream>
#include<cmath>
#include<ctime>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#define endl '\n'
typedef long long ll;
typedef std::pair<int,int> pii;
const double pi=std::acos(-1.0);
const double eps=1e-6;
const int MAXN=2e5+5;
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;

int num_line = 0;
int cnt = 0;
std::string s[5005];
std::map<std::string,std::string>mp{
    {"0000","0"}, {"0001","1"}, {"0010","2"}, {"0011","3"}, {"0100","4"}, 
    {"0101","5"}, {"0110","6"}, {"0111","7"}, {"1000","8"}, {"1001","9"}, 
    {"1010","A"}, {"1011","B"}, {"1100","C"}, {"1101","D"}, {"1110","E"}, {"1111","F"}
};

std::map<std::string,std::string,std::greater<std::string>>id;

std::bitset<100>bs;

std::set<std::string>st_1{"MOV","ADD","SUB","AND","INC","OR","RR"};


std::set<std::string>st_2{"LAD","STA","JMP","BZC","IN","OUT","LDI"};

std::string t2s(const int &x){
    std::string stmp;
    int y = x;
    while(y){
        if(y&1){
            stmp.push_back('1');    
        }else{
            stmp.push_back('0');
        }
        y>>=1;
    }
    while(stmp.size()<8){
        stmp.push_back('0');
    }
    std::reverse(stmp.begin(), stmp.end());

    // std::cout<<stmp<<"   eeeee\n";
    return mp[stmp.substr(0,4)]+mp[stmp.substr(4,4)];
}

void add_line(){
    // std::cout<<t2s(num_line)<<" ";
    num_line++;
}

void proc(std::string &stmp){
    if(stmp.substr(0,4)=="HALT"){
        add_line();
        return;
    }
    std::string stmp2=stmp.substr(0,2);
    std::string stmp3=stmp.substr(0,3);
    // std::cout<<stmp<<"\n";
    if(st_1.find(stmp2)!=st_1.end()||st_1.find(stmp3)!=st_1.end()){
        add_line();
        std::string sttmp="";
        for(auto ittmp:stmp){
            if(ittmp=='H') continue;;
            sttmp.push_back(ittmp);
        }
        stmp = sttmp;
        // std::cout<<"oka\n";
        return;
    }

    if(st_2.find(stmp2)!=st_2.end()||st_2.find(stmp3)!=st_2.end()){
        add_line();
        add_line();
        std::string sttmp="";
        for(auto ittmp:stmp){
            if(ittmp=='H') continue;;
            sttmp.push_back(ittmp);
        }
        stmp = sttmp;
        
        // std::cout<<"okb\n";
        return;
    }
    if(stmp.find(':')==stmp.npos){
        
        std::cout<<stmp<<"\n";
        
        std::cout<<"error-----------first word\n";
        exit(1);
    }
    std::string slabel="";
    for(auto to:stmp){
        if(to == ':'){
            id[slabel]=t2s(num_line);
            break;
        }
        slabel.push_back(to);
    }
    stmp = ";"+stmp;

}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::clock_t c1=clock();
// #ifdef LOCAL
    freopen("before.in","r",stdin);
    freopen("in.in","w",stdout);
// #endif
    //=====================================
    while(std::getline(std::cin, s[cnt])){
        if(s[cnt].empty())   continue;
        cnt++;
    }
    for(auto &to:s){//会把标号也变全大写。建议自己写的时候该大写的时候都大写
        if(to.empty())  continue;
        for(auto &toto:to){
            if('a'<=toto&&toto<='z'){
                toto = toto-'a'+'A';
            }
        }
        // std::cout<<t2s(num_line)<<endl;
    }
    for(auto &to:s){
        if(to.empty()||to[0]==';')  continue;
        proc(to);
        // std::cout<<t2s(num_line)<<endl;
    }
    for(auto labeltmp:id){
        // std::cout<<labletmp;
        
        for(auto &to:s){
            
            if(to.empty()||to[0]==';')  continue;;
            // std::replace(to.begin(),to.end(),labeltmp.first,labeltmp.second);
            std::string w=labeltmp.first;
            std::string v=labeltmp.second;
            // std::cout<<"okokoko:"<<w<<"   "<<v<<"\n";
            while(to.find(w)!=to.npos){
                auto now = to.find(w);
                to.replace(now,w.size(),v);
            }
        }
    }
    for(auto to:s){
        if(to.empty())   continue;
        std::cout<<to<<endl;
    }
    
    //=====================================
end:
    std::cerr<<"Time used:"<<std::clock()-c1<<"ms"<<endl;
    return 0;
}