/*
   argsinfo.h -  include file for argument storage module
   See argsinfo.c for source.
*/

typedef struct s_args_info
{
   char **args;              /* argv-style array of args */
   int argslen;              /* length of args array */
   int argcnt;               /* nbr of args currently in array */
} Args_Info;

Args_Info *new_args_info(void);
void zero_args(Args_Info * args);
int add_arg(Args_Info * args, char *string); /* Returns 0 == OK, or 2 == ERROR (out of memory) */
int ins_arg(Args_Info * args, char *string, int pos); /* Returns 0 == OK, or 2 == ERROR (out of
                                                       * memory) */
