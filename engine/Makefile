CC ?= gcc
BUILD_DIR ?= build
AR ?= ar
RM ?= rm -rf
EXEEXT ?=
CPPFLAGS ?= -Iinclude -Isrc/crypto
CFLAGS ?= -std=c23 -Wall -Wextra -Wpedantic -Werror
LDLIBS ?=

ifeq ($(OS),Windows_NT)
EXEEXT := .exe
LDLIBS += -lbcrypt
endif

CRYPTO_OBJECTS := \
	$(BUILD_DIR)/hash_adapter.o \
	$(BUILD_DIR)/salt_adapter.o \
	$(BUILD_DIR)/sha256.o

.PHONY: build test clean

build: $(BUILD_DIR)/test_hash_adapter$(EXEEXT) $(BUILD_DIR)/test_salt_adapter$(EXEEXT)

test: build
	$(BUILD_DIR)/test_hash_adapter$(EXEEXT)
	$(BUILD_DIR)/test_salt_adapter$(EXEEXT)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/libengine_crypto.a: $(CRYPTO_OBJECTS) | $(BUILD_DIR)
	$(AR) rcs $@ $^

$(BUILD_DIR)/hash_adapter.o: src/crypto/hash_adapter.c include/crypto/hash_adapter.h src/crypto/sha256.h | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/salt_adapter.o: src/crypto/salt_adapter.c include/crypto/salt_adapter.h | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/sha256.o: src/crypto/sha256.c src/crypto/sha256.h | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/test_hash_adapter$(EXEEXT): tests/unit/test_hash_adapter.c $(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< $(BUILD_DIR)/libengine_crypto.a $(LDLIBS) -o $@

$(BUILD_DIR)/test_salt_adapter$(EXEEXT): tests/unit/test_salt_adapter.c $(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< $(BUILD_DIR)/libengine_crypto.a $(LDLIBS) -o $@

clean:
	$(RM) $(BUILD_DIR)
