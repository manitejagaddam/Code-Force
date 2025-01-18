#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;



int vaild(vector<vector<int>> questions){
    int attempt = 0;

    for(vector<int> i : questions){
        int sum = 0;
        for(int j : i){
            sum += j;
            if(sum == 2){
                attempt++;
                break;
            }
        }
    }

    return attempt;
}













int main(){
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<int>> questions;
    for(int i = 0 ; i < n ; i++){
        string line;
        getline(cin, line);

        istringstream ss(line);

        vector<int>question;

        int num;
        while(ss >> num){
            question.push_back(num);
        }

        questions.push_back(question);

    }

    // cout << n << endl;

    // for(auto i : questions){
    //     for(int j : i){
    //         cout << j << " ";
    //     }cout << endl;
    // }



    cout << vaild(questions);
}