/**
 *  Copyright 2008-2010 Cheng Shi.  All rights reserved.
 *  Email: shicheng107@hotmail.com
 */

#ifndef WINHTTPCLIENT_H
#define WINHTTPCLIENT_H

#pragma comment(lib, "Winhttp.lib")

#include "RegExp.h"
#include "StringProcess.h"
#include <comutil.h>
#include <windows.h>
#include <Winhttp.h>
#include <string>
using namespace std;

typedef bool (*PROGRESSPROC)(double);

static const unsigned int INT_RETRYTIMES = 3;
static wchar_t *SZ_AGENT = L"WinHttpClient";
static const int INT_BUFFERSIZE = 10240;    // Initial 10 KB temporary buffer, double if it is not enough.

class WinHttpClient
{
public:
    inline WinHttpClient(const wstring &url, PROGRESSPROC progressProc = NULL);
    inline ~WinHttpClient(void);

    // It is a synchronized method and may take a long time to finish.
    inline bool SendHttpRequest(const wstring &httpVerb = L"GET", bool disableAutoRedirect = false);
    inline wstring GetResponseHeader(void);
    inline wstring GetResponseContent(void);
    inline wstring GetResponseCharset(void);
    inline wstring GetResponseStatusCode(void);
    inline wstring GetResponseLocation(void);
    inline wstring GetRequestHost(void);
    inline const BYTE *GetRawResponseContent(void);
    inline unsigned int GetRawResponseContentLength(void);
    inline unsigned int GetRawResponseReceivedContentLength(void);
    inline bool SaveResponseToFile(const wstring &filePath);
    inline wstring GetResponseCookies(void);
    inline bool SetAdditionalRequestCookies(const wstring &cookies);
    inline bool SetAdditionalDataToSend(BYTE *data, unsigned int dataSize);
    inline bool UpdateUrl(const wstring &url);
    inline bool ResetAdditionalDataToSend(void);
    inline bool SetAdditionalRequestHeaders(const wstring &additionalRequestHeaders);
    inline bool SetRequireValidSslCertificates(bool require);
    inline bool SetProxy(const wstring &proxy);
    inline DWORD GetLastError(void);
    inline bool SetUserAgent(const wstring &userAgent);
    inline bool SetForceCharset(const wstring &charset);
    inline bool SetProxyUsername(const wstring &username);
    inline bool SetProxyPassword(const wstring &password);
    inline bool SetTimeouts(unsigned int resolveTimeout = 0,
                            unsigned int connectTimeout = 60000,
                            unsigned int sendTimeout = 30000,
                            unsigned int receiveTimeout = 30000);

private:
    inline WinHttpClient(const WinHttpClient &other);
    inline WinHttpClient &operator =(const WinHttpClient &other);
    inline bool SetProgress(unsigned int byteCountReceived);

    HINTERNET m_sessionHandle;
    bool m_requireValidSsl;
    wstring m_requestURL;
    wstring m_requestHost;
    wstring m_responseHeader;
    wstring m_responseContent;
    wstring m_responseCharset;
    BYTE *m_pResponse;
    unsigned int m_responseByteCountReceived;   // Up to 4GB.
    PROGRESSPROC m_pfProcessProc;
    unsigned int m_responseByteCount;
    wstring m_responseCookies;
    wstring m_additionalRequestCookies;
    BYTE *m_pDataToSend;
    unsigned int m_dataToSendSize;
    wstring m_additionalRequestHeaders;
    wstring m_proxy;
    DWORD m_dwLastError;
    wstring m_statusCode;
    wstring m_userAgent;
    bool m_bForceCharset;
    wstring m_proxyUsername;
    wstring m_proxyPassword;
    wstring m_location;
    unsigned int m_resolveTimeout;
    unsigned int m_connectTimeout;
    unsigned int m_sendTimeout;
    unsigned int m_receiveTimeout;
};

#endif // WINHTTPCLIENT_H
