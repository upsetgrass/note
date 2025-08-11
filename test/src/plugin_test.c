#include <glib.h>
#include <qemu/osdep.h>  // 必须放在第一个QEMU头文件之前
#include <qemu-plugin.h>
// #define GLIB_VERSION_MIN_REQUIRED GLIB_VERSION_2_66
// #define GLIB_VERSION_MAX_ALLOWED GLIB_VERSION_2_66

// 插件需要导出一个变量 qemu_plugin_version
QEMU_PLUGIN_EXPORT int qemu_plugin_version = 2;

// 插件加载时 QEMU 会调用这个函数
QEMU_PLUGIN_EXPORT int qemu_plugin_install(qemu_plugin_id_t id, const qemu_info_t *info, int argc, char **argv) {
    printf("[plugin] libprint_func loaded into QEMU!\n");
    return 0;
}

// // 定义指令计数器
// static int icount = 0;

// // 插件加载时 QEMU 会调用这个函数
// QEMU_PLUGIN_EXPORT int qemu_plugin_install(qemu_plugin_id_t id, const qemu_info_t *info, int argc, char **argv) {
//     printf("[plugin] Instruction Count plugin loaded into QEMU!\n");

//     // 注册钩子函数
//     // 假设 QEMU 提供了一个类似的 API 用于注册指令计数更新钩子
//     // qemu_plugin_add_hook(QEMU_PLUGIN_HOOK_ICOUNT, icount_update);  // 根据实际情况修改

//     return 0;
// }

// // 插件卸载时的清理工作
// QEMU_PLUGIN_EXPORT void qemu_plugin_uninstall(qemu_plugin_id_t id, qemu_plugin_simple_cb_t cb) {
//     printf("[plugin] Instruction Count: Total instructions executed: %d\n", icount);
// }

// // 每执行一条指令时调用的函数
// void icount_update(void) {
//     icount++;
//     if (icount % 1000 == 0) {
//         // 每执行1000条指令，打印一次当前指令计数
//         printf("[plugin] Instruction count: %d\n", icount);
//     }
// }

// // 插件的初始化和设置函数
// void register_icount_hook(void) {
//     // 假设QEMU提供了注册插件钩子的方法
//     // qemu_plugin_add_hook(QEMU_PLUGIN_HOOK_ICOUNT, icount_update);  // 根据实际情况修改
// }