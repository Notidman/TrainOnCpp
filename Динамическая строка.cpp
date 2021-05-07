#include <iostream>
using namespace std;

char *resize(const char *str, unsigned size, unsigned new_size)
{
	char *nsPtr = new char[new_size];

    for(unsigned i = 0; i < new_size && i < size; i++)
    {
        nsPtr[i] = str[i];
    }

    delete[] str;
    str = 0;
    return nsPtr;
}
char *getline2()
{
    size_t max = 1;
    char* str = new char [max];
    size_t i = 0;
    char c = '\0';
    while(cin.get(c))
    {
      if(i > max)
      {
        str = resize(str,i,max = i*2);
        str[i++] = c;
      }
      else
        str[i++] = c;


      if(c == '\n' || c == '\0')
        break;
    }

    str[i] = '\0';

    return str;
}

int main()
{
    string str = getline2();

    cout << str;

    return 0;
}
