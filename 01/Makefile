####################################################################
# PARAMETER
####################################################################

############################### Input ##############################
# Project dir
PRO_DIR = .

# LIB
LIB_DIR        = ${PRO_DIR}/lib
TEST_LIB_DIR   = ${LIB_DIR}/test

# app
APP_DIR        = ${PRO_DIR}/app

############################### Output #############################

# common build
OUTPUT_DIR     = ${PRO_DIR}/output
OBJ_DIR        = ${OUTPUT_DIR}/obj
OUTPUT_LIB_DIR = ${OUTPUT_DIR}/lib
OUTPUT_APP     = ${OUTPUT_DIR}/app

# static app
OUTPUT_STATIC_APP      = ${OUTPUT_APP}/static_app
OBJ_DIR_STATIC         = ${OBJ_DIR}/static
STATIC_LIB_OUTPUT_DIR  = ${OUTPUT_LIB_DIR}/static_lib

# shared app
OUTPUT_SHARED_APP      = ${OUTPUT_APP}/shared_app
OBJ_DIR_SHARED         = ${OBJ_DIR}/shared
SHARED_LIB_OUTPUT_DIR  = ${OUTPUT_LIB_DIR}/shared_lib

# Unit test lib
UTEST_LIB_DIR  = ${OUTPUT_DIR}/test

####################################################################
# Target and rule
####################################################################
.PHONY: all clean shared static run_shared_app run_static_app

all: static shared

# common build
create_obj_dir:
	@mkdir -p ${OBJ_DIR}

########################### build static app ########################
create_output_static_lib:
	@mkdir -p ${STATIC_LIB_OUTPUT_DIR}

create_static_app_dir:
	@mkdir -p ${OUTPUT_STATIC_APP}

create_static_obj_dir:
	@mkdir -p ${OBJ_DIR_STATIC}

compile_lib_static:
	@echo "Compiling static lib"
	@gcc -c ${LIB_DIR}/src/bstrutils.c -o ${OBJ_DIR_STATIC}/bstrutils.o

static: create_obj_dir create_output_static_lib create_static_app_dir create_static_obj_dir compile_lib_static compile_app
	@echo "Compiling static lib"
	@ar rcs ${STATIC_LIB_OUTPUT_DIR}/libstrutils.a ${OBJ_DIR_STATIC}/bstrutils.o
	@echo "Linking app with static lib"
	@gcc -o ${OUTPUT_STATIC_APP}/main_static ${OBJ_DIR}/app.o ${STATIC_LIB_OUTPUT_DIR}/libstrutils.a

run_shared_app: shared
	@echo "Run shared app"
	@${OUTPUT_SHARED_APP}/main_shared

####################################################################

########################### build shared app ########################
create_output_shared_lib:
	@mkdir -p ${SHARED_LIB_OUTPUT_DIR}

create_shared_app_dir:
	@mkdir -p ${OUTPUT_SHARED_APP}

create_shared_obj_dir:
	@mkdir -p ${OBJ_DIR_SHARED}

compile_lib_shared:
	@echo "Compiling shared lib"
	@gcc -c ${LIB_DIR}/src/bstrutils.c -fPIC -shared -o ${OBJ_DIR_SHARED}/libstrutils.o

shared: create_obj_dir create_output_shared_lib create_shared_app_dir create_shared_obj_dir compile_lib_shared compile_app
	@echo "Compiling shared lib"
	@gcc -shared -o ${SHARED_LIB_OUTPUT_DIR}/libstrutils.so ${OBJ_DIR_SHARED}/libstrutils.o
	@echo "Linking app with shared lib"
	@gcc -o ${OUTPUT_SHARED_APP}/main_shared ${OBJ_DIR}/app.o -L${SHARED_LIB_OUTPUT_DIR} -lstrutils -Wl,-rpath=${SHARED_LIB_OUTPUT_DIR}

run_static_app: static
	@echo "Run static app"
	@${OUTPUT_STATIC_APP}/main_static

####################################################################

########################## Unit Test Lib ###########################
create_utest_dir:
	@mkdir -p ${UTEST_LIB_DIR}

test_lib: create_utest_dir
	@echo "Compiling test"
	@gcc -c ${TEST_LIB_DIR}/main.c -o ${UTEST_LIB_DIR}/main.o -I${LIB_DIR}/src
	@echo "Compiling lib"
	@gcc -c ${LIB_DIR}/src/bstrutils.c -o ${UTEST_LIB_DIR}/bstrutils.o
	@echo "Linking app test"
	@gcc -o ${UTEST_LIB_DIR}/test_static_lib ${UTEST_LIB_DIR}/bstrutils.o ${UTEST_LIB_DIR}/main.o
	@echo "Run test"
	@${UTEST_LIB_DIR}/test_static_lib

####################################################################

############################ build app #############################
compile_app:
	@echo "Compiling app"
	@gcc -c ${APP_DIR}/main.c -o ${OBJ_DIR}/app.o -I${LIB_DIR}/src

####################################################################

############################ clean all #############################
clean:
	rm -rf ${OUTPUT_DIR}

####################################################################
