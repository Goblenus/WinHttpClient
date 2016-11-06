/**
 *  Copyright 2008-2009 Cheng Shi.  All rights reserved.
 *  Email: shicheng107@hotmail.com
 */

#ifndef STRINGPROCESS_H
#define STRINGPROCESS_H

#include "RegExp.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <comutil.h>
#pragma warning(push)
#pragma warning(disable: 4127)
#include <atlcomtime.h>
#pragma warning(pop)
using namespace std;

inline wstring Trim(const wstring &source, const wstring &targets);

inline bool PrepareString(wchar_t *dest, size_t *size, const wstring &src);

inline wstring ReplaceString(const wstring &srcStr, const wstring &oldStr, const wstring &newStr);

inline int StringToInteger(const wstring &number);

inline wstring LowerString(const wstring &text);

inline wstring UpperString(const wstring &text);

inline wstring GetAnchorText(const wstring &anchor);

inline wstring GetAnchorLink(const wstring &anchor);

inline bool SeparateString(const wstring &content, const wstring &delimiter, vector<wstring> &result);

inline wstring URLEncoding(const wstring &keyword, bool convertToUTF8 = true);

inline unsigned int GetSeparateKeywordMatchGrade(const wstring &source, const wstring &keyword);

inline unsigned int GetKeywordMatchGrade(const wstring &source, const wstring & keyword);

inline wstring GetDateString(const COleDateTime &time, const wstring &separator = L"-", bool align = true);

inline wstring GetDateString(int dayOffset, const wstring &separator = L"-", bool align = true);

inline wstring GetTimeString(const COleDateTime &time, const wstring &separator = L":", bool align = true);

inline wstring MD5(const wstring &text);

inline wstring FilterFileName(const wstring &name);

inline wstring GetMagic(unsigned int length);

inline wstring GetHost(const wstring &url);

inline wstring GetValidFileName(const wstring &fileName);

#endif // STRINGPROCESS_H
