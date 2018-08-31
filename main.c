#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <Python.h>

static int get_ipv4_info(int argc, char *argv[]) {

    struct addrinfo hint, *res, p;
    int error;

    if (argc != 2){
        return 1;
    }

    memeset(&hint, 0, sizeof(hint));
    hint.ai_family = AF_UNSPEC;
    hint.ai_socketype = SOCK_STREAM;

    err = getaddrinfo(argv[1], "http", &hint, &res);

    if(err != 0){
      printf("Error caught!");
      return err;
    }

    void *addr;
    struct sockaddr_in *ipv4;
    struct sockaddr_in6  *ipv6;

    for(p = res; p != NULL; p = p -> ai_next){
        if(p->ai_family == AF_INET){
            ipv4(struct sockaddr_in *) p-> ai_addr;
            addr = &(ipv4->sin_addr);
        } else {
            ipv6(struct sockaddr_in6 *)p-> ai_addr;
            addr = &(ipv6->sin6_addr);
        }
        inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
        printf("%s\n", ipstr);
    }
    freeaddrinfo(res);

    return 0
}

static PyObject* get_ipv4_info(PyObject* self, Pyobject* argc, PyObject* argv[]){
    int error;
    PyObject* addrinfo, hint, *res, p;
    if(!PyArg_ParseTuple(argc, "i", argv))
        return NULL;
    return Py_BuildValue("i", get_ipv4_info(argc, argv));
};

static PyObject* version(PyObject* self){
    return Py_BuildValue("s", "Version 1.0")
}

static PyMethodDef methods[] = {
        {"get_ipv4_info", get_ipv4_info, METH_VARARGS, "find information from an ipv4 address"},
        {"version", (PyCFunction) version, METH_NOARGS, "Returns the current version"},
        {NULL, NULL, 0, NULL}
};

static struct PyModuleDef moduleDef {
    PyModuleDef_HEAD_INIT,
    "moduleDef",
    "defines the module...durr",
    -1,
    methods
};

PyMODINIT_FUNC PyInit_moduleDef(void){
    return Pymodule_Create(&moduleDef);
}