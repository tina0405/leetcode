//g++ -std=c++11 1048.cpp -o 1048
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int max = 0;
        int current = 0;
        for(int i = 0; i< words.size() ;i++){
            for(int j = i+1, k = i; j < words.size();j++){
                if(words[k].size()+1 == words[j].size()){
		    if(!cmp(words[k], words[j], &current)){
			cout<< words[k] << " " << words[j] << " " << current << endl;                    
                        k = j;
                        j = k;
                    }
                }
            }  
            if(current+1 > max){
                max = current+1;
            }
	    current = 0;
        }
        return max;
    }
    
private:
    int cmp(string a, string b, int* longset){
        int array[26] = {0};
        int diff = 0;
        for(int k =0;k< a.size();k++){
            array[a[k]-'a'] = -1;
            
        }
        for(int m =0;m< b.size();m++){
            if(array[b[m]-'a'] == -1){
            }else{
                diff++;
            }
        }
        if(diff==1){ 
            *longset = (*longset)+1;    
            return 0; 

        }else{ return 1; }
        
    }
};

int main(){
    vector<string> test = {"a","b","ba","bca","bda","bdca"};
    Solution tina;
    int a = tina.longestStrChain(test);
    cout << a <<endl;
    return 0;
}
