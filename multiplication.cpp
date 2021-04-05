/*Jack Wanitkun
 * HW1 - Multiplication
 * Template looks like this
 * result = xxxx * yy
 * ------------------------
 *   xxxx || This one is the first number describe as a longest one
 *     yy || This one is the second number describe as a smallest one
 *   ----
 *  result
 *
 */

#include<iostream> 
#include<cctype>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int maxLength(char * num){
   return strlen(num);
}

int getMax(int firstLen, int secondLen){
    if(firstLen > secondLen) return firstLen;
    else return secondLen;
}

int getMin(int firstLen, int secondLen){
    if(firstLen < secondLen) return firstLen;
    else return secondLen;
}

int calculate(int first, int second, int & carry){
    first -= 48;
    second -= 48;
    int mul = first * second; 
    int result = mul % 10;
    carry = (mul - result);
    carry = carry/10;
    cout << "Now: " << result << endl;
    return result;
}

//This one will hold to the longest one for the multiplication
char * holdMul(int j, int MAX, char * firstNum, int curr, char *& hold, int carry){
    //I want to literate the firstNum and hold to the index of the smaller one
    if(j == MAX) {
        if(carry != 0){
            hold[j+1] = carry;
            cout << "Last hold " << int (hold[j+1]) << endl;
            return hold;
        }
        return hold;
    }
    int num = firstNum[j];
    if(j == 0){
        hold[j] = calculate(num, curr, carry);
        cout << "Hold: " << int (hold[j]) << endl;
        hold[j+1] = carry;
    }else{
        hold[j] += calculate(num, curr, carry);
        cout << "Hold: " << int (hold[j]) << endl;
        hold[j+1] = carry;
    }
    ++j;
    return holdMul(j, MAX, firstNum, curr, hold, carry);
}



char * startMul(int i ,int carry, char * firstNum, char * secondNum, int MAX, int MIN, char *& result){
    //if(i == MIN) return result; 
    if(i < 0) return result;
    cout << "Start Multiplication" << endl;

    //Hold the longest, and move the calculation by the smallest
    char * hold;
    int curr = secondNum[i];
    hold = holdMul(0, MAX, firstNum, curr, hold, 0);
    //cout << int(hold[i]) << endl;
    //cout << "Size: " << strlen(hold) << endl;
    cout << strlen(hold) << endl;
    for(int k = 0; k < 4; ++k){
        cout << int (hold[k]) << endl;
    }
    --i;
    return startMul(i, carry, firstNum, secondNum, MAX, MIN, result);
}
/////////////////////
//
void printVector(vector<int> const &result, int i){
    if(i == result.size()) return;
    if(i == (result.size() -1)){
        cout << result.at(i) << endl;
        return;
    }
    cout << result.at(i);
    ++i;
    return printVector(result, i);
};


int main(){
    //Declare vals
    char firstNum[100];
    char secondNum[100];
    //int carry = 0;
    
    //Get all inputs
    cout << "Welcome to Jack's program" << endl;
    cout << "Please end the number: "<< endl;
    cin.get(firstNum, 100);
    cin.ignore(100, '\n');

    cout << "Enter the second number: "<< endl;
    cin.get(secondNum, 100);
    cin.ignore(100, '\n');
    
    //Get Max column
    int MAX = getMax(maxLength(firstNum), maxLength(secondNum));
    int MIN = getMin(maxLength(firstNum), maxLength(secondNum));

    //char * result = startMul(MIN-1, 0, firstNum, secondNum, MAX, MIN, result);
    
    ////////////////////////////STUCK WITH MY OWN METHOD///////////////////
    //REDO WITH JUST SIMPLE FOR
    //
    int hold1 = 0;
    int hold2 = 0;
    int carry = 0;
    int result[100];
    vector <int> result1;
    int k = 0;
    for(int i = MIN-1; i > -1; --i){
       hold1 =  int(secondNum[i]) - 48;
        for(int j = MAX-1; j > -1; --j){
            hold2 = int(firstNum[j]) - 48; 
            //cout << hold1 << " * " << hold2 << endl;
            int curr,carryH =0;
            const int ans = hold2 * hold1;
            curr = ans % 10;
            carryH = ans - curr;
            carryH = carry/10;
            cout << hold2 << " * " << hold1 << " = " << hold2 * hold1 << endl;
            cout << "Ans: " << curr << " Carry: " << carry << endl;
            curr += carry;
            result1.push_back(curr);
            carry = carryH;
        }
    }
    cout << "The answer is: ";
    reverse(result1.begin(), result1.end());
    printVector(result1, 0);
    return 0;
}
