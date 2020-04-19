#include "string.h"
#include "frame_buffer.h"
#include "mem_manager.h"

void strcpy(char* dest, char* src, int length)
{
    for(int i = 0; i < length; i++)
    {
        dest[i] = src[i];
    }
    dest[length] = '\0';
}

int strlen(char* src)
{
    int pos = 0;
    while(src[pos] != '\0')
    {
        pos++;
    }
    return pos;
}

void strcat(char* dest, char* appendString)
{
    // dest: "helloworld\0" 
    // appendString "world\0"
    // "hello world\0"
    int startNewStringAt = strlen(dest);
    for(int i = 0; i < strlen(appendString); i++)
    {
        dest[startNewStringAt] = appendString[i];
        startNewStringAt++;
    }
    dest[startNewStringAt] = '\0';
}

void strshorten(char* src, int shortenAmount)
{
    if(strlen(src) >= shortenAmount)
    {
        src[strlen(src)-shortenAmount] = '\0';
    }
}
char *append(char *orig, char c)
{
    int sz = strlen(orig);
    char *str = getMem(sz + 2);
    strcpy(str, orig, (sz +2));
    str[sz] = c;
    str[sz + 1] = '\0';
    return str;
}

void strtok(char** dest, char* src)
{
    
    int j = 0;
    int follower = 0;
    char* emptyPointer = getMem(strlen(src));
    for (int i = 0; i < strlen(src); i++)
    {
        
        if(strlen(emptyPointer) < 1)
        {
            emptyPointer = getMem(strlen(src));
        }

        if(src[i] == 32 || src[i] == '\0')
        {
            dest[j] = getMem(follower);
            strcpy(dest[j], emptyPointer, follower);
            freeMem(emptyPointer, strlen(src));
            follower = 0;  
            j += 4;
        }
        else
        {
            strcat(emptyPointer, &src[i]);
        }
        follower++;       
    }
    freeMem(emptyPointer, strlen(src));
    fb_clear();
    fb_write_string(0, dest[4], strlen(dest[4]));
}

//  int j = 0;
//     int follower = 0;
//     char* emptyPointer = getMem(strlen(src));
//     for (int i = 0; i < strlen(src); i++)
//     {
        
//         if(strlen(emptyPointer) < 1)
//         {
//             emptyPointer = getMem(strlen(src));
//         }

//         if(src[i] == 32 || src[i] == '\0')
//         {
//             dest[j] = getMem(follower);
//             strcpy(dest[j], emptyPointer, follower);
//             freeMem(emptyPointer, strlen(src));
//             follower = 0;  
//             j++;
//         }
//         else
//         {
//             strcat(emptyPointer, &src[i]);
//         }
//         follower++;       
//     }
//     freeMem(emptyPointer, strlen(src));
//     fb_clear();
//     fb_write_string(0, dest[0], strlen(dest[0]));

