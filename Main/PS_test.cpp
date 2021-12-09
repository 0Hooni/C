#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CommunityMember {
private:
    int index = 0;
    string Name = "";
    string RegistrationNumber = "";
    bool Gender = true;
    string PhoneNumber = "";
    string EMail = "";
public:
    CommunityMember(){}
    int getIndex() {
        return index;
    }
    void setIndex(int a) {
        this->index = a;
    }
    void setName(string s) {
        this->Name = s;
    }
    string getName() {
        return Name;
    }
    ~CommunityMember(){}
};


class Employee : public CommunityMember {
private:
    string EmployeeNumber = "";
    string LocalPhoneNumber = "";
    string Rank = "";
    string AccountNumber = "";
public:
    Employee(){}
    ~Employee(){}
};

class Teacher : public Employee {
    string Department = "";
    string UniversitylssuanceDate = "";
    string HomepageAddress = "";
    string FinalEducation = "";
public:
    Teacher() {}
    ~Teacher(){}
};


class Student : public CommunityMember {
private:
    string StudentID = "";
    string Department = "";
    int Grade = 0;
    bool CurrentStudentPresence = true;
public:
    Student(){}
    ~Student(){}
};


class Staff : public Employee {
    string Responsibilities = "";
public:
    Staff(){}
    ~Staff(){}
};

int main() {
    ofstream os;
    os.open("CommunityMember.info", ios::out | ios::binary);
    Teacher osteacher;
    for (int i = 1; i <= 20; i++) {
       os.write(reinterpret_cast<const char*>(&osteacher), sizeof(Teacher));
    }
    os.close();

    fstream is;
    is.open("CommunityMember.info", ios::in | ios::out | ios::binary);

    int a;
    cin >> a;
    string s;
    cin >> s;
    Teacher isteacher;
    isteacher.setIndex(a);
    isteacher.setName(s);
    is.seekp((a - 1) * sizeof(Teacher));
    is.write(reinterpret_cast<const char*>(&isteacher), sizeof(Teacher));

    is.seekg(0);
    for (int i = 0; i < 20; i++) {
        is.read(reinterpret_cast<char*>(&isteacher), sizeof(Teacher));
        cout << isteacher.getIndex() << ' ' << isteacher.getName() << '\n';
    }
    is.clear();
    //cout << sizeof(CommunityMember) <<'\n'; //120
    //cout << sizeof(Employee) << '\n'; //232
    //cout << sizeof(Student) << '\n'; //184
    //cout << sizeof(Teacher) << '\n'; //344
    //cout << sizeof(Staff) << '\n'; //260
    return 0;
}