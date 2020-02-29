//g++ -std=c++11 68.cpp -o 68
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector <string> result;
        string str;
        int buff = 0, start = 0;
        for(int elemt = 0; elemt< words.size(); elemt++){
            buff += words[elemt].size();
            if(buff+elemt-start > maxWidth||elemt+1 == words.size()){
                if(buff+elemt-start > maxWidth) buff -= words[elemt--].size();
                str = words[start];
                for(int ptr = start+1; ptr<=elemt; ptr++){
                    if(elemt+1 == words.size()) str += " ";
                    else{
                        int space = maxWidth-buff, num = elemt-start;
                        str.append(space/num+((ptr-start-1)<( space%num)), ' ');
                    }
                    str += words[ptr];
                
                }
                str.append((maxWidth-str.size()),' ');
                result.push_back(str);
                buff = 0;
                start = elemt + 1;
            }
        }
        return result;
    }
};

int main(void){
	vector<string> words ={"This", "is", "an", "example", "of", "text", "justification."};
	Solution A;
	vector<string> result =  A.fullJustify(words, 16);
	cout << result[0] <<endl;
	cout << result[1] <<endl;
	cout << result[2] <<endl;
	return 0;
}
