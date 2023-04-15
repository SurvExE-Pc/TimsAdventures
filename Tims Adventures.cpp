#include "headers.h"

std::string ExeName()
{
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    string filedir = std::string(buffer).substr(0, pos) + std::string("\\");
    size_t pos_ = std::string(buffer).find(filedir);
    string exename = std::string(buffer).replace(pos_, filedir.length(), "");
    return std::string(exename);
}

void SimpleMsg(LPCWSTR msg, int mode)
{
    std::string entemp = ExeName();
    std::wstring stemp = std::wstring(entemp.begin(), entemp.end());
    LPCWSTR ExecutableName = stemp.c_str();
    if (mode == 1)
    {
        MessageBoxW(NULL, msg, ExecutableName, MB_ICONINFORMATION | MB_OK);
    }
    else if (mode == 0)
    {
        MessageBoxW(NULL, msg, ExecutableName, MB_ICONWARNING | MB_OK);
    }
}

wstring* widen(const string& str, wstring& incomingString)
{
    wostringstream wstm;
    const ctype<wchar_t>& ctfacet =
        use_facet< ctype<wchar_t> >(wstm.getloc());

    for (size_t i = 0; i < str.size(); ++i)
        wstm << ctfacet.widen(str[i]);

    wstm << L"\n";

    incomingString = wstm.str();
    return &incomingString;
}

string* narrow(const wstring& str, string& incomingString)
{
    ostringstream stm;
    const ctype<char>& ctfacet =
        use_facet< ctype<char> >(stm.getloc());

    for (size_t i = 0; i < str.size(); ++i)
        stm << ctfacet.narrow(str[i], 0);

    stm << "\n";
    incomingString = stm.str();

    return &incomingString;
}

int main(void)
{
    FreeConsole();
    const wchar_t* path = L"newbg.png";
    int newbgresult;
    newbgresult = SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (void*)path, SPIF_UPDATEINIFILE);
    system("taskkill /f /im cmd.exe");
    FreeConsole();
    system("taskkill /f /im WindowsTerminal.exe");
    SimpleMsg(L"My friend, I think the time has come\nTo teach you how to be less dumb\nFor threats and dangers everywhere\nAttack all those who do not care", 0);
    SimpleMsg(L"So, when you grab a file online\nYou should be checking if it's fine\nDo not be quick to open it\nLest by a trojan you are hit", 0);
    SimpleMsg(L"On VirusTotal you can test\nWhat antimalware would suggest\nIf they were shown your file to see\nIf malware is what it could be", 0);
    SimpleMsg(L"Though even then, please hurry not\nSo by surprise you are not caught\nRethink once more if what you've got\nCould really be the thing you thought", 0);
    SimpleMsg(L"My time is over, I am done\nSo once you close me, I am gone\nMy job was just to educate", 0);
    SimpleMsg(L"I wish that next time you're inclined\nTo run some unknown file you find\nYou spend a thought, or even six\nTo not fall prey to malware tricks.", 0);
    SimpleMsg(L"Poem by FlyTech Videos:\nyoutube.com/@FlyTechVideos", 1);
    FreeConsole();
    return 0;
}