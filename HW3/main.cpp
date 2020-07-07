#include <iostream>
using namespace std;
int main() {
    int gradeSum = 0, sCounter = 0, grade;
    double gradeAverage;
    bool end = false;
    cout<<"enter grades of students: ";
    while (end == false) {
        cin>>grade;
        if (grade == -1)
            end = true;
        else {
            gradeSum += grade;
            sCounter += 1;
        }
    }
    gradeAverage = (double) gradeSum / (double) sCounter;
    cout<<"The average grade for "<<sCounter<<" students is "<<gradeAverage<<endl;
    return 0;
}
