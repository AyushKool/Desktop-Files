#include <iostream>
using namespace std;

class student
{
    string name, roll;
    public:
        void getinfo()
        {
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter Roll: ";
            getline(cin, roll);
        }
        void putinfo()
        {
            cout << "Name: " << name << "\nRoll: " << roll;
        }
};

class academics : virtual public student
{
    protected:
    int m[4];
    public:
        void getmarks()
        {
            cout << "Enter marks: ";
            cin >> m[0] >> m[1] >> m[2] >> m[3];
        }
        void putmarks()
        {
            cout << "Marks: " << m[0] << ", " << m[1]  << ", " << m[2]  << ", " << m[3];
        }
};

class excir : virtual public student
{
    protected:
    int sp, gp, sm;
    public:
        void getmarks()
        {
            cout << "Enter marks: ";
            cin >> sp >> gp >> sm;
        }
        void putmarks()
        {
            cout << "Marks: " << sp << ", " << gp << ", " << sm;
        }
};

class result: public excir, public academics
{
    float avg;
    public:
    void avgr()
    {
        avg = m[0] + m[1] + m[2] + m[3] + sp + gp + sm;
        avg /= 7;
    }
    void show()
    {
        avgr();
        cout << "\nAvg: " << avg;
    }
};

main()
{
    result a;
    a.getinfo();
    a.academics::getmarks();
    a.excir::getmarks();
    a.show();
}