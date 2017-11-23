#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
typedef struct// 20 40
{
    char name[100];
    char eMail[100];
} ePersona;
char* persona_getName(ePersona* this);
void persona_setName(ePersona* this, char* nombre);
char* persona_getEMail(ePersona* this);
void persona_setEMail(ePersona* this, char* correo);
void persona_print(ePersona* this);
ePersona* persona_new(void);
int comparar_persona(ePersona* pPersonaAlfa, ePersona* pPersonaBravo);
#endif // PERSONA_H_INCLUDED
