#include <stdio.h>
#include <string.h>
#include "records.h"

/*
    RULES:
    - Use fgets() to read lines.
    - Treat ONLY ' ' (and '\n', '\r') as whitespace.
    - Do NOT use: sscanf, strtok, atoi, strtol.
    - All parsing must be done manually.
*/

/* ============================================================
   parse_int
   Convert a numeric string into an integer manually.
   Return 1 if valid, 0 otherwise.
   (Some guidance provided)
   ============================================================ */
int parse_int(const char *str, int *value) {
    int i = 0;
    int len = strlen(str);
    int num = 0;
    int has_digit = 0;

    /* Skip leading spaces or '\r' */
    while (i < len && (str[i] == '\n' || str[i] == ' ' || str[i] == '\r')) {
        i++;
    }

    /* TODO: extract digits and compute num */
    while (i < len && str[i] >= '0' && str[i] <= '9' ){
      has_digit++;
      num = num * 10 + str[i] - '0';
      i++;
    }
   //  for(size_t j = i; j < len; j++){
   //    if(str[j] >= '0' && str[j] <= '9'){
   //       has_digit++;
   //       num = num * 10 + str[j] - '0';
   //    }else{
   //       return 0;
   //    }
   //}
    
    /* TODO: require at least one digit */
    if(has_digit <= 0){
      return 0;
    }
    /* TODO: assign *value */
    *value = num;

    return 1; /* replace when implemented */
}

/* ============================================================
   parse_name
   Extract alphabetic name starting at *index.
   Update *index.
   Return 1 if valid name, 0 otherwise.
   (Some guidance, less than above)
   ============================================================ */
int parse_name(const char *line, char *name, int *index) {
    int i = *index;
    int len = strlen(line);
    int j = 0;

    /* Skip spaces and '\r' */
    while (i < len && (line[i] == ' ' || line[i] == '\r')) {
        i++;
    }


    while (i < len && ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))){
      /* TODO: copy alphabetic characters into name[] */

      // the passing name size appears to be always 50
      if(j < 49){
         name[j] = line[i];
         i++;
         j++; 
      }else{
         break;
      }
    }
    
    name[j] = '\0';
    *index = i;

    /* TODO: return 1 if name length > 0 */
    if (strlen(name) > 0){
      return 1;
    }
    return 0;
}

/* ============================================================
   parse_grade
   Extract next token, convert with parse_int,
   validate it is between 0 and 100.
   (Minimal guidance)
   ============================================================ */
int parse_grade(const char *line, int *grade, int *index) {
    int i = *index;
    int len = strlen(line);
    char buf[50];
    int j = 0;

    /* TODO: skip leading spaces */
    while (i < len && (line[i] == '\n' || line[i] == ' ' || line[i] == '\r')) {
        i++;
    }

    /* TODO: extract token into buf[] */
    while (i < len && line[i] != ' ' && line[i] != '\n' && line[i] != '\r'){
      if(j < sizeof(buf)/sizeof(char)){
         buf[j] = line[i];
         i++;
         j++;
      }else{
         break;
      }
    }
    buf[j] = '\0';
    *index = i;
    int temp = -1;
    /* TODO: call parse_int and check range */
    if(parse_int(buf, &temp)){
      if(temp >= 0 && temp <= 100){
         *grade = temp;
         return 1;
      }
    }

    return 0;
}

/* ============================================================
   process_file
   Students MUST write:
   - opening the input file
   - opening output file
   - reading lines with fgets()
   - calling parse_name + parse_grade
   - counting valid/invalid
   - computing avg
   - writing summary.txt
   - closing both files

   (Almost no code provided — they write everything)
   ============================================================ */
void process_file(const char *input_filename, const char *output_filename) {

    /* TODO:
       - open input file with fopen()
       - check if NULL → print error and return
    */
   FILE *input_f = fopen(input_filename, "r");
   if(!input_f){
      perror("fopen() for input file failed");
      return;
   }

    /* TODO:
       - open output file with fopen()
       - check if NULL → close input file and return
    */
   FILE *output_f = fopen(output_filename, "w");
   if(!output_f){
      perror("fopen() for output file failed");
      return;
   }

    /* Suggested local variables: */
    char line[200];
    int valid = 0;
    int invalid = 0;
    int sum = 0;

    /* TODO:
       - While fgets(...) succeeds:
           int idx = 0;
           char name[50];
           int grade;

           - Call parse_name
           - If OK, call parse_grade
           - Update valid/invalid and sum
    */

    // Assume each line has at most 99 characters
 
   while (fgets(line, 100, input_f) != NULL){
      int idx = 0;
      char name[50];
      int grade;
      if(!parse_name(line, name, &idx)){
         invalid++;
         continue;
      }
      if(!parse_grade(line, &grade, &idx)){
         invalid++;
         continue;
      }
      sum += grade;
      valid++;
      
   }
   if (ferror(input_f)) {
      fprintf(stderr, "I/O error");
   }

    /* TODO:
       - compute average
       - write correct output format to summary file
    */
   float avg = 0.0;
   if (valid > 0){
      avg = (float)sum / valid;
   }
   char buf[100];
   sprintf(buf, "VALID: %d\n", valid);
   fputs(buf, output_f);
   if (ferror(output_f)) {
      fprintf(stderr, "I/O error");
   }
   sprintf(buf, "INVALID: %d\n", invalid);
   fputs(buf, output_f);
   if (ferror(output_f)) {
      fprintf(stderr, "I/O error");
   }
   sprintf(buf, "AVERAGE: %.2f\n", avg);
   fputs(buf, output_f);
   if (ferror(output_f)) {
      fprintf(stderr, "I/O error");
   }

    /* TODO:
       - close files
    */
   fclose(input_f);
   fclose(output_f);
   
}

