/*
 * Copyright 2022 Vasoo Veerapen
 * vasoo (dot) veerapen (at) gmail (dot) com
 * 
 * This file is part of SHAREMIG
 * 
 * SHAREMIG is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include <strsafe.h>

void showHelp(void)
{
    fprintf(stdout, "SHAREMIG Migrates CIFS sharenames and share level permissions across different NAS storage vendors.\n\n");
    fprintf(stdout, "Copyright(C) 2022 Vasoo Veerapen - vasoo (dot) veerapen (at) gmail (dot) com\n");
    fprintf(stdout, "This program is distributed in the hope that it will be useful,\n"
        "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
        "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the\n"
        "GNU General Public License for more details.\n\n"
        "You should have received a copy of the GNU General Public License\n"
        "along with this program.If not, see https://www.gnu.org/licenses/ \n\n"   
    );
    fprintf(stdout, "***** INSTRUCTIONS *****\n");
    fprintf(stdout, "You will probably need Domain Admin privileges for SHAREMIG to work properly across devices.\n");
    fprintf(stdout, "SHAREMIG must be launched from an elevated Administrator command prompt.\n");
    fprintf(stdout, "Normally, SHAREMIG is run after Robocopy operations.\n");
    fprintf(stdout, "\n");
    fprintf(stdout, "***** USAGE *****\n");
    fprintf(stdout, "SHAREMIG [-ss <srcsharename>] [-sh <sourcehost>] [-dh <desthost>] [-dp <destpath>] [-ds <destsharename>]\n");
    fprintf(stdout, "\n");
    fprintf(stdout, " -ss <srcsharename> the source sharename to be migrated. \n");
    fprintf(stdout, " -sh <srchost> the source hostname or IP.\n");
    fprintf(stdout, " -dh <desthost> the destination hostname or IP.\n");
    fprintf(stdout, " -dp <destpath> the directory on the destination host to which the sharename shall map.\n");
    fprintf(stdout, " -ds <destsharename> the target sharename to be given.\n");
    fprintf(stdout, " -? show this help.\n");
    fprintf(stdout, " \n");
    fprintf(stdout, "Example: \n");
    fprintf(stdout, " SHAREMIG -ss SHARE1 -sh HOST1 -dh HOST2 -dp c:\\filedata\\dir1 -ds SHARE2\n");
    fprintf(stdout, " Creates a sharename called SHARE2 on HOST2 and transfers the share level permissions from SHARE1\n");
}
