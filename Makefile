# Vulcalien's Library Makefile
# version 0.1.3 (modified)
#
# This Makefile can create both
# Static and Shared libraries

# ========= CONFIG =========
OUT_FILENAME := lib6502-emulator

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

OBJ_STATIC_DIR := $(OBJ_DIR)/static
OBJ_SHARED_DIR := $(OBJ_DIR)/shared

CPPFLAGS := -Iinclude -Iinclude/lib -MMD -MP

CFLAGS_STATIC := -Wall -pedantic
CFLAGS_SHARED := -fPIC -fvisibility=hidden -Wall -pedantic

# Unix LDFLAGS and LDLIBS
UNI_LDFLAGS := -shared -Llib
UNI_LDLIBS  :=

# Windows LDFLAGS and LDLIBS
WIN_LDFLAGS := -shared -Llib
WIN_LDLIBS  :=

# ========= OS SPECIFIC =========
UNI_OBJ_EXT    := .o
UNI_STATIC_EXT := .a
UNI_SHARED_EXT := .so

WIN_OBJ_EXT    := .obj
WIN_STATIC_EXT := -win.a
WIN_SHARED_EXT := .dll

ifeq ($(OS),Windows_NT)
	CC := gcc

	OBJ_EXT    := $(WIN_OBJ_EXT)
	STATIC_EXT := $(WIN_STATIC_EXT)
	SHARED_EXT := $(WIN_SHARED_EXT)

	LDFLAGS := $(WIN_LDFLAGS)
	LDLIBS  := $(WIN_LDLIBS)

	MKDIR      := mkdir
	MKDIRFLAGS :=

	RM      := del
	RMFLAGS := /Q /S
else
	CC := gcc

	OBJ_EXT    := $(UNI_OBJ_EXT)
	STATIC_EXT := $(UNI_STATIC_EXT)
	SHARED_EXT := $(UNI_SHARED_EXT)

	LDFLAGS := $(UNI_LDFLAGS)
	LDLIBS  := $(UNI_LDLIBS)

	MKDIR      := mkdir
	MKDIRFLAGS := -p

	RM      := rm
	RMFLAGS := -rfv
endif

# ========= OTHER =========
SRC := $(wildcard $(SRC_DIR)/*.c)

OBJ_STATIC := $(SRC:$(SRC_DIR)/%.c=$(OBJ_STATIC_DIR)/%$(OBJ_EXT))
OBJ_SHARED := $(SRC:$(SRC_DIR)/%.c=$(OBJ_SHARED_DIR)/%$(OBJ_EXT))

OUT_STATIC := $(BIN_DIR)/$(OUT_FILENAME)$(STATIC_EXT)
OUT_SHARED := $(BIN_DIR)/$(OUT_FILENAME)$(SHARED_EXT)

.PHONY: all build-static build-shared clean

all: build-static build-shared

build-static: $(OUT_STATIC)

build-shared: $(OUT_SHARED)

$(OUT_STATIC): $(OBJ_STATIC) | $(BIN_DIR)
	$(AR) rcs $@ $^

$(OUT_SHARED): $(OBJ_SHARED) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_STATIC_DIR)/%$(OBJ_EXT): $(SRC_DIR)/%.c | $(OBJ_STATIC_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS_STATIC) -c $< -o $@

$(OBJ_SHARED_DIR)/%$(OBJ_EXT): $(SRC_DIR)/%.c | $(OBJ_SHARED_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS_SHARED) -c $< -o $@

$(BIN_DIR) $(OBJ_STATIC_DIR) $(OBJ_SHARED_DIR):
	$(MKDIR) $(MKDIRFLAGS) "$@"

clean:
	@$(RM) $(RMFLAGS) $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ_STATIC:$(OBJ_EXT)=.d)
-include $(OBJ_SHARED:$(OBJ_EXT)=.d)
