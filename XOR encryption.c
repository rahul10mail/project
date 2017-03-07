//User Enters source and target file via command line arguments. This program encrypts source file and saves in the target file

#include <stdlib.h>
#include <stdio.h>

#define KEY '&'

int main(int argc, char *argv[])
{
   FILE *source_file, *target_file;

   if ((source_file = fopen(argv[1], "rb")) == NULL)
   {
      fprintf(stdout, "Can't open %s\n", argv[1]);

      exit(EXIT_FAILURE);
   }

   if ((target_file = fopen(argv[2], "wb")) == NULL)
   {
      fprintf(stdout, "Can't open %s\n", argv[2]);

      exit(EXIT_FAILURE);
   }

   int source, target;

   while ((source = fgetc(source_file)) != EOF)
   {
      target = source ^ KEY;

      fputc(target, target_file);
   }

   fclose(source_file);
   fclose(target_file);

   return 0;
}
