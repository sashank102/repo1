#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class user
{
public:
    int accountid;
    int balance;
    string password;

    void acc_create(string pwd, int bal, string name)
    {
        string textfile = name + ".txt";
        fstream acc_det;
        acc_det.open(textfile, ios::out);
        if (acc_det.is_open())
        {

            acc_det << "user name is " << name << endl;
            acc_det << "password is " << pwd << endl;
            acc_det << bal << endl;
            acc_det.close();
        }
    }
    void user_list(string name)
    {
        fstream users;
        users.open("register.txt", ios::app);
        if (users.is_open())
        {
            users << name << endl;
            users.close();
        }
    }
    int user_chk(string name)
    {
        fstream users;
        users.open("register.txt", ios::in);
        if (users.is_open())
        {
            string line;
            while (getline(users, line))
            {
                if (name == line)
                {
                    return 1;
                }
            }
            return 2;
            users.close();
        }
    }
    void bank_statement(string name, int amount, int op, int bal)
    {
        string textfile = name + "th.txt";
        fstream tran_hist;
        tran_hist.open(textfile, ios::app);
        if (tran_hist.is_open())
        {
            if (op == 1)
            {
                tran_hist << "-" << amount << "  balance=" << bal << endl;
            }
            else
            {
                tran_hist << "+" << amount << "  balance=" << bal << endl;
            }
        }
    }
    string pass_checker(string name)
    {

        string textfile = name + ".txt";
        fstream acc_det;
        acc_det.open(textfile, ios::in);

        if (acc_det.is_open())
        {
            string line;
            int i = 0;
            while (getline(acc_det, line))
            {
                if (i == 1)
                {
                    return line;
                }
                i++;
            }
        }
    }
    int bal_getter(string name)
    {
        string textfile = name + ".txt";
        fstream acc_det;
        acc_det.open(textfile, ios::in);

        if (acc_det.is_open())
        {
            string line;
            int i = 0;
            while (getline(acc_det, line))
            {
                if (i == 2)
                {
                    return stoi(line);
                }
                i++;
            }
        }
    }
    void acc_update(string pwd, int bal, string name)
    {
        string textfile = name + ".txt";
        fstream acc_det;
        acc_det.open(textfile, ios::out);
        if (acc_det.is_open())
        {

            acc_det << "user name is " << name << endl;
            acc_det << "password is " << pwd << endl;
            acc_det << bal << endl;
            acc_det.close();
        }
    }
};
int main()
{
    string passw;
    int balan, balan1;
    int command, amt;
    int index = 0;
    string name, name1;
    user ip;

    cout << "1-create account, 2-withdraw, 3- deposit, 4- transfer, 5-transaction history" << endl;
    cin >> command;
    if (command == 1)
    {

        do
        {
            cout << "Enter your name :" << endl;
            cin >> name;
            int us = ip.user_chk(name);
            if (us == 2)
            {
                cout << "enter password" << endl;
                cin >> passw;
                cout << "enter initial deposit" << endl;
                cin >> balan;
                ip.acc_create(passw, balan, name);
                ip.user_list(name);
                break;
            }
            else
            {
                cout << "username already taken" << endl;
            }
        } while ((ip.user_chk(name)) == 1);
    }

    else if (command == 2)
    {

        cout << "enter name" << endl;
        cin >> name;
        cout << "enter password" << endl;
        cin >> passw;
        if ((ip.pass_checker(name)) == "password is " + passw)
        {
            balan = ip.bal_getter(name);
            cout << "enter amount to be withdrawn" << endl;
            cin >> amt;
            balan = balan - amt;
            ip.acc_update(passw, balan, name);
            ip.bank_statement(name, amt, 1, balan);
        }
        else
        {
            cout << "incorrect password" << endl;
        }
    }
    else if (command == 3)
    {

        cout << "enter name" << endl;
        cin >> name;
        cout << "enter password" << endl;
        cin >> passw;
        if ((ip.pass_checker(name)) == "password is " + passw)
        {
            balan = ip.bal_getter(name);
            cout << "enter amount to be deposited" << endl;
            cin >> amt;
            balan = balan + amt;
            ip.acc_update(passw, balan, name);
            ip.bank_statement(name, amt, 2, balan);
        }
        else
        {
            cout << "incorrect password" << endl;
        }
    }
    else if (command == 4)
    {

        cout << "enter name" << endl;
        cin >> name;
        cout << "enter password" << endl;
        cin >> passw;
        if ((ip.pass_checker(name)) == "password is " + passw)
        {
            cout << "enter username of person you want to transfer money to" << endl;
            cin >> name1;
            balan1 = ip.bal_getter(name1);
            balan = ip.bal_getter(name);
            cout << "enter money to be transferred" << endl;
            cin >> amt;
            balan = balan - amt;
            balan1 = balan1 + amt;
            ip.acc_update(passw, balan1, name1);
            ip.acc_update(passw, balan, name);
            ip.bank_statement(name, amt, 1, balan);
            ip.bank_statement(name1, amt, 2, balan1);
        }
        else
        {
            cout << "incorrect password" << endl;
        }
    }
    else if (command == 5)
    {
        cout << "enter name" << endl;
        cin >> name;
        cout << "enter password" << endl;
        cin >> passw;
        if ((ip.pass_checker(name)) == "password is " + passw)
        {
            string textfile = name + "th.txt";
            fstream tran_hist;
            tran_hist.open(textfile, ios::in);
            if (tran_hist.is_open())
            {
                string line;
                while (getline(tran_hist, line))
                {
                    cout << line << endl;
                }
                tran_hist.close();
            }
        }
        else
        {
            cout << "incorrect password" << endl;
        }
    }
    else
    {
        cout << "invalid command" << endl;
    }
    return 0;
}