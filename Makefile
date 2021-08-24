# Vulcalien's Library Makefile
# version 0.1.6 (modified)
#
# This Makefile can create both
# Static and Shared libraries

# === TARGET OS ===
ifeq ($(OS),Windows_NT)
	TARGET_OS := WINDOWS
else
	TARGET_OS := UNIX
endif

# ========= EDIT HERE =========
OUT_FILENAME := lib6502-emulator

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

OBJ_STATIC_DIR := $(OBJ_DIR)/static
OBJ_SHARED_DIR := $(OBJ_DIR)/shared

CPPFLAGS := -Iinclude -Iinclude/lib -MMD -MP

CFLAGS_STATIC := -Wall -pedantic
CFLAGS_SHARED := -fPIC -fvisibility=hidden -Wall -pedantic

ifeq ($(TARGET_OS),UNIX)
	# UNIX
	LDFLAGS := -shared -Llib
	LDLIBS  :=
else ifeq ($(TARGET_OS),WINDOWS)
	# WINDOWS
	LDFLAGS := -shared -Llib
	LDLIBS  :=
endif
# =============================

# === OS SPECIFIC ===
ifeq ($(TARGET_OS),UNIX)
	# UNIX
	CC := gcc

	OBJ_EXT    := .o
	STATIC_EXT := .a
	SHARED_EXT := .so

	MKDIR      := mkdir
	MKDIRFLAGS := -p

	RM      := rm
	RMFLAGS := -rfv
else ifeq ($(TARGET_OS),WINDOWS)
	# WINDOWS
	CC := gcc

	OBJ_EXT    := .obj
	STATIC_EXT := -win.a
	SHARED_EXT := .dll

	MKDIR      := mkdir
	MKDIRFLAGS :=

	RM      := del
	RMFLAGS := /Q /S
endif

# === OTHER ===
SRC := $(wildcard $(SRC_DIR)/*.c)

OBJ_STATIC := $(SRC:$(SRC_DIR)/%.c=$(OBJ_STATIC_DIR)/%$(OBJ_EXT))
OBJ_SHARED := $(SRC:$(SRC_DIR)/%.c=$(OBJ_SHARED_DIR)/%$(OBJ_EXT))

OUT_STATIC := $(BIN_DIR)/$(OUT_FILENAME)$(STATIC_EXT)
OUT_SHARED := $(BIN_DIR)/$(OUT_FILENAME)$(SHARED_EXT)

# === TARGETS ===
.PHONY: all build-static build-shared clean

all: build-static build-shared

build-static: $(OUT_STATIC)

build-shared: $(OUT_SHARED)

clean:
	@$(RM) $(RMFLAGS) $(BIN_DIR) $(OBJ_DIR)

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

-include $(OBJ_STATIC:$(OBJ_EXT)=.d)
-include $(OBJ_SHARED:$(OBJ_EXT)=.d)
