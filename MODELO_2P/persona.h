#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
struct
{
    char name[20];
    char eMail[40];
    int black_listed;
} typedef ePersona;

int persona_isBlackListed(void* ePersonaA,void* ePersonaB);
void persona_print(ePersona* this);
ePersona* persona_new(void);
void persona_block(ePersona* this);
#endif // PERSONA_H_INCLUDED
