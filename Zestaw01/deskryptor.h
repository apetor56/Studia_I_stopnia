#ifndef DESKRYPTOR_H
#define DESKRYPTOR_H

int open_original(const char* name);

int open_copy(const char* name);

void arg_error(int count, const char* name);

#endif /* DESKRYPTOR_H */