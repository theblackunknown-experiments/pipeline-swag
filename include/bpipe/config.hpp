#ifndef BPIPE_CONFIG_H
#define BPIPE_CONFIG_H

#define BPIPE_IMPLEMENTATION(ClassName) ClassName##Implementation

#ifdef BPIPE_EXPORT_DLL
#define PIPE_API_ENTRY __decl(dllexport)
#elif BPIPE_IMPORT_DLL
#define PIPE_API_ENTRY __decl(dllimport)
#endif

#ifndef PIPE_API_ENTRY
#define PIPE_API_ENTRY
#endif

#endif
