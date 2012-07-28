#ifndef BPIPE_CONFIG_H
#define BPIPE_CONFIG_H

#define BPIPE_IMPLEMENTATION(ClassName) ClassName##Implementation

#ifdef _WIN32
#ifdef     BPIPE_EXPORT_DLL
#define        BPIPE_API_ENTRY __decl(dllexport)
#elif 	   BPIPE_IMPORT_DLL
#define        BPIPE_API_ENTRY __decl(dllimport)
#endif //BPIPE_XXX_DLL
#endif //_WIN32

#ifndef BPIPE_API_ENTRY
#define     BPIPE_API_ENTRY
#endif //BPIPE_API_ENTRY

#endif //BPIPE_CONFIG_H
