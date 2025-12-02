#ifndef RECORDS_H
#define RECORDS_H

int parse_name(const char *line, char *name, int *index);
int parse_grade(const char *line, int *grade, int *index);
int parse_int(const char *str, int *value);
void process_file(const char *input_filename, const char *output_filename);

#endif
