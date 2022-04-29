#include <iostream>
#include <string>

int main() {

    // Create string
    const char *str = "string";

    // Computing length of string
    size_t n = 0;
    while (true) {
        if (*(str + n++) == '\0') {
            break;
        }
    }

    size_t resultN = 2 * n;
    char *result = new char[resultN];
    for (int i = 0; i < resultN; i++) {
        size_t id = i % 3 + 3 * (i / 6);
        *(result + i) = str[id];
    }

    std::cout << str << " -> " << result << std::endl;

    // Delete pointers
    delete str;
    delete[] result;
}
