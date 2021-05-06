#include <iostream>
using namespace std;

int strstr2(const char* text, const char* pattern)
{
    int place = 0;

    if (*text == '\0' && *pattern == '\0')
        return 0;

    if (*pattern == '\0')
        return 0;

    for (int i = 0; text[i] != '\0'; i++) {

        if (text[i] == *pattern) {
            place = i;
            for (int j = 0; ;) {
                if (pattern[j] == text[i])
                {
                    j++;
                    i++;
                }
                else
                {
                    i = place;
                    break;
                }

                if (pattern[j] == '\0')
                    return place;
            }
        }
    }

    return -1;
}

int main()
{
    int ans = 0;

    ans = strstr2("asasaf", "asaf");

    cout << ans;

    return 0;
}
