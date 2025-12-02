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
    while (i < len && (str[i] == ' ' || str[i] == '\r')) {
        i++;
    }

    /* TODO: extract digits and compute num */

    /* TODO: require at least one digit */

    /* TODO: assign *value */

    return 0; /* replace when implemented */
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

    /* TODO: copy alphabetic characters into name[] */

    name[j] = '\0';
    *index = i;

    /* TODO: return 1 if name length > 0 */
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

    /* TODO: extract token into buf[] */

    buf[j] = '\0';
    *index = i;

    /* TODO: call parse_int and check range */

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

    /* TODO:
       - open output file with fopen()
       - check if NULL → close input file and return
    */

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

    /* TODO:
       - compute average
       - write correct output format to summary file
    */

    /* TODO:
       - close files
    */
}

