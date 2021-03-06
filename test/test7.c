#include <string.h>
#include <sysio.h>
int main()
{
    int x;

    x = 1234;
    printi(x);
    prints("\n");

    x = 0x1234;
    printx(x);
    prints("\n");

    x = 0xFEDC;
    printx(x);
    prints("\n");

    x = 0xA5;
    printxn(x,4);
    prints("\n");

    x = 0;
    printi(x);
    prints("\n");

    x = -789;
    printi(x);
    prints("\n");

    {
        char *ptr;
        char array[20];
        ptr = "1234\n";

        printi( strlen(ptr) );
        prints("\n");
        strcpy(array, ptr);
        prints( array );

        array[6] = '\n';
        array[7] = 0;
        ptr = "this is a test";
        strncpy(array, ptr, 6);
        prints(array);

        ptr = "abcdefghij\n";
        ptr = strchr(ptr, 'f');
        prints(ptr);

        strcpy(array, "this is");
        strcat(array, "a test");
        strcat(array, "\n");
        prints(array);
    }
    {
        char *ptr;
        char array[10];
        int result;
        ptr = "1234\n";

        printi( strlen(ptr) );
        prints("\n");
        strcpy(array, ptr);
        prints( array );

        array[6] = '\n';
        array[7] = 0;
        ptr = "this is a test";
        strncpy(array, ptr, 6);
        prints(array);

        ptr = "abcdefghij\n";
        ptr = strchr(ptr, 'f');
        prints(ptr);

        prints("Checking strcmp\n");
        ptr = "12345";
        strcpy(array, ptr);
        if (strcmp(array, ptr) != 0) prints("strcmp is broken\n");

        ptr = "12346";
        if ( strcmp(ptr, array) <= 0) prints("strcmp is broken\n");
        if ( strcmp(array, ptr) >= 0) prints("strcmp is broken\n");

        ptr = "1234";
        if ( strcmp(ptr, array) >= 0) prints("strcmp is broken\n");
        if ( strcmp(array, ptr) <= 0) prints("strcmp is broken\n");
    }

    {
        char str1[10];
        char str2[10];
        char buff[20];

        strcpy(str1, "1234");
        strcpy(str2, "789");

        strrev(str1);
        strrev(str2);
        if (strcmp(str1, "4321") == 0)
            prints("strrev worked\n");
        else
            prints("strrev broken\n");

        if (strcmp(str2, "987") == 0)
            prints("strrev worked\n");
        else
            prints("strrev broken\n");

        itostr(123, buff);
        if (strcmp("123", buff) == 0)
            prints("itostr worked\n");
        else
            prints("itostr broken\n");

        if (strcmp("1234", itostr(1234, buff)) == 0)
            prints("itostr worked\n");
        else
            prints("itostr broken\n");

        itostr(-7890, buff);
        if (strcmp("-7890", buff) == 0)
            prints("itostr worked\n");
        else
            prints("itostr broken\n");

        itostr(-456, buff);
        if (strcmp("-456", buff) == 0)
            prints("itostr worked\n");
        else
            prints("itostr broken\n");

        itostr(0, buff);
        if (strcmp("0", buff) == 0)
            prints("itostr worked\n");
        else
            prints("itostr broken\n");

        xtostr(0x123, buff);
        if (strcmp("123", buff) == 0)
            prints("xtostr worked\n");
        else
            prints("xtostr broken\n");

        char buff2[20];
        int ii;
        for (ii=0; ii<sizeof(buff2); ii++)
        {
            buff[ii] = (char)ii;
        }
        buff[sizeof(buff2) - 1] = 0;
        memset(buff2, 0, sizeof(buff2));
        memcpy(buff2, buff, sizeof(buff2));
        if (strcmp(buff, buff2) == 0)
            prints("memcpy worked\n");
        else
            prints("memcpy broken\n");

        memset(buff2, 0, sizeof(buff2));
        buff[sizeof(buff2) / 2] = 0;
        memcpy(buff2, buff, sizeof(buff2));
        if (memcmp(buff, buff2, sizeof(buff2)) == 0)
            prints("memcmp worked\n");
        else
            prints("memcmp broken\n");

        buff[sizeof(buff2) / 2 + 1] = 0x7F;
        if (memcmp(buff, buff2, sizeof(buff2)) > 0)
            prints("memcmp worked\n");
        else
            prints("memcmp broken\n");

        return 0;
    }

    if (1) ;    // make sure we allow if with null statements

    return 0;
}
