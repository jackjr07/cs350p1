/*Jack Wanitkun CS350 - Multiplication */
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

vector<int> createF(int i, int fLen, vector<int> & first){
    if(i == fLen) return first;
    int hold = 0;
    cout << "INPUT X: ";
    cin  >> hold;
    first.push_back(hold);
    ++i;
    return createF(i, fLen, first);
};

void printV(int i, vector<int> show){
    if(i == show.size()) return;
    cout << show[i];
    ++i;
    return printV(i, show);
}

int main(){
    vector<int> first;
    vector<int> second;
    vector<int> result;
    int * v1;
    int carry = 0;
    int MAX = 100;

    //create an array of int
    
    int fLen = 0;
    cout << "How many digits in this number: ";
    cin >> fLen;
    cin.ignore(100, '\n');
    
    first = createF(0, fLen, first);
    printV(0, first);

    return 0;
}

