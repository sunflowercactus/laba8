#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

struct Book
{
    string Author;
    string Title;
    int Year;
};

void saveToFile(string& filename,  vector<string>& data) {
    ofstream out(filename);
    if (!out.is_open()) {
        cout << "can't open file" << endl;
    }
    for (int i = 0; i < 3; ++i) {
        out << data[i] << " " << endl;
    }

    out.close();
}
void loadFromFile( string& filename, vector<string>& outData) {
    ifstream in(filename);
    string str;
    if (in.is_open()) {
        while (getline(in, str)) {
            cout << str;
        }
    }
    else {
        cout << "file cant open" << endl;
    }

}

void saveToFileBooks( string& filename,  struct Book& data) {
    ofstream out(filename);
    if (!out.is_open()) {
        cout << "can't open file" << endl;
    }
 
    out<<data.Author<<" "<<data.Title<<" "<<data.Year<<endl;
    

    out.close();

}
void loadFromFileBooks( std::string& filename, vector<string>& outData) {
    ifstream in(filename);
    string str;
    if (in.is_open()) {
        while (getline(in, str)) {
            outData.push_back(str);
        }
    }
    else {
        cout << "file cant open" << endl;
    }
    for (int i=0; i < outData.size(); ++i) {
        cout << outData[i];
    }
    in.close();
}



enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

struct Student
{
    std::string Name;
    int Year;
    map<string, Score> RecordBook;
};

// в качестве ключа - название группы
// в качестве значения - список студентов
using Groups = map<string, vector<Student>>;

void saveToFileGroups(string& filename, Groups& groups) {
    ofstream out(filename);
    if (!out.is_open()) {
        cout << "can't open file" << endl;
    }
    for (auto& elem : groups.at("IU8-14")) {
        out << elem.Name << ' ' << elem.Year << ' ' << elem.RecordBook.at("Math") << std::endl;
    }
    out.close();
}

void loadFromFileGroups(const std::string& filename, Groups& outGroups) {
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "can't open file" << endl;
        return;
    }
    string str;
    vector <Student> s1;
    while (getline(in, str)) {
        Student student;
        istringstream iss(str);
        string name;
        iss >> name;
        student.Name = name;
        int year;
        iss >> year;
        student.Year = year;
        int score;
        iss >> score;
        student.RecordBook["Math"] = static_cast<Score>(score);
        s1.push_back(student);
    }
    outGroups["IU8-14"] = s1;
}

int main() {
    vector<string> mas = { "I", "want", "avtomati"};
    vector <string> b2;
    string filename1 = "test.txt";
    string filename = "test1.txt";


    Groups g1;
    vector <Student> s3;
    Student s1;
    s1.Name = "Vika";
    s1.Year = 18;
    s1.RecordBook["Math"] = Excellent;
    Student s2;
    s2.Name = "Ira";
    s2.Year = 17;
    s2.RecordBook["Math"] = Good;
    s3.push_back(s1);
    s3.push_back(s2);
    g1["IU8-14"] = s3;
    saveToFileGroups(filename, g1);
    Groups g2;
    loadFromFileGroups(filename, g2);

    Book b1 = { "Pushkin", "Onegin", 1918 };
    saveToFileBooks(filename1, b1);
    /*saveToFile(filename, mas);
    loadFromFile(filename, mas);*/
    loadFromFileBooks(filename1, b2);
    
    return 0;
}
