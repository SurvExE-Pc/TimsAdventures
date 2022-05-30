ON ERROR RESUME NEXT
Dim objFSO,Shell
Set Shell = WScript.CreateObject("WScript.Shell")
appDataLocation=Shell.ExpandEnvironmentStrings("%APPDATA%")
Set objFSO = CreateObject("Scripting.FileSystemObject")
Shell.run("robocopy "& "./CachedFiles_ORG" & " " & appDataLocation &"\Microsoft\Windows\Themes\")
objFSO.DeleteFolder("./CachedFiles_ORG")
objFSO.DeleteFolder(appDataLocation & "\Microsoft\Windows\Themes\CachedFiles")
Shell.run("rename " & appDataLocation & "\Microsoft\Windows\Themes\CachedFiles_ORG CachedFiles")