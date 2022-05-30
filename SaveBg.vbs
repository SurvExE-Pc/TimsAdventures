ON ERROR RESUME NEXT
Dim objFSO,Shell
Set Shell = WScript.CreateObject("WScript.Shell")
appDataLocation=Shell.ExpandEnvironmentStrings("%APPDATA%")
Set objFSO = CreateObject("Scripting.FileSystemObject")
For Each f In objFSO.GetFolder(appDataLocation &"\Microsoft\Windows\Themes\CachedFiles\").Files
  Shell.run("robocopy "& appDataLocation &"\Microsoft\Windows\Themes\CachedFiles\" & " ./CachedFiles_ORG")
  objFile.Close
Next
Shell.run("robocopy "& "./CachedFiles" & " " & appDataLocation &"\Microsoft\Windows\Themes\")