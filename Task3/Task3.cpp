#include <iostream>
#include <string>

int main()
{
    // Create string
    const char* str = "strin";

    // Computing length of string
    size_t n = 0;
    while (true)
    {
        if (*(str + ++n) == '\0')
        {
            break;
        }
    }

    size_t result_n = 2 * n;
    char* result = new char[result_n];
    for (int i = 0; i < result_n; i++)
    {
        *(result + i) = str[i % 3 + 3 * (i / 6)];
    }
//    *(result + result_n) = '\0';

    std::cout << n << " " << result << std::endl;

    // Delete pointers
    /*delete str;
    delete result;*/
}
