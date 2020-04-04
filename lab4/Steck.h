//---------------------------------------------------------------------------

#ifndef SteckH
#define SteckH
//---------------------------------------------------------------------------

struct Node_op
{
  char c;
  Node_op* p;
};

struct Node_num
{
  float c;
  Node_num* p;
};

typedef enum
{
  all_true=1,
  bad_operands,
  few_brackets,
  much_brackets,
  few_operands,
  few_operators
}errors;

class Stack
{
public:
  char* s;
  char* sv;
  Node_op* t1;
  Node_num* t2;
  void Stack_init();
  void check();
  void bspaces();
  void postfix();
  float calc(float A, float B, float C, float D, float E);
  void out_err_code();
  errors err_code;
  ~Stack();
private:
  int prioritet_stack();
  bool operand_true(char c);
  void firstOp(char c);
  void pushOp(char c);
  char popOp();
  void firstNum(float c);
  void pushNum(float c);
  float popNum();
};
#endif
