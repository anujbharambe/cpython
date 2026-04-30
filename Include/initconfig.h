#ifndef Py_INITCONFIG_H
#define Py_INITCONFIG_H
#ifdef __cplusplus
extern "C" {
#endif


// --- PyInitConfig (PEP 741) -----------------------------------------------

#if !defined(Py_LIMITED_API) || Py_LIMITED_API+0 >= 0x030f0000

typedef struct PyInitConfig PyInitConfig;

PyAPI_FUNC(PyInitConfig*) PyInitConfig_Create(void);
PyAPI_FUNC(void) PyInitConfig_Free(PyInitConfig *config);

PyAPI_FUNC(int) PyInitConfig_GetError(PyInitConfig* config,
    const char **err_msg);
PyAPI_FUNC(int) PyInitConfig_GetExitCode(PyInitConfig* config,
    int *exitcode);

PyAPI_FUNC(int) PyInitConfig_HasOption(PyInitConfig *config,
    const char *name);
PyAPI_FUNC(int) PyInitConfig_GetInt(PyInitConfig *config,
    const char *name,
    int64_t *value);
PyAPI_FUNC(int) PyInitConfig_GetStr(PyInitConfig *config,
    const char *name,
    char **value);
PyAPI_FUNC(int) PyInitConfig_GetStrList(PyInitConfig *config,
    const char *name,
    size_t *length,
    char ***items);
PyAPI_FUNC(void) PyInitConfig_FreeStrList(size_t length, char **items);

PyAPI_FUNC(int) PyInitConfig_SetInt(PyInitConfig *config,
    const char *name,
    int64_t value);
PyAPI_FUNC(int) PyInitConfig_SetStr(PyInitConfig *config,
    const char *name,
    const char *value);
PyAPI_FUNC(int) PyInitConfig_SetStrList(PyInitConfig *config,
    const char *name,
    size_t length,
    char * const *items);

PyAPI_FUNC(int) PyInitConfig_AddModule(PyInitConfig *config,
    const char *name,
    PyObject* (*initfunc)(void));

PyAPI_FUNC(int) Py_InitializeFromInitConfig(PyInitConfig *config);

#endif

#ifndef Py_LIMITED_API
#  define Py_CPYTHON_INITCONFIG_H
#  include "cpython/initconfig.h"
#  undef Py_CPYTHON_INITCONFIG_H
#endif

#ifdef __cplusplus
}
#endif
#endif /* !Py_INITCONFIG_H */
