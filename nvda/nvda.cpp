#include <string>

#include <nvdaController.h>
#include <Python.h>

#include "nvda.h"


std::wstring toWideChar(const char* c)
{
    const size_t cSize = strlen(c) + 1;
    std::wstring wc(cSize, L'#');
    mbstowcs(&wc[0], c, cSize);
    return wc;
}

static char SpeakText[] = "SpeakText";
static char SpeakText_doc[] = "SpeakText(text)";
static char CancelSpeech[] = "CancelSpeech";
static char CancelSpeech_doc[] = "CancelSpeech()";

static PyObject* nvda_SpeakText(PyObject* self, PyObject* args);
static PyObject* nvda_CancelSpeech(PyObject* self, PyObject* args);

static PyMethodDef methods[] = {
    { SpeakText, nvda_SpeakText, METH_VARARGS, SpeakText_doc },
    { CancelSpeech, nvda_CancelSpeech, METH_VARARGS, CancelSpeech_doc },
    { NULL, NULL, 0, NULL },
};

PyObject* nvda_SpeakText(PyObject* self, PyObject* args) {
    const char* text;
    char s[] = "s";
    char i[] = "i";

    if (!PyArg_ParseTuple(args, s, &text))
        return NULL;

    int error_code = nvdaController_speakText(toWideChar(text).c_str());

    return Py_BuildValue(i, error_code);
}

PyObject* nvda_CancelSpeech(PyObject* self, PyObject* args) {
    char empty_string[] = "";
    char i[] = "i";

    if (!PyArg_ParseTuple(args, empty_string))
        return NULL;

    int error_code = nvdaController_cancelSpeech();

    return Py_BuildValue(i, error_code);
}

void initnvda()
{
    char nvda[] = "nvda";
    Py_InitModule(nvda, methods);
}
