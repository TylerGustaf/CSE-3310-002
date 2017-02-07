#ifndef CHATSPLTYPES_H
#define CHATSPLTYPES_H

#include "ccpp_Chat.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __Chat_Chat__load (c_base base);

extern c_metaObject __Chat_nameType__load (c_base base);
typedef c_string _Chat_nameType;

extern c_metaObject __Chat_ChatMessage__load (c_base base);
extern const char * __Chat_ChatMessage__keys (void);
extern const char * __Chat_ChatMessage__name (void);
struct _Chat_ChatMessage ;
extern  c_bool __Chat_ChatMessage__copyIn(c_base base, struct Chat::ChatMessage *from, struct _Chat_ChatMessage *to);
extern  void __Chat_ChatMessage__copyOut(void *_from, void *_to);
struct _Chat_ChatMessage {
    c_long userID;
    c_long index;
    c_string content;
};

extern c_metaObject __Chat_NameService__load (c_base base);
extern const char * __Chat_NameService__keys (void);
extern const char * __Chat_NameService__name (void);
struct _Chat_NameService ;
extern  c_bool __Chat_NameService__copyIn(c_base base, struct Chat::NameService *from, struct _Chat_NameService *to);
extern  void __Chat_NameService__copyOut(void *_from, void *_to);
struct _Chat_NameService {
    c_long userID;
    _Chat_nameType name;
};

extern c_metaObject __Chat_NamedMessage__load (c_base base);
extern const char * __Chat_NamedMessage__keys (void);
extern const char * __Chat_NamedMessage__name (void);
struct _Chat_NamedMessage ;
extern  c_bool __Chat_NamedMessage__copyIn(c_base base, struct Chat::NamedMessage *from, struct _Chat_NamedMessage *to);
extern  void __Chat_NamedMessage__copyOut(void *_from, void *_to);
struct _Chat_NamedMessage {
    c_long userID;
    _Chat_nameType userName;
    c_long index;
    c_string content;
};

#endif
