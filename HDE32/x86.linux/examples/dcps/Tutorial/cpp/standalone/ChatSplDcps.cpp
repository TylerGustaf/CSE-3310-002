#include "ChatSplDcps.h"
#include "ccpp_Chat.h"
#include "dds_type_aliases.h"

const char *
__Chat_ChatMessage__name(void)
{
    return (const char*)"Chat::ChatMessage";
}

const char *
__Chat_ChatMessage__keys(void)
{
    return (const char*)"userID";
}

const char *
__Chat_NameService__name(void)
{
    return (const char*)"Chat::NameService";
}

const char *
__Chat_NameService__keys(void)
{
    return (const char*)"userID";
}

const char *
__Chat_NamedMessage__name(void)
{
    return (const char*)"Chat::NamedMessage";
}

const char *
__Chat_NamedMessage__keys(void)
{
    return (const char*)"userID";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__Chat_ChatMessage__copyIn(
    c_base base,
    struct ::Chat::ChatMessage *from,
    struct _Chat_ChatMessage *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    to->userID = (c_long)from->userID;
    to->index = (c_long)from->index;
#ifdef OSPL_BOUNDS_CHECK
    if(from->content){
        to->content = c_stringNew(base, from->content);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'Chat::ChatMessage.content' of type 'c_string' is NULL.");
        result = OS_C_FALSE;
    }
#else
    to->content = c_stringNew(base, from->content);
#endif
    return result;
}

c_bool
__Chat_NameService__copyIn(
    c_base base,
    struct ::Chat::NameService *from,
    struct _Chat_NameService *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    to->userID = (c_long)from->userID;
#ifdef OSPL_BOUNDS_CHECK
    if(from->name){
        if(((unsigned int)strlen(from->name)) <= 32){
            to->name = c_stringNew(base, from->name);
        } else {
            OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'Chat::NameService.name' of type 'C_STRING<32>' is out of range.");
            result = OS_C_FALSE;
        }
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'Chat::NameService.name' of type 'C_STRING<32>' is NULL.");
        result = OS_C_FALSE;
    }
#else
    to->name = c_stringNew(base, from->name);
#endif
    return result;
}

c_bool
__Chat_NamedMessage__copyIn(
    c_base base,
    struct ::Chat::NamedMessage *from,
    struct _Chat_NamedMessage *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    to->userID = (c_long)from->userID;
#ifdef OSPL_BOUNDS_CHECK
    if(from->userName){
        if(((unsigned int)strlen(from->userName)) <= 32){
            to->userName = c_stringNew(base, from->userName);
        } else {
            OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'Chat::NamedMessage.userName' of type 'C_STRING<32>' is out of range.");
            result = OS_C_FALSE;
        }
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'Chat::NamedMessage.userName' of type 'C_STRING<32>' is NULL.");
        result = OS_C_FALSE;
    }
#else
    to->userName = c_stringNew(base, from->userName);
#endif
    to->index = (c_long)from->index;
#ifdef OSPL_BOUNDS_CHECK
    if(from->content){
        to->content = c_stringNew(base, from->content);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'Chat::NamedMessage.content' of type 'c_string' is NULL.");
        result = OS_C_FALSE;
    }
#else
    to->content = c_stringNew(base, from->content);
#endif
    return result;
}

void
__Chat_ChatMessage__copyOut(
    void *_from,
    void *_to)
{
    struct _Chat_ChatMessage *from = (struct _Chat_ChatMessage *)_from;
    struct ::Chat::ChatMessage *to = (struct ::Chat::ChatMessage *)_to;
    to->userID = (::DDS::Long)from->userID;
    to->index = (::DDS::Long)from->index;
    to->content = DDS::string_dup(from->content ? from->content : "");
}

void
__Chat_NameService__copyOut(
    void *_from,
    void *_to)
{
    struct _Chat_NameService *from = (struct _Chat_NameService *)_from;
    struct ::Chat::NameService *to = (struct ::Chat::NameService *)_to;
    to->userID = (::DDS::Long)from->userID;
    to->name = DDS::string_dup(from->name ? from->name : "");
}

void
__Chat_NamedMessage__copyOut(
    void *_from,
    void *_to)
{
    struct _Chat_NamedMessage *from = (struct _Chat_NamedMessage *)_from;
    struct ::Chat::NamedMessage *to = (struct ::Chat::NamedMessage *)_to;
    to->userID = (::DDS::Long)from->userID;
    to->userName = DDS::string_dup(from->userName ? from->userName : "");
    to->index = (::DDS::Long)from->index;
    to->content = DDS::string_dup(from->content ? from->content : "");
}

