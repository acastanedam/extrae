#!/bin/sh

export EXTRAE_HOME=@sub_PREFIXDIR@
export PAPI_HOME=@sub_PAPI_HOME@
export UNWIND_HOME=@sub_UNWIND_HOME@

EXTRAE_CONFIG_FILE=extrae.xml LD_LIBRARY_PATH=${EXTRAE_HOME}/lib:${PAPI_HOME}/lib:${UNWIND_HOME}/lib:${LD_LIBRARY_PATH} ./hello_instrumented
