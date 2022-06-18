
#include <iostream>
#include <fstream>
using namespace std;

struct student
{
    char name[20];
    char id[20]; // MAY INCLUDE CHARACTERS!!!
    int roll_no;
    float programming_marks, maths_marks, HST_marks, algorithm_marks, sum, average;
};

// FUNCTIONS DECLERATIONS
void introduction();       // INTRODUCTION PAGE
void mainmenu();           // nAVIGATION MENU
void acceptdata();         // dATA INPUT
void view_individual(int); // RESULT INVIDUAL OUTPUT
void viewall();            // ALL RESULT DATA
void deleterecord(int);    // DELETION OF DATA
void modify(int);          // MODIFICATION OF DATA

int main()
{
    char c;

    do
    {

        cout << "\n\n\n";
        cout << "\t====================STUDENT REPORT CARD MANEGEMENT SYSTEM====================" << endl;
        cout << endl;
        cout << "\t\t\t\t1. MAIN MENU\n\n";
        cout << "\t\t\t\t2. EXIT\n\n";
        cout << "ENTER YOUR CHOICE :";

        cin >> c;

        switch (c)
        {
        case '1':
        {
            mainmenu();
            break;
        }
        }
    } while (c != '2');
    return 0;
}

// fUNCTION STARTS HERE

void introduction()

{

    cout << "\n\n\n";
    cout << "\t\t\t\t================================================" << endl;
    cout << "\t\t\t\tWELCOME TO STUDENT REPORT CARD MANEGEMENT SYSTEM" << endl;
    cout << "\t\t\t\t================================================" << endl
         << endl;
    cout << "press Enter to Continue.";
    cin.ignore();
    // cin.get();
}

void mainmenu()

{
    char C2;
    cout << "\t\t\t\t===================MAIN MENU==================\n\n"
         << endl;
    cout << "\t\t\t\t1. CREATE A STUDENT REPORT CARD\n\n"
         << endl;

    cout << "\t\t\t\t2. VIEW CLASS RESULT\n\n"
         << endl;

    cout << "\t\t\t\t3. VIEW A INDIVIDUAL STUDENT REPORT CARD\n\n"
         << endl;

    cout << "\t\t\t\t4. MODIFY DETAILS REPORT CARD\n\n"
         << endl;

    cout << "\t\t\t\t5. DELETE RECORD OF STUDENT\n\n"
         << endl;

    cout << "\t\t\t\t=================================" << endl;

    cout << "\t\t\t\tENTER YOUR CHOICE...... [1-5] :";

    cin >> C2;
    cout << endl;

    switch (C2)
    {
    case '1':
    {
        acceptdata();
        break;
    }
    case '2':
    {
        viewall();
        break;
    }
    case '3':
    {
        int n;
        cout << "ENTER YOUR ROLL NUMBER :";
        cin >> n;
        view_individual(n);
        break;
    }
    case '4':
    {
        int n;
        cout << "ENTER YOUR ROLL NUMBER :";
        cin >> n;
        modify(n);
        break;
    }

    case '5':
    {
        int n;
        cout << "ENTER YOUR ROLL NUMBER :";
        cin >> n;
        cout << endl;
        deleterecord(n);
        break;
    }
    break;
    }
}

void acceptdata()
{
    student s;
    ofstream outfile;
    outfile.open("Report.txt");

    if (outfile.fail())
    {
        cout << "THE FILE COULD NOT BE OPEN DUE TO INTERNAL ISSUE CONTACT SONI!  ...press enter key";
        cin.ignore();
        cin.get();
    }

    cout << "\n\n";
    cout << "\t\t\t\t=======CREATE A REPORT CARD========\n\n";
    cout << "ENTER YOUR FULL NAME :";
    cin.ignore();
    cin.getline(s.name, 80);
    cout << "ENTER YOUR ID NUMBER : ";
    cin.ignore();
    cin.get(s.id, 80);
    cout << "ENTER YOUR ROLL NUMBER :";
    cin >> s.roll_no;
    cout << "ENTER YOUR PROGRAMMING MARK :";
    cin >> s.programming_marks;
    cout << "ENTER YOUR MATHS MARK :";
    cin >> s.maths_marks;
    cout << "ENTER YOUR WRITING (HST) MARK :";
    cin >> s.HST_marks;
    cout << "ENTER YOUR ALGORITHM MARK :";
    cin >> s.algorithm_marks;

    s.sum = s.programming_marks + s.maths_marks + s.HST_marks + s.algorithm_marks;
    s.average = (s.sum / 4);

    // reinterpret_cast<char *>(&s)--> Casting operator | used to convert a pointer of some data type into a pointer of another data type
    //  basically convers pointer data to data
    outfile.write(reinterpret_cast<char *>(&s), sizeof(student));
    outfile.close();
    cout << endl;
    cout << "\t\t\t\tTHE FILE IS SUCCESSFULLY SAVED" << endl;
    cout << endl;
    cout << "press any key to continue...";
    cin.ignore();
    cin.get();
}

void viewall()

{
    student s;
    ifstream infile;
    bool check = false;
    infile.open("Report.txt");
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED CONTACT SONI!....press enter key...";
        cin.ignore();
        cin.get();
    }
    cout << "\n\n";
    cout << "\t\t\t\tALL STUDENTS REPORT CARDS" << endl;
    cout << "==================================================================================" << endl;
    while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
    {
        cout << "\t\t\t\tSTUDENT NAME :" << s.name << endl
             << endl;
        cout << "\t\t\t\tSTUDENT ID NUMBER :" << s.id << endl
             << endl;
        cout << "\t\t\t\tSTUDENT ROLL NUMBER :" << s.roll_no << endl
             << endl;
        cout << "\t\t\t\tPROGRAMMING MARK :" << s.programming_marks << endl
             << endl;
        cout << "\t\t\t\tCOMPUTER ARCITECTURE MARK :" << s.maths_marks << endl
             << endl;
        cout << "\t\t\t\tWRITING SKILL MARK :" << s.HST_marks << endl
             << endl;
        cout << "\t\t\t\tALGEBRA MARK :" << s.algorithm_marks << endl
             << endl;
        cout << "\t\t\t\tSUM :" << s.sum << endl
             << endl;
        cout << "\t\t\t\tAVERAGE :" << s.average << endl
             << endl;
        cout << "==================================================================================" << endl;
        check = true;
    }
    infile.close();
    if (check == false)
        cout << "\t\t\t\tNO RECORD FOUND..." << endl
             << endl;
    cout << "press any key to continue....";
    cin.ignore();
    cin.get();
}

void view_individual(int n)

{
    student s;
    ifstream infile;
    infile.open("Report.txt");
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    bool equality = false;
    cout << "\t\t\t\t==========VIEW A SINGLE STUDENT REPORT==========\n\n";
    while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
    {
        if (s.roll_no == n)
        {
            cout << "\t\t\t\tSTUDENT NAME :" << s.name << endl;
            cout << "\t\t\t\tSTUDENT ID NUMBER :" << s.id << endl;
            cout << "\t\t\t\tSTUDENT ROLL NUMBER :" << s.roll_no << endl;
            cout << "\t\t\t\tPROGRAMMING MARK :" << s.programming_marks << endl;
            cout << "\t\t\t\tCOMPUTER ARCITECTURE MARK :" << s.maths_marks << endl;
            cout << "\t\t\t\tWRITING SKILL MARK :" << s.HST_marks << endl;
            cout << "\t\t\t\tALGEBRA MARK :" << s.algorithm_marks << endl;
            cout << "\t\t\t\tSUM :" << s.sum << endl;
            cout << "\t\t\t\tAVERAGE :" << s.average << endl;
            cout << "\t\t\t\t================================================" << endl;
            equality = true;
        }
    }
    infile.close();
    if (equality == false)
        cout << "\t\t\t\tRECORD NOT FOUND..." << endl;
    cout << endl;
    cout << "press any key to continue...";
    cin.ignore();
    cin.get();
}

void modify(int n)

{
    student s;
    fstream infile;
    infile.open("Report.txt");
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED..." << endl;
        cin.ignore();
        cin.get();
    }
    bool checker = false;
    cout << "\t\t\t\t==========MODIFY A REPORT CARD==========\n\n";
    while (!infile.eof() && checker == false)
    {
        infile.read(reinterpret_cast<char *>(&s), sizeof(student));
        {
            if (s.roll_no == n)
            {
                cout << "\t\t\t\tSTUDENT NAME :" << s.name << endl
                     << endl;
                cout << "\t\t\t\tSTUDENT ID NUMBER :" << s.id << endl
                     << endl;
                cout << "\t\t\t\tSTUDENT ROLL NUMBER :" << s.roll_no << endl
                     << endl;
                cout << "\t\t\t\tPROGRAMMING MARK :" << s.programming_marks << endl
                     << endl;
                cout << "\t\t\t\tCOMPUTER ARCHITECTURE MARK :" << s.maths_marks << endl
                     << endl;
                cout << "\t\t\t\tWRITING SKILL MARK :" << s.HST_marks << endl
                     << endl;
                cout << "\t\t\t\tALGEBRA MARK :" << s.algorithm_marks << endl
                     << endl;
                cout << "=============================================" << endl;
                cout << "\t\tENTER THE NEW INFORMATION" << endl;
                cout << "=============================================" << endl;
                cout << "ENTER YOUR FULL NAME :";
                cin.ignore();
                cin.getline(s.name, 80);
                cout << "ENTER YOUR ID NUMBER : ";
                cin.ignore();
                cin.get(s.id, 80);
                cout << "ENTER YOUR ROLL NUMBER :";
                cin >> s.roll_no;
                cout << "ENTER YOUR PROGRAMMING MARK :";
                cin >> s.programming_marks;
                cout << "ENTER YOUR COMPUTER ARCITECTURE MARK :";
                cin >> s.maths_marks;
                cout << "ENTER YOUR WRITING SKILL MARK :";
                cin >> s.HST_marks;
                cout << "ENTER YOUR ALGEBRA MARK :";
                cin >> s.algorithm_marks;
                s.sum = s.programming_marks + s.maths_marks + s.HST_marks + s.algorithm_marks;
                s.average = (s.sum / 4);
                int pos = (-1) * static_cast<int>(sizeof(student));
                infile.seekp(pos, ios::cur);
                infile.write(reinterpret_cast<char *>(&s), sizeof(student));
                cout << endl;
                cout << "\t\t\t\tTHE FILE IS SUCCESSFULLY updated" << endl;
                checker = true;
            }
        }
    }
    infile.close();
    if (checker == false)
        cout << "\t\t\t\tRECORD NOT FOUND" << endl;
    cout << endl;
    cout << "press any key to continue...";
    cin.ignore();
    cin.get();
}

void deleterecord(int n)

{
    student s;
    ifstream infile;
    infile.open("Report.txt");
    if (!infile)
    {
        cout << "THE FILE COULD NOT BE OPENED..." << endl;
        cin.ignore();
        cin.get();
    }
    ofstream outfile;
    outfile.open("Record2.txt");
    cout << "\t\t\t\t===========DELETE A REPORT CARD==========\n\n";
    while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
    {
        if (s.roll_no != n)
        {
            outfile.write(reinterpret_cast<char *>(&s), sizeof(student));
        }
    }
    infile.close();
    outfile.close();
    remove("Report.txt");
    rename("Record2.txt", "Report.txt");
    cout << endl;
    cout << "\t\t\t\tRECORD SUCCESSFULLY DELETED" << endl;
    cout << "press any key to continue...";
    cin.ignore();
    cin.get();
}
