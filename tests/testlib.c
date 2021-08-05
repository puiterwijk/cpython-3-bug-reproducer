#include <Python.h>

static PyObject *
say_hello(PyObject *self, PyObject *args)
{
    const char *hello_msg = NULL;

    if (!PyArg_ParseTuple(args, "s:say_hello", &hello_msg))
        return NULL;

    printf("Said hello: %s\n", hello_msg);

    Py_INCREF(Py_None);
    return Py_None;
}


static PyMethodDef TestMethods[] = {
    {"say_hello", say_hello, METH_VARARGS, "Return the passed in string"},
};

static struct PyModuleDef testlib_module = {
    PyModuleDef_HEAD_INIT,
    "testlib",
    NULL,
    -1,
    TestMethods,
};

PyMODINIT_FUNC
PyInit_testlib(void)
{
    return PyModule_Create(&testlib_module);
}
