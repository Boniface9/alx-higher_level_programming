#include <Python.h>

void print_python_list(PyObject *p) {
    if (!PyList_Check(p)) {
        fprintf(stderr, "[ERROR] Invalid List Object\n");
        return;
    }

    Py_ssize_t size = PyList_Size(p);
    Py_ssize_t allocated = ((PyListObject *)p)->allocated;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", allocated);

    for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject *element = PyList_GetItem(p, i);
        printf("Element %ld: ", i);

        if (PyBytes_Check(element)) {
            printf("bytes\n");
            // Additional code for bytes object information
            printf("[.] bytes object info\n");
            printf("  size: %ld\n", PyBytes_Size(element));
            printf("  trying string: %s\n", PyBytes_AsString(element));
            printf("  first 10 bytes: ");
            for (int j = 0; j < 10 && j < PyBytes_Size(element); ++j) {
                printf("%02x ", (unsigned char)PyBytes_AsString(element)[j]);
            }
            printf("\n");
        } else if (PyFloat_Check(element)) {
            printf("float\n");
            // Additional code for float object information
            printf("[.] float object info\n");
            printf("  value: %f\n", PyFloat_AsDouble(element));
        } else if (PyLong_Check(element)) {
            printf("int\n");
            // Additional code for integer object information
        } else if (PyList_Check(element)) {
            printf("list\n");
            // Additional code for nested list information
        } else {
            printf("%s\n", Py_TYPE(element)->tp_name);
        }
    }
}

void print_python_bytes(PyObject *p) {
    if (!PyBytes_Check(p)) {
        fprintf(stderr, "[ERROR] Invalid Bytes Object\n");
        return;
    }

    printf("[.] bytes object info\n");
    printf("  size: %ld\n", PyBytes_Size(p));
    printf("  trying string: %s\n", PyBytes_AsString(p));
    printf("  first 10 bytes: ");
    for (int i = 0; i < 10 && i < PyBytes_Size(p); ++i) {
        printf("%02x ", (unsigned char)PyBytes_AsString(p)[i]);
    }
    printf("\n");
}

void print_python_float(PyObject *p) {
    if (!PyFloat_Check(p)) {
        fprintf(stderr, "[ERROR] Invalid Float Object\n");
        return;
    }

    printf("[.] float object info\n");
    printf("  value: %f\n", PyFloat_AsDouble(p));
}
