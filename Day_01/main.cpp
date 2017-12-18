// Day 1 - Inverse Captcha
#include <stdio.h>
#include <string.h>

int invert_captcha(const char* input, int length, int delta);

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        const char* input = argv[1];
        int length = strlen(input);

        printf("%d\n", invert_captcha(input, length, 1));
        printf("%d\n", invert_captcha(input, length, length / 2));
    }

    getchar();

    return 0;
}

int lookup(const char* input, int length, int index)
{
    if (index >= length)
    {
        index -= length;
    }

    return input[index] - '0';
}

int invert_captcha(const char* input, int length, int delta)
{
    int sum = 0;

    for (int index = 0; index < length; ++index)
    {
        int current = lookup(input, length, index);
        int next = lookup(input, length, index + delta);
        sum += (current == next) ? current : 0;
    }

    return sum;
}
