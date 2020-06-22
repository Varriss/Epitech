/*
** EPITECH PROJECT, 2020
** STRINGS
** File description:
** Strings header
*/

#ifndef STRINGS_H_
#define STRINGS_H_

//////////////////////// VAR ////////////////////////

// help
static char const HELP[200] = "USAGE\n"
    "\t./asm file_name[.s]\n"
    "DESCRIPTION\n"
    "\tfile_name\tfile in assembly language to be "
    "converted into file_name.cor, an\n"
    "\t\t\texecutable in the Virtual Machine.\n";

// error
static char const INVALID_ARG_COUNT[100] = "invalid number of arguments";

// msg
static char const MSG_WARNING_1[100] = "\033[1;37masm, ";
static char const MSG_WARNING_2[100] = ", line ";
static char const MSG_WARNING_3[100] = ": \033[1;31mWarning: \033[1;36m";
static char const MSG_WARNING_4[100] = "\n\033[0m";

static char const MSG_ERROR_1[100] = "\033[1;37masm, ";
static char const MSG_ERROR_2[100] = ", line ";
static char const MSG_ERROR_3[100] = ": \033[1;36m";
static char const MSG_ERROR_4[100] = "\n\033[0m";

static char const EMPTY_FILE_1[100] = "\033[1;37masm, ";
static char const EMPTY_FILE_2[100] = ": \033[1;36mThe file is empty.\n\033[0m";

static char const INVALID_ARGS[100] = "The argument given to the instruction " \
    "is invalid.";
static char const TOO_MANY_ARGS[100] = "Too many arguments given to the " \
    "instruction.";
static char const MULTI_LABEL_DEF[100] = "Multiple definition of the " \
    "same label.";

#endif /* !STRINGS_H_ */