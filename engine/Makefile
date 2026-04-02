CC ?= gcc
AR ?= ar
BUILD_DIR ?= build
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

CORE_OBJECTS := \
	$(BUILD_DIR)/change_password.o \
	$(BUILD_DIR)/login.o \
	$(BUILD_DIR)/logout.o \
	$(BUILD_DIR)/register.o \
	$(BUILD_DIR)/state.o \
	$(BUILD_DIR)/validation.o

UTIL_OBJECTS := \
	$(BUILD_DIR)/file_io.o \
	$(BUILD_DIR)/memory.o \
	$(BUILD_DIR)/parse.o \
	$(BUILD_DIR)/string_view.o

STORAGE_OBJECTS := \
	$(BUILD_DIR)/file_audit_log.o \
	$(BUILD_DIR)/file_session_store.o \
	$(BUILD_DIR)/file_user_store.o

CLI_OBJECTS := \
	$(BUILD_DIR)/command_runner.o \
	$(BUILD_DIR)/exit_codes.o \
	$(BUILD_DIR)/json_output.o \
	$(BUILD_DIR)/service_main.o

UNIT_TESTS := \
	$(BUILD_DIR)/test_hash_adapter$(EXEEXT) \
	$(BUILD_DIR)/test_salt_adapter$(EXEEXT) \
	$(BUILD_DIR)/test_validation$(EXEEXT) \
	$(BUILD_DIR)/test_register$(EXEEXT) \
	$(BUILD_DIR)/test_login$(EXEEXT) \
	$(BUILD_DIR)/test_change_password$(EXEEXT) \
	$(BUILD_DIR)/test_logout$(EXEEXT)

INTEGRATION_TESTS := \
	$(BUILD_DIR)/test_file_user_store$(EXEEXT) \
	$(BUILD_DIR)/test_file_session_store$(EXEEXT) \
	$(BUILD_DIR)/test_file_audit_log$(EXEEXT) \
	$(BUILD_DIR)/test_cli_register$(EXEEXT) \
	$(BUILD_DIR)/test_cli_login$(EXEEXT) \
	$(BUILD_DIR)/test_cli_change_password$(EXEEXT) \
	$(BUILD_DIR)/test_cli_show_audit$(EXEEXT) \
	$(BUILD_DIR)/test_cli_show_metrics$(EXEEXT) \
	$(BUILD_DIR)/test_cli_golden_json$(EXEEXT) \
	$(BUILD_DIR)/test_cli_corrupt_state$(EXEEXT)

ALL_BINARIES := \
	$(BUILD_DIR)/engine_cli$(EXEEXT) \
	$(UNIT_TESTS) \
	$(INTEGRATION_TESTS)

.PHONY: build test clean

build: $(ALL_BINARIES)

test: build
	$(BUILD_DIR)/test_hash_adapter$(EXEEXT)
	$(BUILD_DIR)/test_salt_adapter$(EXEEXT)
	$(BUILD_DIR)/test_validation$(EXEEXT)
	$(BUILD_DIR)/test_register$(EXEEXT)
	$(BUILD_DIR)/test_login$(EXEEXT)
	$(BUILD_DIR)/test_change_password$(EXEEXT)
	$(BUILD_DIR)/test_logout$(EXEEXT)
	$(BUILD_DIR)/test_file_user_store$(EXEEXT)
	$(BUILD_DIR)/test_file_session_store$(EXEEXT)
	$(BUILD_DIR)/test_file_audit_log$(EXEEXT)
	$(BUILD_DIR)/test_cli_register$(EXEEXT)
	$(BUILD_DIR)/test_cli_login$(EXEEXT)
	$(BUILD_DIR)/test_cli_change_password$(EXEEXT)
	$(BUILD_DIR)/test_cli_show_audit$(EXEEXT)
	$(BUILD_DIR)/test_cli_show_metrics$(EXEEXT)
	$(BUILD_DIR)/test_cli_golden_json$(EXEEXT)
	$(BUILD_DIR)/test_cli_corrupt_state$(EXEEXT)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/libengine_crypto.a: $(CRYPTO_OBJECTS) | $(BUILD_DIR)
	$(AR) rcs $@ $^

$(BUILD_DIR)/libengine_auth_core.a: $(CORE_OBJECTS) | $(BUILD_DIR)
	$(AR) rcs $@ $^

$(BUILD_DIR)/libengine_util.a: $(UTIL_OBJECTS) | $(BUILD_DIR)
	$(AR) rcs $@ $^

$(BUILD_DIR)/libengine_storage.a: $(STORAGE_OBJECTS) | $(BUILD_DIR)
	$(AR) rcs $@ $^

$(BUILD_DIR)/libengine_cli.a: $(CLI_OBJECTS) | $(BUILD_DIR)
	$(AR) rcs $@ $^

$(BUILD_DIR)/%.o: src/crypto/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: src/core/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: src/util/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: src/storage/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: src/cli/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/service_main.o: src/app/service_main.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/engine_cli$(EXEEXT): src/app/cli_main.c \
	$(BUILD_DIR)/libengine_cli.a \
	$(BUILD_DIR)/libengine_storage.a \
	$(BUILD_DIR)/libengine_util.a \
	$(BUILD_DIR)/libengine_auth_core.a \
	$(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< \
		$(BUILD_DIR)/libengine_cli.a \
		$(BUILD_DIR)/libengine_storage.a \
		$(BUILD_DIR)/libengine_util.a \
		$(BUILD_DIR)/libengine_auth_core.a \
		$(BUILD_DIR)/libengine_crypto.a \
		$(LDLIBS) -o $@

$(BUILD_DIR)/test_hash_adapter$(EXEEXT): tests/unit/test_hash_adapter.c $(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< $(BUILD_DIR)/libengine_crypto.a $(LDLIBS) -o $@

$(BUILD_DIR)/test_salt_adapter$(EXEEXT): tests/unit/test_salt_adapter.c $(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< $(BUILD_DIR)/libengine_crypto.a $(LDLIBS) -o $@

$(BUILD_DIR)/test_validation$(EXEEXT): tests/unit/test_validation.c $(BUILD_DIR)/libengine_auth_core.a $(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< $(BUILD_DIR)/libengine_auth_core.a $(BUILD_DIR)/libengine_crypto.a $(LDLIBS) -o $@

$(BUILD_DIR)/test_register$(EXEEXT): tests/unit/test_register.c $(BUILD_DIR)/libengine_auth_core.a $(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< $(BUILD_DIR)/libengine_auth_core.a $(BUILD_DIR)/libengine_crypto.a $(LDLIBS) -o $@

$(BUILD_DIR)/test_login$(EXEEXT): tests/unit/test_login.c $(BUILD_DIR)/libengine_auth_core.a $(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< $(BUILD_DIR)/libengine_auth_core.a $(BUILD_DIR)/libengine_crypto.a $(LDLIBS) -o $@

$(BUILD_DIR)/test_change_password$(EXEEXT): tests/unit/test_change_password.c $(BUILD_DIR)/libengine_auth_core.a $(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< $(BUILD_DIR)/libengine_auth_core.a $(BUILD_DIR)/libengine_crypto.a $(LDLIBS) -o $@

$(BUILD_DIR)/test_logout$(EXEEXT): tests/unit/test_logout.c $(BUILD_DIR)/libengine_auth_core.a $(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< $(BUILD_DIR)/libengine_auth_core.a $(BUILD_DIR)/libengine_crypto.a $(LDLIBS) -o $@

$(BUILD_DIR)/test_file_user_store$(EXEEXT): tests/integration/test_file_user_store.c \
	$(BUILD_DIR)/libengine_storage.a \
	$(BUILD_DIR)/libengine_util.a \
	$(BUILD_DIR)/libengine_auth_core.a \
	$(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< \
		$(BUILD_DIR)/libengine_storage.a \
		$(BUILD_DIR)/libengine_util.a \
		$(BUILD_DIR)/libengine_auth_core.a \
		$(BUILD_DIR)/libengine_crypto.a \
		$(LDLIBS) -o $@

$(BUILD_DIR)/test_file_session_store$(EXEEXT): tests/integration/test_file_session_store.c \
	$(BUILD_DIR)/libengine_storage.a \
	$(BUILD_DIR)/libengine_util.a \
	$(BUILD_DIR)/libengine_auth_core.a \
	$(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< \
		$(BUILD_DIR)/libengine_storage.a \
		$(BUILD_DIR)/libengine_util.a \
		$(BUILD_DIR)/libengine_auth_core.a \
		$(BUILD_DIR)/libengine_crypto.a \
		$(LDLIBS) -o $@

$(BUILD_DIR)/test_file_audit_log$(EXEEXT): tests/integration/test_file_audit_log.c \
	$(BUILD_DIR)/libengine_storage.a \
	$(BUILD_DIR)/libengine_util.a \
	$(BUILD_DIR)/libengine_auth_core.a \
	$(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< \
		$(BUILD_DIR)/libengine_storage.a \
		$(BUILD_DIR)/libengine_util.a \
		$(BUILD_DIR)/libengine_auth_core.a \
		$(BUILD_DIR)/libengine_crypto.a \
		$(LDLIBS) -o $@

$(BUILD_DIR)/test_cli_register$(EXEEXT): tests/integration/test_cli_register.c \
	$(BUILD_DIR)/libengine_cli.a \
	$(BUILD_DIR)/libengine_storage.a \
	$(BUILD_DIR)/libengine_util.a \
	$(BUILD_DIR)/libengine_auth_core.a \
	$(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< \
		$(BUILD_DIR)/libengine_cli.a \
		$(BUILD_DIR)/libengine_storage.a \
		$(BUILD_DIR)/libengine_util.a \
		$(BUILD_DIR)/libengine_auth_core.a \
		$(BUILD_DIR)/libengine_crypto.a \
		$(LDLIBS) -o $@

$(BUILD_DIR)/test_cli_login$(EXEEXT): tests/integration/test_cli_login.c \
	$(BUILD_DIR)/libengine_cli.a \
	$(BUILD_DIR)/libengine_storage.a \
	$(BUILD_DIR)/libengine_util.a \
	$(BUILD_DIR)/libengine_auth_core.a \
	$(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< \
		$(BUILD_DIR)/libengine_cli.a \
		$(BUILD_DIR)/libengine_storage.a \
		$(BUILD_DIR)/libengine_util.a \
		$(BUILD_DIR)/libengine_auth_core.a \
		$(BUILD_DIR)/libengine_crypto.a \
		$(LDLIBS) -o $@

$(BUILD_DIR)/test_cli_change_password$(EXEEXT): tests/integration/test_cli_change_password.c \
	$(BUILD_DIR)/libengine_cli.a \
	$(BUILD_DIR)/libengine_storage.a \
	$(BUILD_DIR)/libengine_util.a \
	$(BUILD_DIR)/libengine_auth_core.a \
	$(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< \
		$(BUILD_DIR)/libengine_cli.a \
		$(BUILD_DIR)/libengine_storage.a \
		$(BUILD_DIR)/libengine_util.a \
		$(BUILD_DIR)/libengine_auth_core.a \
		$(BUILD_DIR)/libengine_crypto.a \
		$(LDLIBS) -o $@

$(BUILD_DIR)/test_cli_show_audit$(EXEEXT): tests/integration/test_cli_show_audit.c \
	$(BUILD_DIR)/libengine_cli.a \
	$(BUILD_DIR)/libengine_storage.a \
	$(BUILD_DIR)/libengine_util.a \
	$(BUILD_DIR)/libengine_auth_core.a \
	$(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< \
		$(BUILD_DIR)/libengine_cli.a \
		$(BUILD_DIR)/libengine_storage.a \
		$(BUILD_DIR)/libengine_util.a \
		$(BUILD_DIR)/libengine_auth_core.a \
		$(BUILD_DIR)/libengine_crypto.a \
		$(LDLIBS) -o $@

$(BUILD_DIR)/test_cli_show_metrics$(EXEEXT): tests/integration/test_cli_show_metrics.c \
	$(BUILD_DIR)/libengine_cli.a \
	$(BUILD_DIR)/libengine_storage.a \
	$(BUILD_DIR)/libengine_util.a \
	$(BUILD_DIR)/libengine_auth_core.a \
	$(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< \
		$(BUILD_DIR)/libengine_cli.a \
		$(BUILD_DIR)/libengine_storage.a \
		$(BUILD_DIR)/libengine_util.a \
		$(BUILD_DIR)/libengine_auth_core.a \
		$(BUILD_DIR)/libengine_crypto.a \
		$(LDLIBS) -o $@

$(BUILD_DIR)/test_cli_golden_json$(EXEEXT): tests/integration/test_cli_golden_json.c \
	$(BUILD_DIR)/libengine_cli.a \
	$(BUILD_DIR)/libengine_storage.a \
	$(BUILD_DIR)/libengine_util.a \
	$(BUILD_DIR)/libengine_auth_core.a \
	$(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< \
		$(BUILD_DIR)/libengine_cli.a \
		$(BUILD_DIR)/libengine_storage.a \
		$(BUILD_DIR)/libengine_util.a \
		$(BUILD_DIR)/libengine_auth_core.a \
		$(BUILD_DIR)/libengine_crypto.a \
		$(LDLIBS) -o $@

$(BUILD_DIR)/test_cli_corrupt_state$(EXEEXT): tests/integration/test_cli_corrupt_state.c \
	$(BUILD_DIR)/libengine_cli.a \
	$(BUILD_DIR)/libengine_storage.a \
	$(BUILD_DIR)/libengine_util.a \
	$(BUILD_DIR)/libengine_auth_core.a \
	$(BUILD_DIR)/libengine_crypto.a | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< \
		$(BUILD_DIR)/libengine_cli.a \
		$(BUILD_DIR)/libengine_storage.a \
		$(BUILD_DIR)/libengine_util.a \
		$(BUILD_DIR)/libengine_auth_core.a \
		$(BUILD_DIR)/libengine_crypto.a \
		$(LDLIBS) -o $@

clean:
	$(RM) $(BUILD_DIR)
