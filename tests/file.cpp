#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream my_file;

    my_file.open("Servers/index.html", ios::in);

    if (!my_file)
    {
        cout << "No such file";
    }
    else
    {
        for (std::string line; getline(my_file, line);)
        {
            cout << line << endl;
        }
    }
    my_file.close();
    return 0;
}