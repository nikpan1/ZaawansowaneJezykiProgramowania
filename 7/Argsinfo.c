/*
  argsinfo.c -  source for argument storage module

  These routines manage argument storage and transparently allocate
  more storage space in chunks as needed.  You can manage multiple
  sets of arguments at once, if you wish.  The Args_Info pointer tells
  the routines which set to work on.  It is legal to read the elements
  of the structure, but you should not change them. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "argsinfo.h"


#define ARGS_INCR  50        /* increase in chunks of 50 */

/*
  Defined Functions

  new_args_info    alloc and init Args_Info structure
  zero_args    re-init Args_Info structure
  add_arg      add arg to Args_Info structure
*/



static char **grow_args(     /* increase size of Args_Info structure */
                          char **args,
                          int nbr_elements);


/*
  new_args_info - allocate and initialize a new Args_Info structure
  Returns pointer to Args_Info structure, or NULL if out of memory
*/

Args_Info *new_args_info(void)
{
   Args_Info *args;

   if ((args = (Args_Info *) malloc(sizeof(Args_Info))) == NULL)
      return (NULL);
   args->args = NULL;
   args->argslen = 0;
   args->argcnt = 0;
   return (args);
}                            /* new_args_info */



/*
  zero_args - reinitialize an Args_Info structure
  (prepares for accecpting a new set of arguments)

  Returns no value.
*/

void zero_args(Args_Info * args) /* structure to re-init */
{
   int i;

   if (args->args)
   {
      for (i = 0; i < args->argcnt; i++)
         if (args->args[i] != NULL)
            free(args->args[i]);
   }
   args->argcnt = 0;
   args->argslen = 0;
   if (args->args)
      free(args->args);
   args->args = NULL;
   return;
}                            /* zero_args */

/*
  add_arg - add string as an arg to Args_Info structure
  Automatically grows the structure as needed
  Returns 0 == OK, or 2 == ERROR (out of memory)
*/

int add_arg(Args_Info * args, char *string)  /* structure to add to and the arg to add */
{
   char **newargs;

   if ((args->argcnt + 1) >= args->argslen)
   {
      newargs = grow_args(args->args, ARGS_INCR + args->argslen);
      if (newargs == NULL)
         return (2);
      args->args = newargs;
      args->argslen += ARGS_INCR;
   }
   if ((args->args[args->argcnt] = (char *) calloc(strlen(string) + 1, sizeof(char))) == NULL)
   {
      fprintf(stderr, "No memory for new args");
      return (2);
   }
   strcpy(args->args[args->argcnt], string);
   args->argcnt++;
   args->args[args->argcnt] = NULL;
   return (0);
}                            /* add_args */


int ins_arg(Args_Info * args, char *string, int pos)  /* structure to add to and the arg to add */
{
   char **newargs;

   if (pos < 0)
   {
      fprintf(stderr, "ins_arg - pos < 0 !");
      return (2);
   }
   if ((args->argcnt + 2) >= args->argslen)
   {
      newargs = grow_args(args->args, ARGS_INCR + args->argslen);
      if (newargs == NULL)
         return (2);
      args->args = newargs;
      args->argslen += ARGS_INCR;
   }

   if (pos < args->argcnt)
      movmem((char *) &args->args[pos], (char *) &args->args[pos + 1], (args->argcnt - pos) * sizeof(char *)); /* sizeof(b->text[0]) */

   if (pos > args->argcnt)
      pos = args->argcnt;
   if ((args->args[pos] = (char *) calloc(strlen(string) + 1, sizeof(char))) == NULL)
   {
      fprintf(stderr, "No memory for new args");
      return (2);
   }
   strcpy(args->args[pos], string);
   args->argcnt++;
   args->args[args->argcnt] = NULL;
   return (0);
}                            /* ins_args */


/*
  grow_args - increase size of the Args_Info array by nbr_elements
  Returns pointer to new, enlarged Args_Info, or NULL if out of memory
*/

static char **grow_args(char **args, int nbr_elements)
{
   int size;
   char **newargs;

   size = nbr_elements * sizeof(char *);

   if (args)
      newargs = (char **) realloc(args, size);
   else
      newargs = (char **) malloc(size);

   return (newargs);
}                            /* grow_args */
