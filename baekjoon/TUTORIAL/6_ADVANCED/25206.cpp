#include <iostream>
#include <string>
using namespace std;

int main() {

    string name;
    double credit;
    string grade;
    double Total_credit = 0;
    double Total_grade = 0;

    while( cin >> name >> credit >> grade) {
        if (grade == "P") continue;
        Total_credit += credit;
        if (grade == "A+") Total_grade += 4.5*credit;
        else if (grade == "A0") Total_grade += 4.0*credit;
        else if (grade == "B+") Total_grade += 3.5*credit;
        else if (grade == "B0") Total_grade += 3.0*credit;
        else if (grade == "C+") Total_grade += 2.5*credit;
        else if (grade == "C0") Total_grade += 2.0*credit;
        else if (grade == "D+") Total_grade += 1.5*credit;
        else if (grade == "D0") Total_grade += 1.0*credit;
        else if (grade == "F") Total_grade += 0.0*credit;
    }
    cin.fixed;
    cin.precision(7);
    cout << Total_grade/Total_credit;
    
    return 0;
}