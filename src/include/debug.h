#ifndef __DEBUG_H__
#define __DEBUG_H__

void panic(const char *);
void log(const char *file, const char *func, size_t line, const char *msg, ...);
void error(const char *file, const char *func, size_t line, const char *, uint32_t val);

#define LOG(msg, ...) log(__FILE__, __FUNC__, __LINE__, msg, __VA_LIST__)
#define ERR(msg, ...) log(__FILE__, __FUNC__, __LINE__, msg, __VA_LIST__)

#endif /* __DEBUG_H__ */
