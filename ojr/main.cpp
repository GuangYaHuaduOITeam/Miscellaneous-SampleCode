#include <bits/stdc++.h>

using namespace std;

const string str[] = {"0", "2", "0", "1", "9", "20", "19"};
stringstream sstr;
int ans, sum;
string tempans;
bool check[6];
map<int, bool> checkans;

void dfs(int curr){
    bool isinterrupted = true;
    for(int i = 1; i <= 6; i ++){
        isinterrupted = isinterrupted && check[i];
    }
    if(isinterrupted){
        sstr.clear();
        sstr << tempans;
        sstr >> ans;
        if(ans < 10000000) return;
        checkans[ans] = true;
        return;
    }else{
        for(int i = 1; i <= 6; i ++){
            if(check[i]) continue;
            check[i] = true;
            tempans.append(str[i]);
            dfs(i);
            check[i] = false;
            tempans.erase(tempans.length() - str[i].length(), str[i].length());
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    for(int i = 1; i <= 6; i ++){
        dfs(i);
    }
    for(auto i : checkans){
        if(i.second) sum++;
        cout << i.first << "\n";
    }
    cout << "\n";
    cout << "Result : " << sum;
    return 0;
}
