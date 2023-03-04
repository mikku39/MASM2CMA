#pragma GCC optimize(3)
#include<map>
#include<string>
#include<iostream>
#include<cmath>
#include<ctime>
#include<vector>
#include<algorithm>
#include<bitset>
#define endl '\n'
typedef long long ll;
typedef std::pair<int,int> pii;
const double pi=std::acos(-1.0);
const double eps=1e-6;
const int MAXN=2e5+5;
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;

int num_line = 0;

std::map<std::string,std::string>mp{
    {"0000","0"}, {"0001","1"}, {"0010","2"}, {"0011","3"}, {"0100","4"}, 
    {"0101","5"}, {"0110","6"}, {"0111","7"}, {"1000","8"}, {"1001","9"}, 
    {"1010","A"}, {"1011","B"}, {"1100","C"}, {"1101","D"}, {"1110","E"}, {"1111","F"}
};

std::map<char,std::string>rp{
    {'0',"00"}, {'1',"01"}, {'2',"10"}, {'3',"11"}
};

std::bitset<100>bs;

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

void print_line(){
    std::cout<<"$P ";
    std::cout<<t2s(num_line)<<" ";
    num_line++;
    return;
}

void init(){
    for(char x = '0';x<='9';x++){
        bs.set((int)x);
    }
    for(char x = 'A';x<='F';x++){
        bs.set((int)x);
    }
}

bool check(const std::string &s,const int &type){
    //MOV RD,RS
    if(type == 1){
        if(s[4]==' '&&s[5]=='R'&&'0'<=s[6]&&s[6]<='3'&&s[7]==','&&s[8]=='R'&&'0'<=s[9]&&s[9]<='3'){
            return 1;
        }
        return 0;
    }
    //OR RD,RS
    if(type == 2){
        if(s[3]==' '&&s[4]=='R'&&'0'<=s[5]&&s[5]<='3'&&s[6]==','&&s[7]=='R'&&'0'<=s[8]&&s[8]<='3'){
            // std::cout<<"ok!!\n";
            return 1;
        }
        return 0;
    }
    //LNC RD
    if(type == 3){
        if(s[4]==' '&&s[5]=='R'&&'0'<=s[6]&&s[6]<='3'){
            return 1;
        }
        return 0;
    }
    //LAD M D,RD
    if(type == 4){
        if(s[4]==' '&&'0'<=s[5]&&s[5]<='1'&&'0'<=s[6]&&s[6]<='1'&&s[7]==' '&&bs.test((int)s[8])&&bs.test((int)s[9])&&s[10]==','&&s[11]=='R'&&'0'<=s[12]&&s[12]<='3'){
            return 1;
        }
        return 0;
    }
    //JMP MM DD
    //BZC MM DD
    if(type == 5){
        if(s[4]==' '&&'0'<=s[5]&&s[5]<='1'&&'0'<=s[6]&&s[6]<='1'&&s[7]==' '&&bs.test((int)s[8])&&bs.test((int)s[9])){
            return 1;
        }
        return 0;
    }
    //IN RD,PP
    if(type == 6){
        if(s[3]==' '&&s[4]=='R'&&'0'<=s[5]&&s[5]<='3'&&s[6]==','&&bs.test((int)s[7])&&bs.test((int)s[8])){
            return 1;
        }
        return 0;
    }
    //OUT PP,RS
    if(type == 7){
        if(s[4]==' '&&bs.test((int)s[5])&&bs.test((int)s[6])&&s[7]==','&&s[8]=='R'&&'0'<=s[9]&&s[9]<='3'){
            return 1;
        }
        return 0;
    }
    //LDI RD,DD
    if(type == 8){
        if(s[4]==' '&&s[5]=='R'&&'0'<=s[6]&&s[6]<='3'&&s[7]==','&&bs.test((int)s[8])&&bs.test((int)s[9])){
            return 1;
        }
        return 0;
    }
    return 0;
}

void proc(const std::string &s){
    if(s.size()==1){
        return;
    }
    if(s.substr(1,3)=="MOV"){
        if(check(s,1)){
            print_line();
            std::cout<<mp["0100"]<<mp[ rp[s[9]] + rp[s[6]] ];
            std::cout<<";"<<s;
            std::cout<<endl;
            return;
        }
        goto sy_error;
        
    }   
    if(s.substr(1,3)=="ADD"){
        if(check(s,1)){
            print_line();
            std::cout<<mp["0000"]<<mp[ rp[s[9]] + rp[s[6]] ];
            std::cout<<";"<<s;
            std::cout<<endl;
            return;
        }
        goto sy_error;
    }
    if(s.substr(1,3)=="SUB"){
        if(check(s,1)){
            print_line();
            std::cout<<mp["1000"]<<mp[ rp[s[9]] + rp[s[6]] ];
            std::cout<<";"<<s;
            std::cout<<endl;
            return;
        }
        goto sy_error;
    }
    if(s.substr(1,3)=="AND"){
        if(check(s,1)){
            print_line();
            std::cout<<mp["0001"]<<mp[ rp[s[9]] + rp[s[6]] ];
            std::cout<<";"<<s;
            std::cout<<endl;
            return;
        }
        goto sy_error;
    }
    if(s.substr(1,2)=="OR"){
        if(check(s,2)){
            print_line();
            std::cout<<mp["1001"]<<mp[ rp[s[8]] + rp[s[5]] ];
            std::cout<<";"<<s;
            std::cout<<endl;
            return;
        }
        goto sy_error;
    }
    if(s.substr(1,2)=="RR"){
        if(check(s,2)){
            print_line();
            std::cout<<mp["1010"]<<mp[ rp[s[8]] + rp[s[5]] ];
            std::cout<<";"<<s;
            std::cout<<endl;
            return;
        }
        goto sy_error;
    }
    if(s.substr(1,3)=="INC"){
        if(check(s,3)){
            print_line();
            std::cout<<mp["0111"]<<mp["00" + rp[s[6]]];
            std::cout<<";"<<s;
            std::cout<<endl;
            return;
        }
        goto sy_error;
    }

//----------------------------------------------------------------

    if(s.substr(1,3)=="LAD"){//LAD MM DD,RD
        if(check(s,4)){
            print_line();
            std::cout<<mp["1100"]<<mp[s.substr(5,2)+rp[s[12]]];
            std::cout<<";"<<s;
            std::cout<<endl;
            print_line();
            std::cout<<s[8]<<s[9]<<endl;
            return;
        }
        goto sy_error;
    }
    if(s.substr(1,3)=="STA"){//STA MM DD,RD
        if(check(s,4)){
            print_line();
            std::cout<<mp["1101"]<<mp[s.substr(5,2)+rp[s[12]]];
            std::cout<<";"<<s;
            std::cout<<endl;
            print_line();
            std::cout<<s[8]<<s[9]<<endl;
            return;
        }
        goto sy_error;
    }
    if(s.substr(1,3)=="JMP"){//JMP MM DD 
        if(check(s,5)){
            print_line();
            std::cout<<mp["1110"]<<mp[s.substr(5,2)+"00"];
            std::cout<<";"<<s;
            std::cout<<endl;
            print_line();
            std::cout<<s[8]<<s[9]<<endl;
            return;
        }
        goto sy_error;
    }
    if(s.substr(1,3)=="BZC"){
        if(check(s,5)){
            print_line();
            std::cout<<mp["1111"]<<mp[s.substr(5,2)+"00"];
            std::cout<<";"<<s;
            std::cout<<endl;
            print_line();
            std::cout<<s[8]<<s[9]<<endl;
            return;
        }
        goto sy_error;
    }

//--------------------------------------------------------------------

    if(s.substr(1,2)=="IN"){//IN RD,PP
        if(check(s,6)){
            print_line();
            std::cout<<mp["0010"]<<mp["00"+rp[s[5]]];
            std::cout<<";"<<s;
            std::cout<<endl;
            print_line();
            std::cout<<s[7]<<s[8]<<endl;
            return;
        }
        goto sy_error;
    }
    if(s.substr(1,3)=="OUT"){//OUT PP,RS
        if(check(s,7)){
            print_line();
            std::cout<<mp["0011"]<<mp[rp[s[9]]+"00"];
            std::cout<<";"<<s;
            std::cout<<endl;
            print_line();
            std::cout<<s[5]<<s[6]<<endl;
            return;
        }
        goto sy_error;
    }

    if(s.substr(1,3)=="LDI"){//LDI RD,DD
        if(check(s,8)){
            print_line();
            std::cout<<mp["0110"]<<mp["00"+rp[s[6]]];
            std::cout<<";"<<s;
            std::cout<<endl;
            print_line();
            std::cout<<s[8]<<s[9]<<endl;
            return;
        }
        goto sy_error;
    }

    if(s.substr(1,4)=="HALT"){
        print_line();
        std::cout<<"50";
        std::cout<<";"<<s;
        std::cout<<endl;
        return;
    }

sy_error:
    print_line();
    std::cout<<"error!"<<endl<<s;
    exit(1);
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::clock_t c1=clock();
// #ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
// #endif
    //=====================================
    std::string s="";
    init();
    while(std::getline(std::cin, s)){
        if(s[0]==';'){
            std::cout<<s<<endl;
            continue;
        }
        s=" "+s;
        proc(s);
        
    }
    

    
    //=====================================
end:
    std::cerr<<"Time used:"<<std::clock()-c1<<"ms"<<endl;
    return 0;
}