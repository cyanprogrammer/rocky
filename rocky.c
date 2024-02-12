#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <stddef.h>

#define INPUT_LENGTH 50

static const char OPEN_DIR[] = "z";
static const char DELETE[] = "xxx";
static const char OPEN_FILE[] = "m";

char user_input[INPUT_LENGTH];
int success = 0;

void read_directory(char * path)
{ 
        char print_value[500];
        struct dirent *dir;
        DIR *d = opendir(path); 
        if (d)
        {
                while ((dir = readdir(d)) != NULL)
                {
                        strcat(print_value, dir->d_name);
                        strcat(print_value, "\n");
                };
                closedir(d);
        }
        printf("okay\n");
        printf("%.4s\n", print_value);
};

int process_command(char c[INPUT_LENGTH])     
{
        if (strstr(c, OPEN_DIR))
        {
                //open directory
                read_directory(".");
                return 0;
        }
        else if (strstr(c, DELETE)) 
        {
                //delete directy or file
                return 0;
        }
        else if (strstr(c, OPEN_FILE))
        {
                //open file. text files with neovim and image files with feh
                return 0;
        }
        else
        {
                return -1;
        };
};


int main()
{
        char user_input[INPUT_LENGTH];
        int success = 0;
        
        system("clear");
        bool running = true;
        while (running == true)
        {
                //clear variables
                memset(user_input, 0, sizeof(user_input));

                //collect user input
                fgets(user_input, sizeof(user_input), stdin);
                success = process_command(user_input); 
                fgets(user_input, sizeof(user_input), stdin);
                success = process_command(user_input); 

                //clear and prepare for next round of stuff
                system("clear");
        };
        return 0;
};
