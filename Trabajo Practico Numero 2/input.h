#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

int getInt(int* input,char mensaje[],char eMensaje[],int lowLimit,int hiLimit);
int getFloat(float* input,char mensaje[],char eMensaje[],float lowLimit,float hiLimit);
int getString(char* input,char mensaje[],char eMensaje[],int lowLimit,int hiLimit);
int getSN(char* input, char message[], char eMessage[]);

#endif // INPUT_H_INCLUDED
