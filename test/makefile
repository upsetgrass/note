
# PROJECT=libprint_func.so

# CC?=gcc

# SOURCES=$(wildcard src/*.c)

# OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

# .PHONY:clean

# # CFLAG = -Iinclude -fPIC -shared
# # CFLAG = -Iinclude -I/home/happy_grass/work/qemu/include/qemu -fPIC -shared
# # --- I是指定额外头文件搜索路径，这里指定了当前项目下的include ~/work/qemu/include/qemu /usr/include/glib-2.0 /usr/lib/x86_64-linux-gnu/glib-2.0/include --- #
# # --- -fPIC使得生成的共享库.so能够被加载到内存的任意位置，不依赖固定的内存地址 -shared输出共享库，而不是编译成独立的程序 --- #
# QEMU_SRC = /home/happy_grass/work/qemu
# QEMU_BUILD = $(QEMU_SRC)/build
# PLUGIN_CFLAGS = -I$(QEMU_BUILD)/include -IQEMU_BUILD -I$(QEMU_SRC)/include  -fPIC -Wall -shared
# #PLUGIN_CFLAGS = -I$(QEMU_BUILD)/include -I$(QEMU_SRC)/include -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I$(QEMU_SRC)/include/qemu-common -I$(QEMU_SRC)/include/qemu-opts -fPIC -Wall -shared
# #LD_FLAGS += -lgobject-2.0 -lglib-2.0 -fPIC -s -Wl,-z,relro,-z,now,-z,noexecstack -fstack-protector-all

# LD_FLAG = -fPIC -s -Wl,-z,relro,-z,now,-z,noexecstack -fstack-protector-all

# $(PROJECT): $(OBJECTS)
# 	mkdir -p lib
# 	$(CC)  -shared -o lib/$@ $(patsubst %.o,obj/%.o,$(notdir $(OBJECTS))) $(LD_FLAG)
# 	@echo "finish $(PROJECT)"

# .c.o:
# 	@mkdir -p obj
# 	$(CC) -c $< $(PLUGIN_CFLAGS) -o obj/$(patsubst %.c,%.o,$(notdir $<))

# clean:
# 	-rm -rf obj lib
# 	@echo "clean up"

# # QEMU_SRC = /home/happy_grass/work/qemu
# # QEMU_BUILD = $(QEMU_SRC)/build
# # PLUGIN_CFLAGS = -I$(QEMU_BUILD)/include -I$(QEMU_SRC)/include -fPIC -Wall -shared

# # PROJECT = libprint_func.so
# # SRC = src/plugin_test.c
# # OUT = lib/$(PROJECT)

# # .PHONY: all clean

# # all:
# #	mkdir -p lib
# #	gcc $(PLUGIN_CFLAGS) $(SRC) -o $(OUT)

# #clean:
# #	rm -rf lib


# # 修改后的 Makefile
# PROJECT=libprint_func.so
# CC?=gcc
# SOURCES=$(wildcard src/*.c)
# # OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
# OBJECTS=$(patsubst src/%.c,obj/%.o,$(SOURCES))

# # QEMU 路径配置
# QEMU_SRC = /home/happy_grass/work/qemu
# QEMU_BUILD = $(QEMU_SRC)/build

# # 关键修改：添加 pkg-config 和 QEMU 内部头文件路径
# # GLIB_CFLAGS = $(shell pkg-config --cflags glib-2.0)
# # QEMU_CFLAGS = -I$(QEMU_BUILD)/include -I$(QEMU_SRC)/include -I$(QEMU_SRC)/include/qemu
# # PLUGIN_CFLAGS = $(GLIB_CFLAGS) $(QEMU_CFLAGS) -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -fPIC -Wall -shared

# # LD_FLAG = -fPIC -shared -Wl,-z,relro,-z,now,-z,noexecstack -fstack-protector-all
# GLIB_CFLAGS  = $(shell pkg-config --cflags glib-2.0)
# GLIB_LDFLAGS = $(shell pkg-config --libs glib-2.0)
# QEMU_CFLAGS  = -I$(QEMU_BUILD)/include -I$(QEMU_SRC)/include -I$(QEMU_SRC)/include/qemu -I$(QEMU_BUILD)

# CFLAGS = -Wall -fPIC -shared $(GLIB_CFLAGS) $(QEMU_CFLAGS)
# LDFLAGS = -fPIC -shared -Wl,-z,relro,-z,now,-z,noexecstack -fstack-protector-all $(GLIB_LDFLAGS)


# $(PROJECT): $(OBJECTS)
# 	mkdir -p lib
# 	$(CC) $(LD_FLAG) -o lib/$@ $(patsubst %.c,obj/%.o,$(notdir $(SOURCES)))
# 	@echo "finish $(PROJECT)"

# obj/%.o: src/%.c
# 	@mkdir -p obj
# 	$(CC) $(PLUGIN_CFLAGS) -c $< -o $@

# clean:
# 	rm -rf obj lib
# 	@echo "clean up"

PROJECT=libprint_func.so
CC ?= gcc
SOURCES := $(wildcard src/*.c)
OBJECTS := $(patsubst src/%.c,obj/%.o,$(SOURCES))

# QEMU 路径配置
QEMU_SRC   = /home/happy_grass/work/qemu
QEMU_BUILD = $(QEMU_SRC)/build

# 获取 GLib 和 QEMU 的 CFLAGS 和 LDFLAGS
GLIB_CFLAGS  := $(shell pkg-config --cflags glib-2.0)
GLIB_LDFLAGS := $(shell pkg-config --libs glib-2.0)
QEMU_CFLAGS  := -I$(QEMU_BUILD)/include -I$(QEMU_SRC)/include -I$(QEMU_SRC)/include/qemu -I$(QEMU_BUILD)

CFLAGS  := -Wall -fPIC -shared -Wno-macro-redefined $(GLIB_CFLAGS) $(QEMU_CFLAGS)
LDFLAGS := -fPIC -shared -Wl,-z,relro,-z,now,-z,noexecstack -fstack-protector-all $(GLIB_LDFLAGS)

# 构建目标
$(PROJECT): $(OBJECTS)
	mkdir -p lib
	$(CC) $(LDFLAGS) -o lib/$@ $(OBJECTS)
	@echo "finish $(PROJECT)"

# 编译规则
obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

# 清理
clean:
	rm -rf obj lib
	@echo "clean up"