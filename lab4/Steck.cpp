#pragma hdrstop
#include "string.h"
#include "stdlib.h"
#include "Steck.h"
#pragma package(smart_init)


//--------------------------------------------------------------------------
void Stack::postfix()
{
int i;
int j=0;
int pr=0;
int l=strlen(s);
  for(i=0;i<l;i++)
  {
	if(s[i]==' ') {sv[j++]=s[i]; continue;}
	if((s[i]>='('&&s[i]<='+')||s[i]=='-'||s[i]=='/')
	{
	  switch(s[i])
	  {
		 case '(':
		 {
		   if(!t1) {firstOp(s[i]);}
		   else {pushOp(s[i]);}
		   break;
		 }
		 case '*':
		 case '/':
		 {
		   if(!t1) {firstOp(s[i]); break;}
		   pr=prioritet_stack();
		   if(pr==3||pr==1) {pushOp(s[i]); break;}
		   if(t1->c=='/') sv[j++]=popOp();
		   if(t1) {pushOp(s[i]); break;}
		   else {firstOp(s[i]); break;}
		 }
		 case '+':
		 case '-':
		 {
		   if(!t1) {firstOp(s[i]); break;}
		   pr=prioritet_stack();
		   if(pr==3) {pushOp(s[i]); break;}
		   else
		   {
			 while(pr<3&&t1)
			 {
			   sv[j++]=popOp();
			   if(t1) pr=prioritet_stack();
			 }
		   }
		  if(t1) {pushOp(s[i]); break;}
		  else {firstOp(s[i]); break;}
		 }
		 case ')':
		 {
		   pr=prioritet_stack();
		   while(pr!=3)
		   {
			 sv[j++]=popOp();
			 pr=prioritet_stack();
		   }
		   sv[j]= popOp();
		 }
	  }
	}
	else {sv[j++]=s[i]; continue;}
  }
  if(t1){ while(t1) sv[j++]=popOp();}
  sv[j]='\0';
  strcpy(s,sv);
}

//-------------------------------------------------------------------------
float Stack::calc(float A, float B, float C, float D, float E)
{
int i,j=0,l=strlen(s);
char sc[10];
float a,b;
  for(i=0;i<l;i++)
  {
	if(s[i]==' ') continue;
	else
	if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
	{
		  a=popNum();
		  b=popNum();
		  switch(s[i])
		  {
			   case '+': {a=a+b; break;}
			   case '-': {a=b-a; break;}
			   case '*': {a=a*b; break;}
			   case '/': {a=b/a; break;}
		  }
		  if(!t2) {firstNum(a); }
		  else {pushNum(a); }
	}
	else
	{
	   while(operand_true(s[i])&&s[i]!='\0')
	   {
	   //	 sc[j++]=s[i];
		 if (s[i] == 'a' || s[i] == 'A') a = A; else
		 if (s[i] == 'b' || s[i] == 'B') a = B; else
		 if (s[i] == 'c' || s[i] == 'C') a = C; else
		 if (s[i] == 'd' || s[i] == 'D') a = D; else
		 if (s[i] == 'e' || s[i] == 'E') a = E;
		 i++;
	   }
	  //sc[j]='\0';
	 // a = atof(sc);
	  j=0;
	  if(!t2) { firstNum(a); }
	  else { pushNum(a); }
	}
  }
  return popNum();
}
//---------------------------------------------------------------------------
void Stack::Stack_init()
{
  t1=0;
  t2=0;
  s=new char[100];
  sv=new char[100];
  err_code=all_true;
}
//-------------------------------------------------------------------------
Stack::~Stack()
{
  delete[] s;
  delete[] sv;
}
//---------------------------------------------------------------------------
void Stack::firstOp(char c)  //создание стека операций
{
  Node_op* pv=new Node_op;
  pv->c=c;
  pv->p=0;
  t1=pv;
}
//---------------------------------------------------------------------------
void Stack::pushOp(char c)
{
  Node_op* pv=new Node_op;
  pv->c=c;
  pv->p=t1;
  t1=pv;
}
//--------------------------------------------------------------------------
char Stack::popOp()  //выталкивание из стека операций
{
  char z=t1->c;
  Node_op* pv=t1;
  t1=t1->p;
  delete pv;
  return z;
}
//--------------------------------------------------------------------------
void Stack::firstNum(float c)  //создание стека чисел
{
  Node_num* pv=new Node_num;
  pv->c=c;
  pv->p=0;
  t2=pv;
}
//---------------------------------------------------------------------------
void Stack::pushNum(float c)
{
  Node_num* pv=new Node_num;
  pv->c=c;
  pv->p=t2;
  t2=pv;
}
//--------------------------------------------------------------------------
float Stack::popNum()
{
  float z=t2->c;
  Node_num* pv=t2;
  t2=t2->p;
  delete pv;
  return z;
}
//--------------------------------------------------------------------------
bool Stack:: operand_true(char c)
{
  if((c>='0'&&c<='9') || (c>='A' && c<='Z') || (c>='a'&&c<='z') || c=='.') return true;
  else return false;
}
//---------------------------------------------------------------------------
int Stack::prioritet_stack()
{
  if(t1->c=='(')return 3;
  if(t1->c=='+'||t1->c=='-')return 1;
  return 2;
}
//---------------------------------------------------------------------------
void Stack::check()
{
 int sk=0;
 int rang=0;
 int l=strlen(s);
 int i;
 if(s[0] == ')') {err_code = much_brackets; return;}
 if(s[0] == '*'||s[0]=='/') {err_code = few_operands; return;}
 for(i = 0; i<l; i++)
 {
   if(s[i]=='(')
   {
	   if(i > 0 && operand_true(s[i-1]))  {err_code = few_operators; return;}
	   if(s[i+1] == '*' || s[i+1] == '/' || s[i+1] == ')')  {err_code = few_operands; return;}
	   sk++; continue;
   }
   if(s[i] == ')')
   {
		if((i > 0) && (s[i-1] == '*' || s[i-1] == '+' || s[i-1] == '-' || s[i-1] == '/')) {err_code = few_operands; return;}
		if(operand_true(s[i+1])||s[i+1]=='(') {err_code=few_operators; return;}
		sk--; continue;
   }
   if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-') {rang++; continue;}
   if(operand_true(s[i]))
   {
	 while (operand_true(s[++i]));
	 i--;
	 rang--;
   }
   else
   {
	err_code=bad_operands;
	return;
   }
 }
  s[i]='\0';
  if(rang>-1) {err_code = few_operands; return;}
  if(rang<-1) {err_code = few_operators; return;}
  if(sk>0) {err_code = few_brackets; return;}
  if(sk<0) {err_code = much_brackets; return;}
}
//--------------------------------------------------------------------------
void Stack::bspaces()
{
  int l=strlen(s);
  int i,j=0;
  for(i = 0;i<l;i++)
  {
	if((s[i]>='(' && s[i]<='+') || s[i]=='-' || s[i]=='/') { sv[j++]=s[i]; sv[j++]=' '; continue;}
	else
	{
	  sv[j++]=s[i];
	  while(operand_true(s[++i])==1&&s[i]!='\0')
	  sv[j++]=s[i];
	  sv[j++]=' ';
	}
	i--;
  }
  sv[j]='\0';
}

