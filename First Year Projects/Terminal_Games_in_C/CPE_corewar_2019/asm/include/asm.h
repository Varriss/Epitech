/*
** EPITECH PROJECT, 2020
** ASM
** File description:
** Asm header
*/

#ifndef ASM_H_
#define ASM_H_

//////////////////////// VAR ////////////////////////

// def struct
typedef struct list_s list_t;
typedef struct data_s data_t;
typedef struct compiled_data_s compiled_data_t;
typedef struct label_s label_t;

// struct
struct compiled_data_s
{
    char *data;
    unsigned int len;
};
struct data_s
{
    compiled_data_t compiled;
    unsigned int line_id;
    char *last_line;
    list_t *labels;
};
struct label_s
{
    int to_find;
    char *name;
    int pos;
    int line_id;
    int is_long_size;
    unsigned int instruction_at;
};

// data
static data_t const EMPTY_DATA = {{NULL, 0}, 0, NULL, NULL};

///////////////////// PROTOTYPE /////////////////////

// parser
int parse_file(char const *path);
int get_header(int fd, data_t *data);
int get_header_name(int fd, data_t *data);
int get_header_comment(int fd, data_t *data);

// string parser
int is_string_line(char const *line);
char *get_string(char const *line, char const *name);

// compiler
int compile_line(data_t *data, compiled_data_t *compiled, char const *line);
char get_coding_byte(data_t *data, char **args, int op_id);
int compile_argument(data_t *data, compiled_data_t *compiled,
    char *arg, int op_id);
int compile_direct_label_argument(data_t *data,
    compiled_data_t *compiled, char *arg, int op_id);
int compile_missed_labels(data_t *data);

// data
int data_create(data_t *data);
void data_destroy(data_t data);
int data_destroy_rtn_failure(data_t data);

// label
int is_valid_label_name(char *name, int line_id);
label_t *label_create(char *name, int pos);
label_t *label_create_to_find(char *name, int pos,
    int line_id, int is_long_size);
void label_destroy(label_t *label);
int add_label_to_data(data_t *data, char *arg);

int append_compiled_data(compiled_data_t *data, compiled_data_t to_add);

// lexer
char *lexe_line(char *line);

// output
char *get_output_path(char const *path);
int save_to_file(char const *path, char const *data, size_t data_len);

// msg
void print_empty_file(void);
void print_warning(int line, char const *warning);
void print_error(int line, char const *error);
void print_inv_nb_args(int line, int op_id, int nb_args);

void get_file_name(char *get_name);
void set_file_name(char const *set_name);

////////////////////////// for unit_tests ///////////////////////////////

// parser
int add_header_name(data_t *data, char *line);
int add_header_comment(data_t *data, char *line);

// lexer
char *simplify_line(char const *line);
void remove_comment(char *line);
void remove_multi_spaces(char *line);
void remove_spaces_between_args(char *line);

#endif /* !ASM_H_ */