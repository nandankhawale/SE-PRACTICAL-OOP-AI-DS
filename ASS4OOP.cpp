/* Write a C++ program that creates an output file, writes information to it,
 closes the file, open it again as an input file and read the information from the file.*/

#include <iostream>
#include <fstream>
using namespace std;

class Student
{
public:
    string name;
    string rollNo;

    void setData()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter Roll no.: ";
        cin >> rollNo;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll no.: " << rollNo << endl;
    }
};

int main()
{

    int n;
    Student *s;

    cout << "Enter no. of Students: ";
    cin >> n;

    fstream f;
    f.open("data.txt", ios::in | ios::out);
    s = new Student[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Information of student " << i + 1 << ": " << endl;
        s[i].setData();
        f.write((char *)&s[i], sizeof(s[i]));
        cout << endl;
    }
        f.close();
        f.open("data.txt", ios::in);
        f.seekg(0);
    
    for(int i=0; i<n; i++){
        f.read((char*)&s[i], sizeof(s[i]));
        s[i].display();
        cout << endl;
    }
    f.close();
    return 0;
}