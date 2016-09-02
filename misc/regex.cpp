// source: http://www.cs.princeton.edu/courses/archive/spr09/cos333/beautiful.html

#include <iostream>
#include <string>

namespace {

int matchhere(const char *regexp, const char *text);
int matchstar(int c, const char *regexp, const char *text);

/* match: search for regexp anywhere in text */
int match(const char *regexp, const char *text)
{
    if (regexp[0] == '^')
        return matchhere(regexp+1, text);
    do {    /* must look even if string is empty */
        if (matchhere(regexp, text))
            return 1;
    } while (*text++ != '\0');
    return 0;
}

/* matchhere: search for regexp at beginning of text */
int matchhere(const char *regexp, const char *text)
{
    if (regexp[0] == '\0')
        return 1;
    if (regexp[1] == '*')
        return matchstar(regexp[0], regexp+2, text);
    if (regexp[0] == '$' && regexp[1] == '\0')
        return *text == '\0';
    if (*text!='\0' && (regexp[0]=='.' || regexp[0]==*text))
        return matchhere(regexp+1, text+1);
    return 0;
}

/* matchstar: search for c*regexp at beginning of text */
int matchstar(int c, const char *regexp, const char *text)
{
    do {    /* a * matches zero or more instances */
        if (matchhere(regexp, text))
            return 1;
    } while (*text != '\0' && (*text++ == c || c == '.'));
    return 0;
}

} // close unnamed namespace

int main() {
    std::string regex, text;
    while (std::cin) {
        std::cout << "Enter regex: ";
        std::getline(std::cin, regex);
        std::cout << "Enter text : ";
        std::getline(std::cin, text);
        std::cout << "Result     : " << match(regex.data(), text.data())
                  << std::endl;
    }
    return 0;
}
