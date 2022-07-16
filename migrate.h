#pragma once

#include <windows.h>
#include <tchar.h>
#include <lm.h>
#include <strsafe.h>

NET_API_STATUS migrate(LPTSTR lpszSourceHost, LPTSTR lpszSourceShare, LPTSTR lpszTargetHost, LPTSTR lpszTargetPath, LPTSTR lpszTargetShare)
{
    DWORD parm_err = 0;
    PSHARE_INFO_502 BufPtrSource;
    SHARE_INFO_502 BufPtrTarget;
    NET_API_STATUS result;
    int inkey = 0;

    if ((result = NetShareGetInfo(lpszSourceHost, lpszSourceShare, 502, (LPBYTE*)&BufPtrSource)) == ERROR_SUCCESS)
    {
        fprintf(stdout, "Starting migration of sharename: < %S > at path < %S >\n", BufPtrSource->shi502_netname, BufPtrSource->shi502_path);

        if (IsValidSecurityDescriptor(BufPtrSource->shi502_security_descriptor))
        {
            BufPtrTarget.shi502_netname = lpszTargetShare;
            BufPtrTarget.shi502_type = BufPtrSource->shi502_type;
            BufPtrTarget.shi502_remark = BufPtrSource->shi502_remark;
            BufPtrTarget.shi502_permissions = BufPtrSource->shi502_permissions;
            BufPtrTarget.shi502_max_uses = BufPtrSource->shi502_max_uses;
            BufPtrTarget.shi502_current_uses = BufPtrSource->shi502_current_uses;
            BufPtrTarget.shi502_passwd = BufPtrSource->shi502_passwd;
            BufPtrTarget.shi502_reserved = BufPtrSource->shi502_reserved;
            BufPtrTarget.shi502_security_descriptor = BufPtrSource->shi502_security_descriptor;
            BufPtrTarget.shi502_path = lpszTargetPath;

            result = NetShareAdd(lpszTargetHost, 502, (LPBYTE)&BufPtrTarget, &parm_err);

            if (result == ERROR_SUCCESS)
                fprintf(stderr, "[ERROR_SUCCESS] Sucess.\n");
            else if (result == ERROR_ACCESS_DENIED)
                fprintf(stderr, "[ERROR_ACCESS_DENIED] The user does not have access to the requested information.\n");
            else if (result == ERROR_INVALID_LEVEL)
                fprintf(stderr, "[ERROR_INVALID_LEVEL] The value specified for the level parameter is not valid.\n");
            else if (result == ERROR_INVALID_NAME)
                fprintf(stderr, "[ERROR_INVALID_NAME] The character or file system name is not valid.\n");
            else if (result == ERROR_INVALID_PARAMETER)
                fprintf(stderr, "[ERROR_INVALID_PARAMETER] The specified parameter is not valid.\n");
            else if (result == NERR_DuplicateShare)
                fprintf(stderr, "[ERROR_DUPLICATE_SHARE] The share name is already in use.\n");
            else if (result == NERR_RedirectedPath)
                fprintf(stderr, "[ERROR_REDIRECTED_PATH] The operation is not valid for a redirected resource.\n");
            else if (result == NERR_UnknownDevDir)
                fprintf(stderr, "[ERROR_DEVICE_DIR] The device or directory does not exist.\n");
            else
                fprintf(stderr, "[ERROR_UNKNOWN] An unknown error occurred.\n");

            fprintf(stderr, "Share name: %S | Path: %S | Uses: %u | Return code: %u | Return parameter: %u\n", BufPtrTarget.shi502_netname, BufPtrTarget.shi502_path, BufPtrTarget.shi502_current_uses, result, parm_err);

        }
        else
        {
            fprintf(stderr, "[ERROR_INVALID_SECURITY_DESCRIPTOR] Not a valid security descriptor.\n");
        }

        NetApiBufferFree(BufPtrSource);
    }
    else
        fprintf(stderr, "Error %u occured getting source share information.\n", result);

    return result;
}







