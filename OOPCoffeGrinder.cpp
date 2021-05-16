//=============================================|
//Кофемолка ООП
//=============================================|

#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

class Human
{
public:
    int age;
    float weight;
    string name;

    void AboutYou()
    {
        cout << "Name: " << name
             << "\nWeght: " << weight
             << "\nAge: " << age
             << endl;
    }

    void Get()
    {
        cout << "Enter your info\n";
        cout << "Your name: ";
        cin >> name;
        cout << "Your weight: ";
        cin >> weight;
        cout << "Your age: ";
        cin >> age;
        cout << endl;
    }
};

class CoffeGrinder
{
private:
    bool Energy;

    bool GetVoltage(bool Vol)
    {
        return Vol;
    }

public:
    void SetEnergy(bool SetEnergy)
    {
        if (SetEnergy)
            Energy = true;
        else
            Energy = false;
    }
    void Start()
    {
        if (GetVoltage(Energy))
            cout << "VjuHHH!!" << endl;
        else
            cout << "\a" << endl;
    }
};

int main()
{
    CoffeGrinder x;
    string Answer;

    cout << "Enable energy?(Yes/No):\n> ";
    cin >> Answer;

    transform(Answer.begin(), Answer.end(), Answer.begin(), tolower);

    if (Answer == "yes" || Answer == "y") {
        x.SetEnergy(true);
        x.Start();
    }
    else if (Answer == "no" || Answer == "n") {
        x.SetEnergy(false);
        x.Start();
    }
    else
        cout << "What?";

    return 0;
}