#include <iostream>
#include <vector>
using namespace std;

class Subject {
public:
    string name;
    int credits;
    float grade;

    Subject(string n, int c, float g) : name(n), credits(c), grade(g) {}
};

float calculateCGPA(const vector<Subject>& subjects) {
    float totalPoints = 0;
    int totalCredits = 0;

    for(const auto& subject : subjects) {
        totalPoints += subject.grade * subject.credits;
        totalCredits += subject.credits;
    }

    return totalPoints / totalCredits;
}

int main() {
    int numSubjects;
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    vector<Subject> subjects;

    for(int i = 0; i < numSubjects; ++i) {
        string name;
        int credits;
        float grade;

        cout << "Enter the name of subject " << i+1 << ": ";
        cin >> name;
        cout << "Enter the credits for " << name << ": ";
        cin >> credits;
        cout << "Enter the grade for " << name << ": ";
        cin >> grade;

        subjects.emplace_back(name, credits, grade);
    }

    float cgpa = calculateCGPA(subjects);
    cout << "Your CGPA is: " << cgpa << endl;

    return 0;
}
