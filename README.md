# sharemig
SHAREMIG is a Windows tool which helps system administrators migrate CIFS share names and share level permissions across different vendors. eg. from NetApp FAS to Dell EMC Unity. 
 
Normally, the tool is used after a robocopy. It automates the transfers of sharenames and associated share level permissions (helps when hundreds of sharenames/ share level permissions need to be copied across storage devices, and auditors are breathing down your neck.)  If done manually, a sysadmin would need to go into computer management, connect to a storage device, and manage the shares from there. 

To note that WMI/WinRM/Powershell commands e.g. New-SMBShare, etc. were found not work on enterprise NAS storage.

SHAREMIG uses the data access and storage WIN32 API function NetShareAdd which works only with Server Message Block (SMB) shares. Only members of the Administrators, System Operators, or Power Users local group can add file shares with a call to the NetShareAdd function. To transfer share level permissions the code the code fills in the members of the SHARE_INFO_502 structure and cbefore calling NetShareAdd. Normally, to add shares on Domain connected devices, Domain Admin rights are needed. SHAREMIG needs to run in an elevated command prompt.
