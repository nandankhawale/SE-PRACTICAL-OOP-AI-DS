#include<iostream>
using namespace std;
 
class Student {

    string name;
    string dob;
    string blood_group;
    int height;
    int weight;
    string policyNo;
    string address;
    string telephoneNo;
    string licenceNo;

    public:
    friend class Database;
    static int count;

    Student() {
        name = "-1";
        dob = "-1";
        blood_group = "-1";
        height = -1;
        weight = -1;
        policyNo = "-1";
        address = "-1";
        telephoneNo = "-1";
        licenceNo = "-1";
    }

    Student(Student &std){
        name = std.name;
        dob = std.dob;
        blood_group = std.blood_group;
        height = std.height;
        weight = std.weight;
        policyNo = std.policyNo;
        address = std.address;
        telephoneNo = std.telephoneNo;
        licenceNo = std.licenceNo;
    }

    void set_data() {
        cout << "Enter your Name: ";
        cin >> name;
        cout << "Enter your Date of Birth: ";
        cin >> dob;
        cout << "Enter your Blood Group: ";
        cin >> blood_group;
        cout << "Enter your height: ";
        cin >> height;
        cout << "Enter your Weight: ";
        cin >> weight;
        cout << "Enter your policy No.: ";
        cin >> policyNo;
        cout << "Enter your Contact Address: ";
        cin >> address;
        cout << "Enter your Telephone No.: ";
        cin >> telephoneNo;
        cout << "Enter your Licence No.: ";
        cin >> licenceNo;
        count++;
    }

    void show_data() {
        cout << "\n";
        cout << "Name :              " << name << endl;
        cout << "Date of Birth :     " << dob << endl;
        cout << "Blood Group :       " << blood_group << endl;
        cout << "height :            " << height << endl;
        cout << "Weight :            " << weight << endl;
        cout << "Policy No. :        " << policyNo << endl;
        cout << "Contact Address :   " << address << endl;
        cout << "Telephone No. :     " << telephoneNo << endl;
        cout << "Licence No. :       " << licenceNo << endl;
        cout << "\n";
    }
};

int Student::count = 0;

class Database {

    Student* s;

    public:
    int noOfStudent;
    int size;

    Database(int n){
        size = n;
        s = new Student[size];
        noOfStudent = 0;
    }

    ~Database(){
        delete[] s;
    }

    void addData(){
        try{
            if(noOfStudent == size){
                throw size;
            }
        }
        catch(int size)
        {
            cout << "Database Full with " << size << " Students." << endl; 
            return;
        }
        s[noOfStudent++].set_data();
        cout << "Total Students: " << noOfStudent << endl;
    }

    void deleteData(string a) {

        for (int i=0; i<noOfStudent; i++) {
            if (s[i].name == a) {
                for (int j = i; j<noOfStudent-1; j++) {
                    s[j] = s[j + 1];
                }
                noOfStudent--;
                s[noOfStudent] = Student();
            }
        }
    }

    void findData(string a){
        for (int i=0; i<noOfStudent; i++){
            if(s[i].name == a)
                s[i].show_data();
        }
    }

    inline void displayData() {
        for (int i=0; i<noOfStudent; i++){
            s[i].show_data();
        }
    }
};
 
int main(){

    int size, choice;
    string x;
    cout << "Enter size of the Student Database: ";
    cin >> size;
    Database s(size);
    cout << "Database Created Successfully.\n\n";

    do {
        cout << "********** Menu **********" << endl;
        cout << "1. Add data of a Student" << endl;
        cout << "2. Find Data of student by Name" << endl;
        cout << "3. Display Data of all Students" << endl;
        cout << "4. Delete Data of student by name" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                s.addData();
                break;
            case 2:
                cout << "Enter name of Student to find: ";
                cin >> x;
                s.findData(x);
                break;
            case 3:
                s.displayData();
                break;
            case 4:
                cout << "Enter name of Student to Delete: ";
                cin >> x;
                s.deleteData(x);
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid Choice" << endl;
        }
        cout << "\n\n";
    }
    while (choice != 5);
    
    return 0;
}
