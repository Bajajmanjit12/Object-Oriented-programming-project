#include <iostream>
using namespace std;

int n; 


class student {
    int rno; 
protected:
    string name, prn; 
public:
    
    void accept() {
        cout << "\nEnter name of student: ";
        cin >> name;
        cout << "Enter roll no: ";
        cin >> rno;
        cout << "Enter PRN no: ";
        cin >> prn;
    }

    
    void display() {
        cout << "\nRoll No: " << rno << "\tName: " << name << "\tPRN: " << prn << endl;
    }
};


class test : virtual public student {
    string s[5]; 
    int cia[5], endsem[5], total[5]; 
    int tot, per; 

public:

    void acceptT() {
        cout << "\nEnter subject names, CIA marks (out of 40), EndSem marks (out of 60):\n";
        for (int i = 0; i < 5; i++) {
            cout << "Enter subject " << i + 1 << " name: ";
            cin >> s[i];
            cout << "Enter CIA marks for " << s[i] << ": ";
            cin >> cia[i];
            cout << "Enter EndSem marks for " << s[i] << ": ";
            cin >> endsem[i];
        }
    }
    
    void displayT() {
        tot = 0;
        for (int i = 0; i < 5; i++) {
            total[i] = cia[i] + endsem[i];
            tot += total[i];
        }
        per = tot / 5;
        cout << "\nSUBJECT\tCIA\tENDSEM\tTOTAL\n";
        for (int i = 0; i < 5; i++) {
            cout << s[i] << "\t" << cia[i] << "\t" << endsem[i] << "\t" << total[i] << endl;
        }
        cout << "\nTotal marks: " << tot;
        cout << "\nPercentage: " << per << "%";
        if (per >= 35) {
            cout << "\nPASS!!!\n";
        } else {
            cout << "\nFAIL!!!\n";
        }
    }
};


class sports : virtual public student {
    string sportsname; 
    char grade; 

public:
    
    void acceptS() {
        cout << "\nEnter the name of Sports: ";
        cin >> sportsname;
        cout << "Enter the grade obtained in " << sportsname << ": ";
        cin >> grade;
    }

   
    void displayS() {
        cout << "\nSports name: " << sportsname;
        cout << "\nGrade Obtained: " << grade << endl;
    }
};

class result : public test, public sports {
public:
    
    void displayresult() {
        display();    
        displayT();    
        displayS();    
    }
};

int main() {
    result T[100]; 

    cout << "\nEnter the number of records: ";
    cin >> n;
    int choice;

    do {
        cout << "\n1. Accept Details\n2. Display Result\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Accept data for 'n' students
                for (int i = 0; i < n; i++) {
                    T[i].accept();   // Accept student details
                    T[i].acceptT();  // Accept test marks
                    T[i].acceptS();  // Accept sports details
                }
                break;

            case 2: // Display result for 'n' students
                for (int i = 0; i < n; i++) {
                    T[i].displayresult();
                }
                break;
        }
    } while (choice != 0);

    return 0;
}
