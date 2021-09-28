// sort array using recursion:

#include <iostream>
#include <vector>

using namespace std;

void insert(vector<int> &input2, int element){
    if(input2.size()==0 | input2.back()<=element){
        input2.push_back(element);
        return;
    }
    int prev_elem=input2.back();
    input2.pop_back();
    insert(input2,element);
    input2.push_back(prev_elem);
}

void sort(vector<int> &input1){
    if(input1.size()==1){
        return;
    }
    int last_element=input1[input1.size()-1];
    input1.pop_back();
    sort(input1);
    insert(input1,last_element);
}

int main(){
   vector<int> input={2,3,7,6,4,5};
   sort(input);

    for(int i=0;i<input.size();i++){
        cout << input[i] << endl;
    }

    return 0;
}