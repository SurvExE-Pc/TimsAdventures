#pragma once

#ifndef _WIN32_WINNT                 
#define _WIN32_WINNT 0x0501
#endif						

#include <stdio.h>
#include <tchar.h>
#include <locale>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

wstring* widen(const string& str);
string* narrow(const wstring& str);