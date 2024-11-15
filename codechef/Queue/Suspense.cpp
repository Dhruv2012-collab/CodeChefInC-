#include <iostream>
using namespace std;

int main() {
    
    int T_testcases = 0;
    cin >> T_testcases;
    
    while(T_testcases--)
    {
        int N_length = 0;
        cin >> N_length;
        
        string str;
        cin >> str;
        
        string res = "";
        int i = 0, j = str.length() - 1;
      
        while(i <= j)
        {
            if(str[i] == '0')
            {
                res = str[i] + res;
                //cout << res << "in\n";
            }
            else 
            {
                res = res + str[i];
            }
            
            if(i < j)
            {
                if(str[j] == '1')
                {
                    res = str[j] + res;
                }
                else
                {
                    res = res + str[j];
                }
                j--;
            }
            i++;
        }
        
        cout << res << endl;
    }
	return 0;
}