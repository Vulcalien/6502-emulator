# Vulcalien's Library Makefile
# version 0.3.2

# === Detect OS ===
ifeq ($(OS),Windows_NT)
    CURRENT_OS := WINDOWS
else
    CURRENT_OS := UNIX
endif
TARGET_OS := $(CURRENT_OS)

# === Basic Info ===
OUT_FILENAME := lib6502-emulator

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

SRC_SUBDIRS :=

# === Compilation ===
CPPFLAGS := -Iinclude -Iinclude/lib -MMD -MP

CFLAGS_STATIC := -Wall -pedantic
CFLAGS_SHARED := -Wall -pedantic -fPIC -fvisibility=hidden

ifeq ($(TARGET_OS),UNIX)
    # UNIX
    CC := gcc

    CPPFLAGS +=

    CFLAGS_STATIC +=
    CFLAGS_SHARED +=

    LDFLAGS := -shared
    LDLIBS  :=
else ifeq ($(TARGET_OS),WINDOWS)
    ifeq ($(CURRENT_OS),WINDOWS)
        # WINDOWS
        CC := gcc

        CPPFLAGS +=

        CFLAGS_STATIC +=
        CFLAGS_SHARED +=

        LDFLAGS := -shared
        LDLIBS  :=
    else ifeq ($(CURRENT_OS),UNIX)
        # UNIX to WINDOWS cross-compile
        CC := x86_64-w64-mingw32-gcc

        CPPFLAGS +=

        CFLAGS_STATIC +=
        CFLAGS_SHARED +=

        LDFLAGS := -shared
        LDLIBS  :=
    endif
endif

# === Extensions & Commands ===
ifeq ($(TARGET_OS),UNIX)
    OBJ_EXT    := o
    STATIC_EXT := a
    SHARED_EXT := so
else ifeq ($(TARGET_OS),WINDOWS)
    OBJ_EXT    := obj
    STATIC_EXT := win.a
    SHARED_EXT := dll
endif

ifeq ($(CURRENT_OS),UNIX)
    MKDIR      := mkdir
    MKDIRFLAGS := -p

    RM      := rm
    RMFLAGS := -rfv
else ifeq ($(CURRENT_OS),WINDOWS)
    MKDIR      := mkdir
    MKDIRFLAGS :=

    RM      := rmdir
    RMFLAGS := /Q /S
endif

# === Resources ===

# list of source file extensions
SRC_EXT := c

# list of source directories
SRC_DIRS := $(SRC_DIR)\
            $(foreach SUBDIR,$(SRC_SUBDIRS),$(SRC_DIR)/$(SUBDIR))

# list of source files
SRC := $(foreach DIR,$(SRC_DIRS),\
         $(foreach EXT,$(SRC_EXT),\
           $(wildcard $(DIR)/*.$(EXT))))

OBJ_STATIC_DIR := $(OBJ_DIR)/static
OBJ_SHARED_DIR := $(OBJ_DIR)/shared

# lists of object directories
OBJ_STATIC_DIRS := $(SRC_DIRS:%=$(OBJ_STATIC_DIR)/%)
OBJ_SHARED_DIRS := $(SRC_DIRS:%=$(OBJ_SHARED_DIR)/%)

# lists of object files
OBJ_STATIC := $(SRC:%=$(OBJ_STATIC_DIR)/%.$(OBJ_EXT))
OBJ_SHARED := $(SRC:%=$(OBJ_SHARED_DIR)/%.$(OBJ_EXT))

# output files
OUT_STATIC := $(BIN_DIR)/$(OUT_FILENAME).$(STATIC_EXT)
OUT_SHARED := $(BIN_DIR)/$(OUT_FILENAME).$(SHARED_EXT)

# === Targets ===

.PHONY: all build-static build-shared clean

all: build-static build-shared

build-static: $(OUT_STATIC)
build-shared: $(OUT_SHARED)

clean:
	@$(RM) $(RMFLAGS) $(BIN_DIR) $(OBJ_DIR)

# generate static library file
$(OUT_STATIC): $(OBJ_STATIC) | $(BIN_DIR)
	$(AR) rcs $@ $^

# generate shared library file
$(OUT_SHARED): $(OBJ_SHARED) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

# compile .c files for static library
$(OBJ_STATIC_DIR)/%.c.$(OBJ_EXT): %.c | $(OBJ_STATIC_DIRS)
	$(CC) $(CPPFLAGS) $(CFLAGS_STATIC) -c $< -o $@

# compile .c files for shared library
$(OBJ_SHARED_DIR)/%.c.$(OBJ_EXT): %.c | $(OBJ_SHARED_DIRS)
	$(CC) $(CPPFLAGS) $(CFLAGS_SHARED) -c $< -o $@

# create directories
$(BIN_DIR) $(OBJ_STATIC_DIRS) $(OBJ_SHARED_DIRS):
	$(MKDIR) $(MKDIRFLAGS) "$@"

-include $(OBJ_STATIC:.$(OBJ_EXT)=.d)
-include $(OBJ_SHARED:.$(OBJ_EXT)=.d)
