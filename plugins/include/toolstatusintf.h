#ifndef _TOOLSTATUSINTF_H
#define _TOOLSTATUSINTF_H

#define TOOLSTATUS_PLUGIN_NAME L"ProcessHacker.ToolStatus"
#define TOOLSTATUS_INTERFACE_VERSION 1

typedef PPH_STRING (NTAPI *PTOOLSTATUS_GET_SEARCHBOX_TEXT)(
    VOID
    );

typedef BOOLEAN (NTAPI *PTOOLSTATUS_WORD_MATCH)(
    _In_ PPH_STRINGREF Text
    );

typedef VOID (NTAPI *PTOOLSTATUS_REGISTER_TAB_SEARCH)(
    _In_ INT TabIndex,
    _In_ PWSTR BannerText
    );

typedef VOID (NTAPI *PTOOLSTATUS_TAB_ACTIVATE_CONTENT)(
    _In_ BOOLEAN Select
    );

typedef struct _TOOLSTATUS_TAB_INFO
{
    PWSTR BannerText;
    PTOOLSTATUS_TAB_ACTIVATE_CONTENT ActivateContent;
} TOOLSTATUS_TAB_INFO, *PTOOLSTATUS_TAB_INFO;

typedef PTOOLSTATUS_TAB_INFO (NTAPI *PTOOLSTATUS_REGISTER_TAB_INFO)(
    _In_ INT TabIndex
    );

typedef struct _TOOLSTATUS_INTERFACE
{
    ULONG Version;
    PTOOLSTATUS_GET_SEARCHBOX_TEXT GetSearchboxText;
    PTOOLSTATUS_WORD_MATCH WordMatch;
    PTOOLSTATUS_REGISTER_TAB_SEARCH RegisterTabSearchDeprecated;
    PPH_CALLBACK SearchChangedEvent;
    PTOOLSTATUS_REGISTER_TAB_INFO RegisterTabInfo;
} TOOLSTATUS_INTERFACE, *PTOOLSTATUS_INTERFACE;

#endif
