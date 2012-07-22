#ifndef BPIPE_CONFIG_H
#define BPIPE_CONFIG_H

#define BPIPE_IMPLEMENTATION(ClassName) ClassName##Implementation

#ifdef BPIPE_EXPORT_DLL
#define BPIPE_API_ENTRY __decl(dllexport)
#elif BPIPE_IMPORT_DLL
#define BPIPE_API_ENTRY __decl(dllimport)
#endif
#else
#define BPIPE_API_ENTRY
#endif
