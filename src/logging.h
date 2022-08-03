#pragma once
#ifndef LOGGING_H
#define LOGGING_H

void CCraft_info(const char *);
void CCraft_debug(const char *);
void CCraft_warn(const char *);
void CCraft_error(const char *);
void GLFW_error_callback(int, const char *);
void GLAD_error(const char *);

#endif /* LOGGING_H */
