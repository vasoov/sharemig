#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include "migrate.h"
#include "showhelp.h"

#pragma comment(lib, "Netapi32.lib")
#pragma comment(lib, "Advapi32.lib")

int _tmain(int argc, LPTSTR argv[])
{
    int more = 1;

    if (argc < 2)
    {
        showHelp();
        return 0;
    }
    
    LPTSTR lpszSourceHost = NULL, lpszSourceShare = NULL, lpszTargetHost = NULL, lpszTargetPath = NULL, lpszTargetShare = NULL, lpszCommandFile = NULL;

    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            if (argv[i][1] == '?')
            {
                showHelp();
                return 0;
            }

            if (argv[i][1] == 's' && argv[i][2] == 's')
            {
                if (argv[i + 1])
                {
                    lpszSourceShare = argv[i + 1]; // source share name
                    fprintf(stdout, "Source sharename:\t\t%S\n", lpszSourceShare);
                }
                else
                {
                    fprintf(stdout, "-ss : Source sharename must be specified.\n");
                    more = 0;
                }
            }

            if (argv[i][1] == 's' && argv[i][2] == 'h')
            {
                if (argv[i + 1])
                {
                    lpszSourceHost = argv[i + 1];
                    fprintf(stdout, "Source host:\t\t%S\n", lpszSourceHost);
                }
                else
                {
                    fprintf(stdout, "-sh : Source IP/hostname must be specified.\n");
                    more = 0;
                }
            }

            if (argv[i][1] == 'd' && argv[i][2] == 's')
            {
                if (argv[i + 1])
                {
                    lpszTargetShare = argv[i + 1];
                    fprintf(stdout, "Destination sharename:\t\t%S\n", lpszTargetShare);
                }
                else
                {
                    fprintf(stdout, "-ds : Destination sharename must be specified.\n");
                    more = 0;
                }
            }
 
            if (argv[i][1] == 'd' && argv[i][2] == 'p')
            {
                if (argv[i + 1])
                {
                    lpszTargetPath = argv[i + 1]; //target path
                    fprintf(stdout, "Destination path:\t\t%S\n", lpszTargetPath);
                }
                else
                {
                    fprintf(stdout, "-dp : Destination path must be specified.\n");
                    more = 0;
                }
            }

            if (argv[i][1] == 'd' && argv[i][2] == 'h')
            {
                if (argv[i + 1])
                {
                    lpszTargetHost = argv[i + 1];
                    fprintf(stdout, "Destination host:\t\t%S\n", lpszTargetHost);
                }
                else
                {
                    fprintf(stdout, "-dh : Destination IP/hostname must be specified.\n");
                    more = 0;
                }
            }

          
        }
    }

    if (!more)
    {
        showHelp();
        exit(EXIT_FAILURE);
    }

    if (lpszSourceHost && lpszSourceShare && lpszTargetHost && lpszTargetPath && lpszTargetShare)
    {
        migrate(lpszSourceHost, lpszSourceShare, lpszTargetHost, lpszTargetPath, lpszTargetShare);
    }
    else
    {
        fprintf(stderr, "[ERROR] Invalid input parameters detected.\n");
        exit(EXIT_FAILURE);
    }

    //-ss SHARE1 -sh localhost -dh localhost -dp c:\temp\destination -ds SHARE2
    return 0;
}