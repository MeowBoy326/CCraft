#include <stdio.h>

#include "logging.h"

/* Standard information logging */
void CCraft_info(const char *description) {
	fprintf(stdout, "CCraft | INFO      | %s\n", description);
}

/* Debug information */
void CCraft_debug(const char *description) {
	fprintf(stderr, "CCraft | DEBUG     | %s\n", description);
}

/* Potential issues, can continue running */
void CCraft_warn(const char *description) {
	fprintf(stdout, "CCraft | WARN      | %s\n", description);
}

/* Internal error, usually exits immediately after */
void CCraft_error(const char *description) {
	fprintf(stderr, "CCraft | ERR       | %s\n", description);
}

/* GLFW error, usually exits immediately after */
void GLFW_error_callback(int error, const char *description) {
	fprintf(stderr, "GLFW   | error %03d | %s\n", error, description);
}

/* GLAD error, usually exits immediately after */
void GLAD_error(const char *description) {
	fprintf(stderr, "GLAD error:        | %s\n", description);
}
