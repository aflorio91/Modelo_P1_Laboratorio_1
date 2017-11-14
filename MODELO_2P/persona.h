#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
typedef struct// 20 40
{
    char name[100];
    char eMail[100];
}ePersona;

/*int persona_isBlackListed(void* ePersonaA,void* ePersonaB);*/
void persona_print(ePersona* this);
ePersona* persona_new(void);
void persona_block(ePersona* this);
#endif // PERSONA_H_INCLUDED
