/* Creator  Faustino Francisco da silva Filho
aka(illidandidnothingwrong on github and stackoverflow)
contact:kamikazeuchiha123@gmail.com
https://www.linkedin.com/in/faustino-francisco-2752b8177/
 */

#include <iostream> // libraries used on this code
#include <fstream>
#include <string>
using namespace std;
bool checkloguin() // function that checks the loguin of a user inside a text file, if the password and loguin is corret
// retuns true else it will return false
{
    string User_name, User_Password, unf, pwf;
    cout << "Enter user name\n";
    cin >> User_name;
    cout << "Enter password\n";
    cin >> User_Password;
    ifstream read(User_name + ".txt");
    getline(read, unf);
    getline(read, pwf);
    if (unf == User_name && pwf == User_Password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main() // main function where the user needs to  choose between resgister and loguin
// register will create a file with the name of the loguin, with the password inside
{
    int user_choice;
    string User_name, User_Password;
    cout << "1.Do you want to register?\n";
    cout << "2.Do you want to loguin?\n";
    cin >> user_choice;
    if (user_choice == 1)
    {
        cout << "type in  new username\n";
        cin >> User_name;
        cout << "Type in  password\n";
        cin >> User_Password;
        ofstream file;
        file.open(User_name + ".txt");
        file << User_name << endl
             << User_Password;
        file.close();
        main();
    }
    else if (user_choice == 2) // false prints False loguin
    {
        bool status = checkloguin();
        if (status == false)
        {
            cout << "False loguin!\n"
                 << endl;
            system("PAUSE");
            return 0;
        }
        else if (status == true) // true prints Sucess!!
        {
            cout << "Sucessfully logged in!!\n";
            system("PAUSE");

            return 1;
        }
    }
}
