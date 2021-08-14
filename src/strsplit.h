#ifndef STRSPLIT_H
#define STRSPLIT_H

// Dynamic string splitting
// static char** _strsplit( const char* s, const char* delim, size_t* nb ); <-- Static
char** strsplit( const char* s, const char* delim );
char** strsplit_count( const char* s, const char* delim, size_t* nb );

#endif /* STRSPLIT_H */
