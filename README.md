# sharemig
SHAREMIG is a Windows tool which helps system administrators migrate Enterprise NAS CIFS share names and share level permissions across different vendors. eg. from NetApp FAS to Dell EMC Unity. To note that WMI/WinRM/Powershell commands e.g. New-SMBShare, etc. did not work on certain enterprise NAS storage devices hence the need for an automated tool.
 
Normally, SHAREMIG is used after a robocopy. It automates the transfers of sharenames and associated share level permissions (helps when hundreds of sharenames/ share level permissions need to be copied across storage devices, and auditors are breathing down your neck.)  If done manually, a sysadmin would need to go into computer management, connect to the NAS storage device, and manage the shares from there. 

SHAREMIG uses the data access and storage WIN32 API function NetShareAdd which works only with Server Message Block (SMB) shares. Only members of the Administrators, System Operators, or Power Users local group can add file shares with a call to the NetShareAdd function. To transfer share level permissions the code fills in the members of the SHARE_INFO_502 structure from the source NAS and calls NetShareAdd to create the destination share with the same permissions. 

Normally, to add shares on Domain connected devices, Domain Admin rights are needed and SHAREMIG needs to run from an elevated command prompt.

SHAREMIG was tested on Windows Server 2016, does not depend on .NET and was compiled using VisuaL Studio Community 2019.
