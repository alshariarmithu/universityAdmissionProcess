#include <iostream>
#include <algorithm>
using namespace std;

//ALSHARIAR HOSSAIN MITHU
//ROLL:2107066

class varsity;
void Admin_Login(varsity &);
void admission_Panel(varsity &);
void student_Login(varsity &, int);

class accountinfo
{
protected:
    string name, email, pass;
    int ID;

public:
    accountinfo(){};
    void show()
    {
        cout << "Name: " << name << "\n";
        cout << "Email: " << email << "\n";
        cout << "Password: " << pass << "\n";
        cout << "ID: " << ID << "\n";
    }
    friend void studentLoginPage(varsity &);
    friend class adminLoginClass;
};

class studentInformation : public accountinfo
{
    string father_name, alocated_dept;
    int merit_pos;
    string choiceList[15];
    int numberofchoice;
    bool givendept;

public:
    studentInformation()
    {
        numberofchoice = 0;
        givendept = false;
    };
    void show()
    {
        cout << "Name: " << name << "\n";
        cout << "ID: " << ID << "\n";
        cout << "Allocated Department: " << alocated_dept << "\n";
        cout << "Number Of Choice: " << numberofchoice << "\n";
    }
    void setdept()
    {
        givendept = true;
    }
    void checkDept()
    {
        if (givendept)
            cout << "Congratulations! you have been Allocated to the department " << alocated_dept << "\n";
        else
            cout << "Alas! You are not Allocated any department.\n";
    }
    friend class studentDatabse;
    friend class studentLoginClass;
    friend void subjectChoice(varsity &, int);
    friend void setSubject(varsity &);
};

class studentDatabse
{
    studentInformation selectedstudentarr[100];
    int numberofstudent;

public:
    studentDatabse()
    {
        numberofstudent = 0;
    }
    void addSelectedStudent()
    {
        cout << "Enter how many student do want to input? \n";
        int cnt;
        cin >> cnt;
        for (int i = 1; i <= cnt; i++)
        {
            cout << "Enter Information for Student " << i << "\n";
            cout << "Enter Student Name: \n";
            cin >> selectedstudentarr[numberofstudent].name;
            cout << "Enter Student Father Name: \n";
            cin >> selectedstudentarr[numberofstudent].father_name;
            cout << "Enter Student Email: \n";
            cin >> selectedstudentarr[numberofstudent].email;
            cout << "Enter Student Merit Position: \n";
            cin >> selectedstudentarr[numberofstudent].merit_pos;
            cout << "Enter Student ID for Login: \n";
            cin >> selectedstudentarr[numberofstudent].ID;
            cout << "Enter Student Account Password: \n";
            cin >> selectedstudentarr[numberofstudent].pass;
            numberofstudent++;
            cout << "Student Added successfully \n";
        }
    }
    void login(string email, string pass, varsity &ins)
    {
        bool flag = false;
        for (int i = 0; i < numberofstudent; i++)
        {
            if (selectedstudentarr[i].email == email && selectedstudentarr[i].pass == pass)
            {
                flag = true;
                student_Login(ins, i);
            }
        }
        if (!flag)
        {
            cout << "Student Not Found.\n";
        }
    }
    friend void studentLoginPage(varsity &);
    friend void subjectChoice(varsity &, int);
    friend void setSubject(varsity &);
    friend void student_Login(varsity &, int);
};

class adminLoginClass
{
    accountinfo adminarr[100];
    int numofadmin;

public:
    adminLoginClass()
    {
        numofadmin = 0;
    };
    void registerAdmin()
    {
        cout << "Enter your name: \n";
        cin >> adminarr[numofadmin].name;
        cout << "Enter your Email: \n";
        cin >> adminarr[numofadmin].email;
        cout << "Enter your Password: \n";
        cin >> adminarr[numofadmin].pass;
        cout << "Enter your ID: \n";
        cin >> adminarr[numofadmin].ID;
        numofadmin++;
    }
    void loginAdmin(string email, string pass, varsity &ins)
    {
        bool flag = false;
        for (int i = 0; i < numofadmin; i++)
        {
            if (adminarr[i].email == email && adminarr[i].pass == pass)
            {
                flag = true;
                Admin_Login(ins);
            }
        }
        if (!flag)
        {
            cout << "Admin User Not Found!\n";
        }
    }
};

class depertmentClass
{
    string name;
    int numofseat;

public:
    depertmentClass()
    {
        numofseat = 0;
    }
    int getnumofseat()
    {
        return numofseat;
    }
    friend class varsity;
    friend void subjectChoice(varsity &, int);
    friend void setSubject(varsity &);
};

class varsity
{
    string name;
    adminLoginClass adminarr;
    studentDatabse studentdata1;
    depertmentClass deptarr[15];
    int numofdept;

public:
    varsity()
    {
        numofdept = 0;
    };
    void addvarsityName()
    {
        cout << "Enter Your varsity Name \n";
        cin >> name;
    }
    void addDept()
    {
        cout << "How many Department do you have in your varsity? \n";
        cout << "MAX LIMIT 15 \n";
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cout << "Enter information of Department NO: " << i << "\n";
            cout << "Enter Name: \n";
            cin >> deptarr[numofdept].name;
            cout << "Enter number of seat in : " << deptarr[numofdept].name << " \n";
            cin >> deptarr[numofdept].numofseat;
            numofdept++;
        }
    }
    string getname()
    {
        return name;
    }
    friend class studentDatabse;
    friend void adminLoginPage(varsity &);
    friend void Admin_Login(varsity &);
    friend void studentLoginPage(varsity &);
    friend void subjectChoice(varsity &, int);
    friend void setSubject(varsity &);
    friend void student_Login(varsity &, int);
};

void setSubject(varsity &ins)
{
    for (int merit = 1; merit <= ins.studentdata1.numberofstudent; merit++)
    {
        for (int j = 0; j < ins.studentdata1.numberofstudent; j++)
        {
            if (ins.studentdata1.selectedstudentarr[j].merit_pos == merit)
            {
                for (int k = 0; k < ins.studentdata1.selectedstudentarr[j].numberofchoice; k++)
                {
                    string dept_name = ins.studentdata1.selectedstudentarr[j].choiceList[k];
                    bool flag = false;
                    for (int p = 0; p < ins.numofdept; p++)
                    {
                        if (ins.deptarr[p].name == dept_name)
                        {
                            if (ins.deptarr[p].numofseat > 0)
                            {
                                ins.studentdata1.selectedstudentarr[j].alocated_dept = dept_name;
                                ins.deptarr[p].numofseat--;
                                flag = true;
                                break;
                            }
                        }
                    }
                    if (flag)
                        break;
                }
            }
        }
    }
}

void subjectChoice(varsity &ins, int pos)
{
    cout << "You can apply for following depertments.\n";
    for (int i = 0; i < ins.numofdept; i++)
    {
        cout << i + 1 << ". Department of " << ins.deptarr[i].name << "\n";
    }
    for (int i = 0; i < ins.numofdept; i++)
    {
        cout << "Enter your choice no: " << i + 1 << "\n";
        cin >> ins.studentdata1.selectedstudentarr[pos].choiceList[i];
        ins.studentdata1.selectedstudentarr[pos].numberofchoice++;
        cout << " Do you want to add more choice? [Y/N]\n";
        char ch;
        cin >> ch;
        if (ch == 'N')
            break;
    }
}

void Admin_Login(varsity &ins)
{
    int op;
    char ch;
    do
    {

        cout << "                       Welcome to Admin Panel" << endl;
        cout << "                       ____________________" << endl;
        cout << "                       1. input student list" << endl;
        cout << "Select your option:";
        cin >> op;
        switch (op)
        {
        case 1:
        {
            ins.studentdata1.addSelectedStudent();
            break;
        }
            cout << "Goback?[Y/N]" << endl;
            cin >> ch;
        }
    } while (ch == 'Y');
}

void student_Login(varsity &ins, int pos)
{
    int op;
    char ch;
    do
    {

        cout << "                       Welcome to Student Panel" << endl;
        cout << "                       ____________________" << endl;
        cout << "                       1. Subject Choice" << endl;
        cout << "                       2. Departmental result" << endl;
        cout << "                       4. Show details information" << endl;
        cout << "                       5. Go to HomePage" << endl;
        cout << "Select your option:";
        cin >> op;
        switch (op)
        {
        case 1:
        {
            subjectChoice(ins, pos);
            setSubject(ins);
            break;
        }
        case 2:
        {
            ins.studentdata1.selectedstudentarr[pos].checkDept();
        }
        case 4:
        {
            ins.studentdata1.selectedstudentarr[pos].show();
            break;
        }
        case 5:
        {
            admission_Panel(ins);
            break;
        }
        }
        cout << "Go to the Student Panel?[Y/N]" << endl;
        cin >> ch;
    } while (ch == 'Y');
    admission_Panel(ins);
}

void adminLoginPage(varsity &ins)
{
    char option_for_login, option_for_registration;
    cout << "\t\tAdmin login page" << endl;
    cout << "\t\t-----------------" << endl;
    cout << "Do you already have an account ?[Y/N]" << endl
         << endl;
    cout << "Select your option:";
    cin >> option_for_login;
    if (option_for_login == 'Y')
    {
        string em, pass;
        cout << "Enter Your Email: \n";
        cin >> em;
        cout << "Enter Your Password: \n";
        cin >> pass;
        ins.adminarr.loginAdmin(em, pass, ins);
    }
    else if (option_for_login == 'N')
    {
        cout << endl
             << "Please register and then login !" << endl;
        cout << endl;
        cout << "Do you  want to register?[Y/N]" << endl
             << endl;
        cout << "Select your option:";
        cin >> option_for_registration;
        if (option_for_registration == 'Y')
        {
            ins.adminarr.registerAdmin();
        }
        else if (option_for_registration == 'N')
        {
            cout << endl
                 << "Thank you for using Kuet Admission Panel !" << endl;
        }
    }
}

void studentLoginPage(varsity &ins)
{
    char option_for_login, option_for_registration;
    cout << "\t\tStudent login page" << endl;
    cout << "\t\t-----------------" << endl;
    cout << "Enter Your Login ID \n";
    int id;
    cin >> id;
    int pos = -1;
    for (int i = 0; i < ins.studentdata1.numberofstudent; i++)
    {
        if (ins.studentdata1.selectedstudentarr[i].ID)
        {
            pos = i;
            break;
        }
    }
    if (pos != -1)
    {
        string em, pass;
        cout << "Enter Your Email: \n";
        cin >> em;
        cout << "Enter Your Password: \n";
        cin >> pass;
        ins.studentdata1.login(em, pass, ins);
    }
    else
    {
        cout << "Alas! You are not selected!\n";
    }
}

void admission_Panel(varsity &ins)
{
    int option;
    char p;
    do
    {
        cout << "                       WELCOME TO " << ins.getname() << " ADMISSION PANEL" << endl;
        cout << "                     ----------------------------------" << endl;
        cout << "                                1. Admin Login" << endl;
        cout << "                                2. Student Login" << endl;
        cout << "                                3. Exit" << endl;
        cout << "select your option:";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            adminLoginPage(ins);
            break;
        }
        case 2:
        {
            studentLoginPage(ins);
        }
        case 3:
        {
            exit(0);
        }
        }
        cout << "do you want to go back to the homepage[Y/N]?" << endl;
        cin >> p;
    } while (p == 'Y');
}
int main()
{
    varsity ins;
    ins.addvarsityName();
    ins.addDept();
    admission_Panel(ins);
    return 0;
}
