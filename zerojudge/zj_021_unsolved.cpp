#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INf 0x3f3f3f3f
using namespace std;
typedef long long ll;
string str1, str2, op;
int a[505], b[505];
void print_ans(int output[]){
    int start = 0;
    for(int i = 504;i >= 0;i--){
        if(output[i] != 0){
            start = i;
            break;
        }
    }
    for(int i = start;i >= 0;i--) cout << output[i];
}
int main(){
    IOS
    while(cin >> str1 >> op >> str2){
        if(op != "/"){
            memset(a, 0, sizeof(a));
            memset(b, 0, sizeof(b));
            for(int i = str1.size();i >= 0;i--) a[str1.size() - i - 1] = str1[i] - '0';
            for(int i = str2.size();i >= 0;i--) b[str2.size() - i - 1] = str2[i] - '0';
        }
        int cnt = 0;
        if(op == "+"){
            int sum[505];
            memset(sum, 0, sizeof(sum));
            for(int i = 0;i < 505;i++){
                sum[i] = a[i] + b[i] + cnt;
                if(sum[i] >= 10){
                    sum[i] -= 10;
                    cnt = 1;
                }
                else cnt = 0;
            }
            print_ans(sum);
        }
        else if(op == "-"){
            int delta[505];
            int minus = 0;
            memset(delta, 0, sizeof(delta));
            bool judge = false;
            if(str1.size() < str2.size() || ((str1.size() == str2.size()) && (a[str1.size() - 1] < b[str2.size() - 1]))){
                judge = true;
                for(int i = 0;i < 505;i++) swap(a[i], b[i]);
            }
            for(int i = 0;i < 505;i++){
                int num1 = a[i], num2 = b[i];
                if(num1 < num2 && i > 0){
                    a[i + 1] = a[i + 1] - 1;
                    a[i] = num1 - num2 + 10;
                }
                else a[i] = num1 - num2;
            }
            if(judge) cout << '-';
            print_ans(a);
        }
        else if(op == "*"){
            int product[1001] = {0};
            for(int i = 0;i < str1.size();i++){
                for(int j = 0;j < str2.size();j++){
                    product[i + j] += a[i] * b[j];
                    if(product[i + j] >= 10){
                        product[i + j + 1] += product[i + j] / 10;
                        product[i + j] = product[i + j] % 10;
                    }
                }
            }
            print_ans(product);
        }
        else if(op == "/"){
            int quotient[505] = {0}, tmp[505] = {0};
            for(int i = 0;i < str1.size();i++) tmp[i] = str1[i] - '0';
            for(int i = 0;i < (str1.size() - str2.size() + 1);i++){
                while(tmp[i] >= 0){
                    for(int j = 0;j < str2.size();j++){
                        tmp[i + j] -= (str2[j] - '0');
                        if(tmp[i + j] < 0 && j > 0){
                            tmp[i + j - 1]--;
                            tmp[i + j] += 10;
                        }
                    }
                    quotient[i]++;
                }
                for(int j = 0;j < str2.size();j++) tmp[j + i] += str2[j] - '0';
                quotient[i]--;
                tmp[i + 1] += tmp[i] * 10;
                tmp[i] = 0;
            }
            for(int i = 0;i < str1.size() - str2.size() + 1;i++) cout << quotient[i];
            cout << '\n';

            for(int i = 0;i < str1.size() - str2.size() + 1;i++) str2 += '0';
            for(int i = str2.size() - str2.size() + 1;i >= 0;i--){
                for(int j = 1;j < 10;j++){
                    if()
                }
            }
        }
    }

    return 0;
}