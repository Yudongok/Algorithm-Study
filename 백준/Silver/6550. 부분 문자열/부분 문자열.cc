#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, t;

    while(cin >> s >> t){
        size_t idx = 0;
        bool result = true;

        for(size_t i = 0; i<s.size(); i++){
            bool found = false;     //이번에 s[i]를 찾았는지 확인
            size_t start = (i==0 ? 0 : idx+1); // 첫 글자는 t처음부터, 그 이후는 idx+1부터

            for(size_t k = start; k<t.size(); k++){
                if(s[i] == t[k]){
                    idx = k;
                    found = true;
                    break;
                }
            }
            if(!found){
                result = false;
                break;
            }

        }
        cout << (result ? "Yes" : "No") << endl;
    }
    return 0;
}