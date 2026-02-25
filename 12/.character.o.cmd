savedcmd_/home/ntai/embedded_linux_pratice/12/character.o := arm-poky-linux-gnueabi-gcc -Wp,-MMD,/home/ntai/embedded_linux_pratice/12/.character.o.d -nostdinc -I/home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include -I./arch/arm/include/generated -I/home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include -I./include -I/home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/uapi -I./arch/arm/include/generated/uapi -I/home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi -I./include/generated/uapi -include /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/compiler-version.h -include /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/kconfig.h -include /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/compiler_types.h -D__KERNEL__ -mlittle-endian -D__LINUX_ARM_ARCH__=7 -fmacro-prefix-map=/home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/= -std=gnu11 -fshort-wchar -funsigned-char -fno-common -fno-PIE -fno-strict-aliasing -fno-dwarf2-cfi-asm -mno-fdpic -fno-ipa-sra -mtp=cp15 -mabi=aapcs-linux -mfpu=vfp -funwind-tables -marm -Wa,-mno-warn-deprecated -march=armv7-a -msoft-float -Uarm -fno-delete-null-pointer-checks -O2 -fno-allow-store-data-races -fstack-protector-strong -ftrivial-auto-var-init=zero -fno-stack-clash-protection -pg -fno-inline-functions-called-once -fstrict-flex-arrays=3 -fno-strict-overflow -fno-stack-check -fconserve-stack -fno-builtin-wcslen -fno-builtin-wcslen -Wall -Wextra -Wundef -Werror=implicit-function-declaration -Werror=implicit-int -Werror=return-type -Werror=strict-prototypes -Wno-format-security -Wno-trigraphs -Wno-frame-address -Wno-address-of-packed-member -Wmissing-declarations -Wmissing-prototypes -Wframe-larger-than=1024 -Wno-main -Wno-dangling-pointer -Wvla -Wno-pointer-sign -Wcast-function-type -Wno-array-bounds -Wno-stringop-overflow -Wno-alloc-size-larger-than -Wimplicit-fallthrough=5 -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -Wenum-conversion -Wunused -Wno-unused-but-set-variable -Wno-unused-const-variable -Wno-packed-not-aligned -Wno-format-overflow -Wno-format-truncation -Wno-stringop-truncation -Wno-override-init -Wno-missing-field-initializers -Wno-type-limits -Wno-shift-negative-value -Wno-maybe-uninitialized -Wno-sign-compare -Wno-unused-parameter --sysroot=/opt/poky/5.0.14/sysroots/armv7at2hf-neon-poky-linux-gnueabi -mstack-protector-guard=tls -mstack-protector-guard-offset=1696  -DMODULE  -DKBUILD_BASENAME='"character"' -DKBUILD_MODNAME='"character"' -D__KBUILD_MODNAME=kmod_character -c -o /home/ntai/embedded_linux_pratice/12/character.o /home/ntai/embedded_linux_pratice/12/character.c  

source_/home/ntai/embedded_linux_pratice/12/character.o := /home/ntai/embedded_linux_pratice/12/character.c

deps_/home/ntai/embedded_linux_pratice/12/character.o := \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/compiler-version.h \
    $(wildcard include/config/CC_VERSION_TEXT) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/kconfig.h \
    $(wildcard include/config/CPU_BIG_ENDIAN) \
    $(wildcard include/config/BOOGER) \
    $(wildcard include/config/FOO) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/compiler_types.h \
    $(wildcard include/config/DEBUG_INFO_BTF) \
    $(wildcard include/config/PAHOLE_HAS_BTF_TAG) \
    $(wildcard include/config/FUNCTION_ALIGNMENT) \
    $(wildcard include/config/CC_HAS_SANE_FUNCTION_ALIGNMENT) \
    $(wildcard include/config/X86_64) \
    $(wildcard include/config/ARM64) \
    $(wildcard include/config/LD_DEAD_CODE_DATA_ELIMINATION) \
    $(wildcard include/config/LTO_CLANG) \
    $(wildcard include/config/HAVE_ARCH_COMPILER_H) \
    $(wildcard include/config/CC_HAS_COUNTED_BY) \
    $(wildcard include/config/UBSAN_SIGNED_WRAP) \
    $(wildcard include/config/CC_HAS_ASM_INLINE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/compiler_attributes.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/compiler-gcc.h \
    $(wildcard include/config/MITIGATION_RETPOLINE) \
    $(wildcard include/config/ARCH_USE_BUILTIN_BSWAP) \
    $(wildcard include/config/SHADOW_CALL_STACK) \
    $(wildcard include/config/KCOV) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/module.h \
    $(wildcard include/config/MODULES) \
    $(wildcard include/config/SYSFS) \
    $(wildcard include/config/MODULES_TREE_LOOKUP) \
    $(wildcard include/config/LIVEPATCH) \
    $(wildcard include/config/STACKTRACE_BUILD_ID) \
    $(wildcard include/config/ARCH_USES_CFI_TRAPS) \
    $(wildcard include/config/MODULE_SIG) \
    $(wildcard include/config/GENERIC_BUG) \
    $(wildcard include/config/KALLSYMS) \
    $(wildcard include/config/SMP) \
    $(wildcard include/config/TRACEPOINTS) \
    $(wildcard include/config/TREE_SRCU) \
    $(wildcard include/config/BPF_EVENTS) \
    $(wildcard include/config/DEBUG_INFO_BTF_MODULES) \
    $(wildcard include/config/JUMP_LABEL) \
    $(wildcard include/config/TRACING) \
    $(wildcard include/config/EVENT_TRACING) \
    $(wildcard include/config/FTRACE_MCOUNT_RECORD) \
    $(wildcard include/config/KPROBES) \
    $(wildcard include/config/HAVE_STATIC_CALL_INLINE) \
    $(wildcard include/config/KUNIT) \
    $(wildcard include/config/PRINTK_INDEX) \
    $(wildcard include/config/MODULE_UNLOAD) \
    $(wildcard include/config/MITIGATION_ITS) \
    $(wildcard include/config/CONSTRUCTORS) \
    $(wildcard include/config/FUNCTION_ERROR_INJECTION) \
    $(wildcard include/config/DYNAMIC_DEBUG_CORE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/list.h \
    $(wildcard include/config/LIST_HARDENED) \
    $(wildcard include/config/DEBUG_LIST) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/container_of.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/build_bug.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/compiler.h \
    $(wildcard include/config/TRACE_BRANCH_PROFILING) \
    $(wildcard include/config/PROFILE_ALL_BRANCHES) \
    $(wildcard include/config/OBJTOOL) \
    $(wildcard include/config/64BIT) \
  arch/arm/include/generated/asm/rwonce.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/rwonce.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/kasan-checks.h \
    $(wildcard include/config/KASAN_GENERIC) \
    $(wildcard include/config/KASAN_SW_TAGS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/types.h \
    $(wildcard include/config/HAVE_UID16) \
    $(wildcard include/config/UID16) \
    $(wildcard include/config/ARCH_DMA_ADDR_T_64BIT) \
    $(wildcard include/config/PHYS_ADDR_T_64BIT) \
    $(wildcard include/config/ARCH_32BIT_USTAT_F_TINODE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/uapi/asm/types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/int-ll64.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/asm-generic/int-ll64.h \
  arch/arm/include/generated/uapi/asm/bitsperlong.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/bitsperlong.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/asm-generic/bitsperlong.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/posix_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/stddef.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/stddef.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/uapi/asm/posix_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/asm-generic/posix_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/kcsan-checks.h \
    $(wildcard include/config/KCSAN) \
    $(wildcard include/config/KCSAN_WEAK_MEMORY) \
    $(wildcard include/config/KCSAN_IGNORE_ATOMICS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/poison.h \
    $(wildcard include/config/ILLEGAL_POINTER_VALUE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/const.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/vdso/const.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/const.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/barrier.h \
    $(wildcard include/config/CPU_32v6K) \
    $(wildcard include/config/THUMB2_KERNEL) \
    $(wildcard include/config/CPU_XSC3) \
    $(wildcard include/config/CPU_FA526) \
    $(wildcard include/config/ARM_HEAVY_MB) \
    $(wildcard include/config/ARM_DMA_MEM_BUFFERABLE) \
    $(wildcard include/config/CPU_SPECTRE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/barrier.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/stat.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/uapi/asm/stat.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/stat.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/time.h \
    $(wildcard include/config/POSIX_TIMERS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/cache.h \
    $(wildcard include/config/ARCH_HAS_CACHE_LINE_SIZE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/kernel.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/sysinfo.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/cache.h \
    $(wildcard include/config/ARM_L1_CACHE_SHIFT) \
    $(wildcard include/config/AEABI) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/math64.h \
    $(wildcard include/config/ARCH_SUPPORTS_INT128) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/math.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/div64.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/compiler.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/div64.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/log2.h \
    $(wildcard include/config/ARCH_HAS_ILOG2_U32) \
    $(wildcard include/config/ARCH_HAS_ILOG2_U64) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/bitops.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/bits.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/vdso/bits.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/bits.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/typecheck.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/bitops/generic-non-atomic.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/bitops.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/irqflags.h \
    $(wildcard include/config/PROVE_LOCKING) \
    $(wildcard include/config/TRACE_IRQFLAGS) \
    $(wildcard include/config/PREEMPT_RT) \
    $(wildcard include/config/IRQSOFF_TRACER) \
    $(wildcard include/config/PREEMPT_TRACER) \
    $(wildcard include/config/DEBUG_IRQFLAGS) \
    $(wildcard include/config/TRACE_IRQFLAGS_SUPPORT) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/irqflags_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/cleanup.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/irqflags.h \
    $(wildcard include/config/CPU_V7M) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/ptrace.h \
    $(wildcard include/config/ARM_THUMB) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/uapi/asm/ptrace.h \
    $(wildcard include/config/CPU_ENDIAN_BE8) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/hwcap.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/uapi/asm/hwcap.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/bitfield.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/uapi/asm/byteorder.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/byteorder/little_endian.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/byteorder/little_endian.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/swab.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/swab.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/swab.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/uapi/asm/swab.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/byteorder/generic.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/irqflags.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/percpu.h \
    $(wildcard include/config/CPU_V6) \
    $(wildcard include/config/ARM_HAS_GROUP_RELOCS) \
    $(wildcard include/config/ARM_MODULE_PLTS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/insn.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/percpu.h \
    $(wildcard include/config/DEBUG_PREEMPT) \
    $(wildcard include/config/HAVE_SETUP_PER_CPU_AREA) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/threads.h \
    $(wildcard include/config/NR_CPUS) \
    $(wildcard include/config/BASE_SMALL) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/percpu-defs.h \
    $(wildcard include/config/DEBUG_FORCE_WEAK_PER_CPU) \
    $(wildcard include/config/AMD_MEM_ENCRYPT) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/bitops/non-atomic.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/bitops/non-instrumented-non-atomic.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/bitops/builtin-__fls.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/bitops/builtin-__ffs.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/bitops/builtin-fls.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/bitops/builtin-ffs.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/bitops/ffz.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/bitops/fls64.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/bitops/sched.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/bitops/hweight.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/bitops/arch_hweight.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/bitops/const_hweight.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/bitops/lock.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/atomic.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/atomic.h \
    $(wildcard include/config/GENERIC_ATOMIC64) \
    $(wildcard include/config/ARM_LPAE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/prefetch.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/processor.h \
    $(wildcard include/config/HAVE_HW_BREAKPOINT) \
    $(wildcard include/config/BINFMT_ELF_FDPIC) \
    $(wildcard include/config/MMU) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/hw_breakpoint.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/unified.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/vdso/processor.h \
    $(wildcard include/config/ARM_ERRATA_754327) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/cmpxchg.h \
    $(wildcard include/config/CPU_SA1100) \
    $(wildcard include/config/CPU_SA110) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/cmpxchg-emu.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/cmpxchg-local.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/atomic/atomic-arch-fallback.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/atomic/atomic-long.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/atomic/atomic-instrumented.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/instrumented.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/kmsan-checks.h \
    $(wildcard include/config/KMSAN) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/bitops/instrumented-lock.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/bitops/le.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/bitops/ext2-atomic-setbit.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/vdso/math64.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/time64.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/vdso/time64.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/time.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/time_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/time32.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/timex.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/timex.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/param.h \
  arch/arm/include/generated/uapi/asm/param.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/param.h \
    $(wildcard include/config/HZ) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/asm-generic/param.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/timex.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/vdso/time32.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/vdso/time.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/uidgid.h \
    $(wildcard include/config/MULTIUSER) \
    $(wildcard include/config/USER_NS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/uidgid_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/highuid.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/buildid.h \
    $(wildcard include/config/VMCORE_INFO) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/kmod.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/umh.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/gfp.h \
    $(wildcard include/config/HIGHMEM) \
    $(wildcard include/config/ZONE_DMA) \
    $(wildcard include/config/ZONE_DMA32) \
    $(wildcard include/config/ZONE_DEVICE) \
    $(wildcard include/config/NUMA) \
    $(wildcard include/config/COMPACTION) \
    $(wildcard include/config/CONTIG_ALLOC) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/gfp_types.h \
    $(wildcard include/config/KASAN_HW_TAGS) \
    $(wildcard include/config/LOCKDEP) \
    $(wildcard include/config/SLAB_OBJ_EXT) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/mmzone.h \
    $(wildcard include/config/ARCH_FORCE_MAX_ORDER) \
    $(wildcard include/config/CMA) \
    $(wildcard include/config/MEMORY_ISOLATION) \
    $(wildcard include/config/ZSMALLOC) \
    $(wildcard include/config/UNACCEPTED_MEMORY) \
    $(wildcard include/config/IOMMU_SUPPORT) \
    $(wildcard include/config/SWAP) \
    $(wildcard include/config/NUMA_BALANCING) \
    $(wildcard include/config/TRANSPARENT_HUGEPAGE) \
    $(wildcard include/config/LRU_GEN) \
    $(wildcard include/config/LRU_GEN_STATS) \
    $(wildcard include/config/LRU_GEN_WALKS_MMU) \
    $(wildcard include/config/MEMCG) \
    $(wildcard include/config/SPARSEMEM) \
    $(wildcard include/config/MEMORY_HOTPLUG) \
    $(wildcard include/config/MEMORY_FAILURE) \
    $(wildcard include/config/FLATMEM) \
    $(wildcard include/config/PAGE_EXTENSION) \
    $(wildcard include/config/DEFERRED_STRUCT_PAGE_INIT) \
    $(wildcard include/config/HAVE_MEMORYLESS_NODES) \
    $(wildcard include/config/SPARSEMEM_VMEMMAP) \
    $(wildcard include/config/SPARSEMEM_EXTREME) \
    $(wildcard include/config/HAVE_ARCH_PFN_VALID) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/spinlock.h \
    $(wildcard include/config/DEBUG_SPINLOCK) \
    $(wildcard include/config/PREEMPTION) \
    $(wildcard include/config/DEBUG_LOCK_ALLOC) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/preempt.h \
    $(wildcard include/config/PREEMPT_COUNT) \
    $(wildcard include/config/TRACE_PREEMPT_TOGGLE) \
    $(wildcard include/config/PREEMPT_NOTIFIERS) \
    $(wildcard include/config/PREEMPT_DYNAMIC) \
    $(wildcard include/config/PREEMPT_NONE) \
    $(wildcard include/config/PREEMPT_VOLUNTARY) \
    $(wildcard include/config/PREEMPT) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/linkage.h \
    $(wildcard include/config/ARCH_USE_SYM_ANNOTATIONS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/stringify.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/export.h \
    $(wildcard include/config/MODVERSIONS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/linkage.h \
  arch/arm/include/generated/asm/preempt.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/preempt.h \
    $(wildcard include/config/HAVE_PREEMPT_DYNAMIC_KEY) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/thread_info.h \
    $(wildcard include/config/THREAD_INFO_IN_TASK) \
    $(wildcard include/config/GENERIC_ENTRY) \
    $(wildcard include/config/HAVE_ARCH_WITHIN_STACK_FRAMES) \
    $(wildcard include/config/HARDENED_USERCOPY) \
    $(wildcard include/config/BUG) \
    $(wildcard include/config/SH) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/limits.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/limits.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/vdso/limits.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/bug.h \
    $(wildcard include/config/BUG_ON_DATA_CORRUPTION) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/bug.h \
    $(wildcard include/config/DEBUG_BUGVERBOSE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/opcodes.h \
    $(wildcard include/config/CPU_ENDIAN_BE32) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/bug.h \
    $(wildcard include/config/GENERIC_BUG_RELATIVE_POINTERS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/instrumentation.h \
    $(wildcard include/config/NOINSTR_VALIDATION) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/once_lite.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/panic.h \
    $(wildcard include/config/PANIC_TIMEOUT) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/printk.h \
    $(wildcard include/config/MESSAGE_LOGLEVEL_DEFAULT) \
    $(wildcard include/config/CONSOLE_LOGLEVEL_DEFAULT) \
    $(wildcard include/config/CONSOLE_LOGLEVEL_QUIET) \
    $(wildcard include/config/EARLY_PRINTK) \
    $(wildcard include/config/PRINTK) \
    $(wildcard include/config/DYNAMIC_DEBUG) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/stdarg.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/init.h \
    $(wildcard include/config/HAVE_ARCH_PREL32_RELOCATIONS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/kern_levels.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/ratelimit_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/spinlock_types_raw.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/spinlock_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/lockdep_types.h \
    $(wildcard include/config/PROVE_RAW_LOCK_NESTING) \
    $(wildcard include/config/LOCK_STAT) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/dynamic_debug.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/jump_label.h \
    $(wildcard include/config/HAVE_ARCH_JUMP_LABEL_RELATIVE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/jump_label.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/restart_block.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/errno.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/errno.h \
  arch/arm/include/generated/uapi/asm/errno.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/asm-generic/errno.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/asm-generic/errno-base.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/current.h \
    $(wildcard include/config/CURRENT_POINTER_IN_TPIDRURO) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/thread_info.h \
    $(wildcard include/config/KASAN) \
    $(wildcard include/config/VMAP_STACK) \
    $(wildcard include/config/ARM_THUMBEE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/fpstate.h \
    $(wildcard include/config/VFPv3) \
    $(wildcard include/config/IWMMXT) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/page.h \
    $(wildcard include/config/PAGE_SHIFT) \
    $(wildcard include/config/CPU_COPY_V4WT) \
    $(wildcard include/config/CPU_COPY_V4WB) \
    $(wildcard include/config/CPU_COPY_FEROCEON) \
    $(wildcard include/config/CPU_COPY_FA) \
    $(wildcard include/config/CPU_XSCALE) \
    $(wildcard include/config/CPU_COPY_V6) \
    $(wildcard include/config/KUSER_HELPERS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/glue.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/pgtable-2level-types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/memory.h \
    $(wildcard include/config/NEED_MACH_MEMORY_H) \
    $(wildcard include/config/PAGE_OFFSET) \
    $(wildcard include/config/DRAM_BASE) \
    $(wildcard include/config/DRAM_SIZE) \
    $(wildcard include/config/XIP_KERNEL) \
    $(wildcard include/config/HAVE_TCM) \
    $(wildcard include/config/ARM_PATCH_PHYS_VIRT) \
    $(wildcard include/config/PHYS_OFFSET) \
    $(wildcard include/config/DEBUG_VIRTUAL) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sizes.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/kasan_def.h \
    $(wildcard include/config/KASAN_SHADOW_OFFSET) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/getorder.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/memory_model.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/pfn.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/traps.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/bottom_half.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/instruction_pointer.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/lockdep.h \
    $(wildcard include/config/DEBUG_LOCKING_API_SELFTESTS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/smp.h \
    $(wildcard include/config/UP_LATE_INIT) \
    $(wildcard include/config/CSD_LOCK_WAIT_DEBUG) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/cpumask.h \
    $(wildcard include/config/FORCE_NR_CPUS) \
    $(wildcard include/config/HOTPLUG_CPU) \
    $(wildcard include/config/DEBUG_PER_CPU_MAPS) \
    $(wildcard include/config/CPUMASK_OFFSTACK) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/kernel.h \
    $(wildcard include/config/PREEMPT_VOLUNTARY_BUILD) \
    $(wildcard include/config/HAVE_PREEMPT_DYNAMIC_CALL) \
    $(wildcard include/config/PREEMPT_) \
    $(wildcard include/config/DEBUG_ATOMIC_SLEEP) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/align.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/array_size.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/hex.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/kstrtox.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/minmax.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sprintf.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/static_call_types.h \
    $(wildcard include/config/HAVE_STATIC_CALL) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/wordpart.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/bitmap.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/find.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/string.h \
    $(wildcard include/config/BINARY_PRINTF) \
    $(wildcard include/config/FORTIFY_SOURCE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/args.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/err.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/overflow.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/string.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/string.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/fortify-string.h \
    $(wildcard include/config/CC_HAS_KASAN_MEMINTRINSIC_PREFIX) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/bitmap-str.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/cpumask_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/numa.h \
    $(wildcard include/config/NODES_SHIFT) \
    $(wildcard include/config/NUMA_KEEP_MEMINFO) \
    $(wildcard include/config/HAVE_ARCH_NODE_DEV_GROUP) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/smp_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/llist.h \
    $(wildcard include/config/ARCH_HAVE_NMI_SAFE_CMPXCHG) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/smp.h \
  arch/arm/include/generated/asm/mmiowb.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/mmiowb.h \
    $(wildcard include/config/MMIOWB) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/spinlock_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/rwlock_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/spinlock.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/rwlock.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/spinlock_api_smp.h \
    $(wildcard include/config/INLINE_SPIN_LOCK) \
    $(wildcard include/config/INLINE_SPIN_LOCK_BH) \
    $(wildcard include/config/INLINE_SPIN_LOCK_IRQ) \
    $(wildcard include/config/INLINE_SPIN_LOCK_IRQSAVE) \
    $(wildcard include/config/INLINE_SPIN_TRYLOCK) \
    $(wildcard include/config/INLINE_SPIN_TRYLOCK_BH) \
    $(wildcard include/config/UNINLINE_SPIN_UNLOCK) \
    $(wildcard include/config/INLINE_SPIN_UNLOCK_BH) \
    $(wildcard include/config/INLINE_SPIN_UNLOCK_IRQ) \
    $(wildcard include/config/INLINE_SPIN_UNLOCK_IRQRESTORE) \
    $(wildcard include/config/GENERIC_LOCKBREAK) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/rwlock_api_smp.h \
    $(wildcard include/config/INLINE_READ_LOCK) \
    $(wildcard include/config/INLINE_WRITE_LOCK) \
    $(wildcard include/config/INLINE_READ_LOCK_BH) \
    $(wildcard include/config/INLINE_WRITE_LOCK_BH) \
    $(wildcard include/config/INLINE_READ_LOCK_IRQ) \
    $(wildcard include/config/INLINE_WRITE_LOCK_IRQ) \
    $(wildcard include/config/INLINE_READ_LOCK_IRQSAVE) \
    $(wildcard include/config/INLINE_WRITE_LOCK_IRQSAVE) \
    $(wildcard include/config/INLINE_READ_TRYLOCK) \
    $(wildcard include/config/INLINE_WRITE_TRYLOCK) \
    $(wildcard include/config/INLINE_READ_UNLOCK) \
    $(wildcard include/config/INLINE_WRITE_UNLOCK) \
    $(wildcard include/config/INLINE_READ_UNLOCK_BH) \
    $(wildcard include/config/INLINE_WRITE_UNLOCK_BH) \
    $(wildcard include/config/INLINE_READ_UNLOCK_IRQ) \
    $(wildcard include/config/INLINE_WRITE_UNLOCK_IRQ) \
    $(wildcard include/config/INLINE_READ_UNLOCK_IRQRESTORE) \
    $(wildcard include/config/INLINE_WRITE_UNLOCK_IRQRESTORE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/list_nulls.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/wait.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/seqlock.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/mutex.h \
    $(wildcard include/config/DEBUG_MUTEXES) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/osq_lock.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/debug_locks.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/mutex_types.h \
    $(wildcard include/config/MUTEX_SPIN_ON_OWNER) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/seqlock_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/nodemask.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/nodemask_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/random.h \
    $(wildcard include/config/VMGENID) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/random.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/ioctl.h \
  arch/arm/include/generated/uapi/asm/ioctl.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/ioctl.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/asm-generic/ioctl.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/irqnr.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/irqnr.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/prandom.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/once.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/pageblock-flags.h \
    $(wildcard include/config/HUGETLB_PAGE) \
    $(wildcard include/config/HUGETLB_PAGE_SIZE_VARIABLE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/page-flags-layout.h \
  include/generated/bounds.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/mm_types.h \
    $(wildcard include/config/HAVE_ALIGNED_STRUCT_PAGE) \
    $(wildcard include/config/HUGETLB_PMD_PAGE_TABLE_SHARING) \
    $(wildcard include/config/USERFAULTFD) \
    $(wildcard include/config/ANON_VMA_NAME) \
    $(wildcard include/config/PER_VMA_LOCK) \
    $(wildcard include/config/SCHED_MM_CID) \
    $(wildcard include/config/HAVE_ARCH_COMPAT_MMAP_BASES) \
    $(wildcard include/config/MEMBARRIER) \
    $(wildcard include/config/AIO) \
    $(wildcard include/config/MMU_NOTIFIER) \
    $(wildcard include/config/SPLIT_PMD_PTLOCKS) \
    $(wildcard include/config/ARCH_WANT_BATCHED_UNMAP_TLB_FLUSH) \
    $(wildcard include/config/IOMMU_MM_DATA) \
    $(wildcard include/config/KSM) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/mm_types_task.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/auxvec.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/auxvec.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/auxvec.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/uapi/asm/auxvec.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/kref.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/refcount.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/refcount_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/rbtree.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/rbtree_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/rcupdate.h \
    $(wildcard include/config/PREEMPT_RCU) \
    $(wildcard include/config/TINY_RCU) \
    $(wildcard include/config/RCU_STRICT_GRACE_PERIOD) \
    $(wildcard include/config/RCU_LAZY) \
    $(wildcard include/config/TASKS_RCU_GENERIC) \
    $(wildcard include/config/RCU_STALL_COMMON) \
    $(wildcard include/config/NO_HZ_FULL) \
    $(wildcard include/config/KVM_XFER_TO_GUEST_WORK) \
    $(wildcard include/config/RCU_NOCB_CPU) \
    $(wildcard include/config/TASKS_RCU) \
    $(wildcard include/config/TASKS_TRACE_RCU) \
    $(wildcard include/config/TASKS_RUDE_RCU) \
    $(wildcard include/config/TREE_RCU) \
    $(wildcard include/config/DEBUG_OBJECTS_RCU_HEAD) \
    $(wildcard include/config/PROVE_RCU) \
    $(wildcard include/config/ARCH_WEAK_RELEASE_ACQUIRE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/context_tracking_irq.h \
    $(wildcard include/config/CONTEXT_TRACKING_IDLE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/rcutree.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/maple_tree.h \
    $(wildcard include/config/MAPLE_RCU_DISABLED) \
    $(wildcard include/config/DEBUG_MAPLE_TREE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/rwsem.h \
    $(wildcard include/config/RWSEM_SPIN_ON_OWNER) \
    $(wildcard include/config/DEBUG_RWSEMS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/completion.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/swait.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/uprobes.h \
    $(wildcard include/config/UPROBES) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/uprobes.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/probes.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/workqueue.h \
    $(wildcard include/config/DEBUG_OBJECTS_WORK) \
    $(wildcard include/config/FREEZER) \
    $(wildcard include/config/WQ_WATCHDOG) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/timer.h \
    $(wildcard include/config/DEBUG_OBJECTS_TIMERS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/ktime.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/jiffies.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/vdso/jiffies.h \
  include/generated/timeconst.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/vdso/ktime.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/timekeeping.h \
    $(wildcard include/config/GENERIC_CMOS_UPDATE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/clocksource_ids.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/debugobjects.h \
    $(wildcard include/config/DEBUG_OBJECTS) \
    $(wildcard include/config/DEBUG_OBJECTS_FREE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/timer_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/workqueue_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/percpu_counter.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/percpu.h \
    $(wildcard include/config/MEM_ALLOC_PROFILING) \
    $(wildcard include/config/RANDOM_KMALLOC_CACHES) \
    $(wildcard include/config/PAGE_SIZE_4KB) \
    $(wildcard include/config/NEED_PER_CPU_PAGE_FIRST_CHUNK) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/alloc_tag.h \
    $(wildcard include/config/MEM_ALLOC_PROFILING_DEBUG) \
    $(wildcard include/config/MEM_ALLOC_PROFILING_ENABLED_BY_DEFAULT) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/codetag.h \
    $(wildcard include/config/CODE_TAGGING) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/static_key.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/mmdebug.h \
    $(wildcard include/config/DEBUG_VM) \
    $(wildcard include/config/DEBUG_VM_IRQSOFF) \
    $(wildcard include/config/DEBUG_VM_PGFLAGS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sched.h \
    $(wildcard include/config/VIRT_CPU_ACCOUNTING_NATIVE) \
    $(wildcard include/config/SCHED_INFO) \
    $(wildcard include/config/SCHEDSTATS) \
    $(wildcard include/config/SCHED_CORE) \
    $(wildcard include/config/FAIR_GROUP_SCHED) \
    $(wildcard include/config/RT_GROUP_SCHED) \
    $(wildcard include/config/RT_MUTEXES) \
    $(wildcard include/config/UCLAMP_TASK) \
    $(wildcard include/config/UCLAMP_BUCKETS_COUNT) \
    $(wildcard include/config/KMAP_LOCAL) \
    $(wildcard include/config/SCHED_CLASS_EXT) \
    $(wildcard include/config/CGROUP_SCHED) \
    $(wildcard include/config/BLK_DEV_IO_TRACE) \
    $(wildcard include/config/MEMCG_V1) \
    $(wildcard include/config/COMPAT_BRK) \
    $(wildcard include/config/CGROUPS) \
    $(wildcard include/config/BLK_CGROUP) \
    $(wildcard include/config/PSI) \
    $(wildcard include/config/PAGE_OWNER) \
    $(wildcard include/config/EVENTFD) \
    $(wildcard include/config/ARCH_HAS_CPU_PASID) \
    $(wildcard include/config/CPU_SUP_INTEL) \
    $(wildcard include/config/TASK_DELAY_ACCT) \
    $(wildcard include/config/STACKPROTECTOR) \
    $(wildcard include/config/ARCH_HAS_SCALED_CPUTIME) \
    $(wildcard include/config/VIRT_CPU_ACCOUNTING_GEN) \
    $(wildcard include/config/POSIX_CPUTIMERS) \
    $(wildcard include/config/POSIX_CPU_TIMERS_TASK_WORK) \
    $(wildcard include/config/KEYS) \
    $(wildcard include/config/SYSVIPC) \
    $(wildcard include/config/DETECT_HUNG_TASK) \
    $(wildcard include/config/IO_URING) \
    $(wildcard include/config/AUDIT) \
    $(wildcard include/config/AUDITSYSCALL) \
    $(wildcard include/config/UBSAN) \
    $(wildcard include/config/UBSAN_TRAP) \
    $(wildcard include/config/TASK_XACCT) \
    $(wildcard include/config/CPUSETS) \
    $(wildcard include/config/X86_CPU_RESCTRL) \
    $(wildcard include/config/FUTEX) \
    $(wildcard include/config/COMPAT) \
    $(wildcard include/config/PERF_EVENTS) \
    $(wildcard include/config/RSEQ) \
    $(wildcard include/config/FAULT_INJECTION) \
    $(wildcard include/config/LATENCYTOP) \
    $(wildcard include/config/FUNCTION_GRAPH_TRACER) \
    $(wildcard include/config/BCACHE) \
    $(wildcard include/config/SECURITY) \
    $(wildcard include/config/BPF_SYSCALL) \
    $(wildcard include/config/GCC_PLUGIN_STACKLEAK) \
    $(wildcard include/config/X86_MCE) \
    $(wildcard include/config/KRETPROBES) \
    $(wildcard include/config/RETHOOK) \
    $(wildcard include/config/ARCH_HAS_PARANOID_L1D_FLUSH) \
    $(wildcard include/config/RV) \
    $(wildcard include/config/USER_EVENTS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/sched.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/pid_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sem_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/shm.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/shmparam.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/kmsan_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/plist_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/hrtimer_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/timerqueue_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/seccomp_types.h \
    $(wildcard include/config/SECCOMP) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/resource.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/resource.h \
  arch/arm/include/generated/uapi/asm/resource.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/resource.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/asm-generic/resource.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/latencytop.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sched/prio.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sched/types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/signal_types.h \
    $(wildcard include/config/OLD_SIGACTION) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/signal.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/signal.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/uapi/asm/signal.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/asm-generic/signal-defs.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/uapi/asm/sigcontext.h \
  arch/arm/include/generated/uapi/asm/siginfo.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/asm-generic/siginfo.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/syscall_user_dispatch_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/netdevice_xmit.h \
    $(wildcard include/config/NET_EGRESS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/task_io_accounting.h \
    $(wildcard include/config/TASK_IO_ACCOUNTING) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/posix-timers_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/rseq.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/kcsan.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/rv.h \
    $(wildcard include/config/RV_REACTORS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/livepatch_sched.h \
  arch/arm/include/generated/asm/kmap_size.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/kmap_size.h \
    $(wildcard include/config/DEBUG_KMAP_LOCAL) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sched/ext.h \
    $(wildcard include/config/EXT_GROUP_SCHED) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/mmu.h \
    $(wildcard include/config/CPU_HAS_ASID) \
    $(wildcard include/config/VDSO) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/page-flags.h \
    $(wildcard include/config/PAGE_IDLE_FLAG) \
    $(wildcard include/config/ARCH_USES_PG_ARCH_2) \
    $(wildcard include/config/ARCH_USES_PG_ARCH_3) \
    $(wildcard include/config/HUGETLB_PAGE_OPTIMIZE_VMEMMAP) \
    $(wildcard include/config/DEBUG_KMAP_LOCAL_FORCE_MAP) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/local_lock.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/local_lock_internal.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/zswap.h \
    $(wildcard include/config/ZSWAP) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/memory_hotplug.h \
    $(wildcard include/config/ARCH_HAS_ADD_PAGES) \
    $(wildcard include/config/MEMORY_HOTREMOVE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/notifier.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/srcu.h \
    $(wildcard include/config/TINY_SRCU) \
    $(wildcard include/config/NEED_SRCU_NMI_SAFE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/rcu_segcblist.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/srcutree.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/rcu_node_tree.h \
    $(wildcard include/config/RCU_FANOUT) \
    $(wildcard include/config/RCU_FANOUT_LEAF) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/topology.h \
    $(wildcard include/config/USE_PERCPU_NUMA_NODE_ID) \
    $(wildcard include/config/SCHED_SMT) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/arch_topology.h \
    $(wildcard include/config/GENERIC_ARCH_TOPOLOGY) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/topology.h \
    $(wildcard include/config/ARM_CPU_TOPOLOGY) \
    $(wildcard include/config/BL_SWITCHER) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/topology.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sysctl.h \
    $(wildcard include/config/SYSCTL) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/sysctl.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/elf.h \
    $(wildcard include/config/ARCH_HAVE_EXTRA_ELF_NOTES) \
    $(wildcard include/config/ARCH_USE_GNU_PROPERTY) \
    $(wildcard include/config/ARCH_HAVE_ELF_PROT) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/elf.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/user.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/elf.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/elf-em.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/kobject.h \
    $(wildcard include/config/UEVENT_HELPER) \
    $(wildcard include/config/DEBUG_KOBJECT_RELEASE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sysfs.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/kernfs.h \
    $(wildcard include/config/KERNFS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/idr.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/radix-tree.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/xarray.h \
    $(wildcard include/config/XARRAY_MULTI) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sched/mm.h \
    $(wildcard include/config/MMU_LAZY_TLB_REFCOUNT) \
    $(wildcard include/config/ARCH_HAS_MEMBARRIER_CALLBACKS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sync_core.h \
    $(wildcard include/config/ARCH_HAS_SYNC_CORE_BEFORE_USERMODE) \
    $(wildcard include/config/ARCH_HAS_PREPARE_SYNC_CORE_CMD) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sched/coredump.h \
    $(wildcard include/config/CORE_DUMP_DEFAULT_ELF_HEADERS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/kobject_ns.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/moduleparam.h \
    $(wildcard include/config/ALPHA) \
    $(wildcard include/config/PPC64) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/rbtree_latch.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/error-injection.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/error-injection.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/tracepoint-defs.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/module.h \
    $(wildcard include/config/ARM_UNWIND) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/module.h \
    $(wildcard include/config/HAVE_MOD_ARCH_SPECIFIC) \
    $(wildcard include/config/MODULES_USE_ELF_REL) \
    $(wildcard include/config/MODULES_USE_ELF_RELA) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/unwind.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/fs.h \
    $(wildcard include/config/READ_ONLY_THP_FOR_FS) \
    $(wildcard include/config/FS_POSIX_ACL) \
    $(wildcard include/config/CGROUP_WRITEBACK) \
    $(wildcard include/config/IMA) \
    $(wildcard include/config/FILE_LOCKING) \
    $(wildcard include/config/FSNOTIFY) \
    $(wildcard include/config/FS_ENCRYPTION) \
    $(wildcard include/config/FS_VERITY) \
    $(wildcard include/config/EPOLL) \
    $(wildcard include/config/UNICODE) \
    $(wildcard include/config/QUOTA) \
    $(wildcard include/config/FS_DAX) \
    $(wildcard include/config/BLOCK) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/wait_bit.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/kdev_t.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/kdev_t.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/dcache.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/rculist.h \
    $(wildcard include/config/PROVE_RCU_LIST) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/rculist_bl.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/list_bl.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/bit_spinlock.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/lockref.h \
    $(wildcard include/config/ARCH_USE_CMPXCHG_LOCKREF) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/stringhash.h \
    $(wildcard include/config/DCACHE_WORD_ACCESS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/hash.h \
    $(wildcard include/config/HAVE_ARCH_HASH) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/path.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/list_lru.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/shrinker.h \
    $(wildcard include/config/SHRINKER_DEBUG) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/pid.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/capability.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/capability.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/semaphore.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/fcntl.h \
    $(wildcard include/config/ARCH_32BIT_OFF_T) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/fcntl.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/uapi/asm/fcntl.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/asm-generic/fcntl.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/openat2.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/migrate_mode.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/percpu-rwsem.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/rcuwait.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sched/signal.h \
    $(wildcard include/config/SCHED_AUTOGROUP) \
    $(wildcard include/config/BSD_PROCESS_ACCT) \
    $(wildcard include/config/TASKSTATS) \
    $(wildcard include/config/STACK_GROWSUP) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/signal.h \
    $(wildcard include/config/DYNAMIC_SIGFRAME) \
    $(wildcard include/config/PROC_FS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sched/jobctl.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sched/task.h \
    $(wildcard include/config/HAVE_EXIT_THREAD) \
    $(wildcard include/config/ARCH_WANTS_DYNAMIC_TASK_STRUCT) \
    $(wildcard include/config/HAVE_ARCH_THREAD_STRUCT_WHITELIST) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/uaccess.h \
    $(wildcard include/config/ARCH_HAS_SUBPAGE_FAULTS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/fault-inject-usercopy.h \
    $(wildcard include/config/FAULT_INJECTION_USERCOPY) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/nospec.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/uaccess.h \
    $(wildcard include/config/CPU_SW_DOMAIN_PAN) \
    $(wildcard include/config/CPU_TTBR0_PAN) \
    $(wildcard include/config/HAVE_EFFICIENT_UNALIGNED_ACCESS) \
    $(wildcard include/config/UACCESS_WITH_MEMCPY) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/domain.h \
    $(wildcard include/config/IO_36) \
    $(wildcard include/config/CPU_USE_DOMAINS) \
    $(wildcard include/config/CPU_CP15_MMU) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/unaligned.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/unaligned/packed_struct.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/vdso/unaligned.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/pgtable.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/proc-fns.h \
    $(wildcard include/config/BIG_LITTLE) \
    $(wildcard include/config/HARDEN_BRANCH_PREDICTOR) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/glue-proc.h \
    $(wildcard include/config/CPU_ARM7TDMI) \
    $(wildcard include/config/CPU_ARM720T) \
    $(wildcard include/config/CPU_ARM740T) \
    $(wildcard include/config/CPU_ARM9TDMI) \
    $(wildcard include/config/CPU_ARM920T) \
    $(wildcard include/config/CPU_ARM922T) \
    $(wildcard include/config/CPU_ARM925T) \
    $(wildcard include/config/CPU_ARM926T) \
    $(wildcard include/config/CPU_ARM940T) \
    $(wildcard include/config/CPU_ARM946E) \
    $(wildcard include/config/CPU_ARM1020) \
    $(wildcard include/config/CPU_ARM1020E) \
    $(wildcard include/config/CPU_ARM1022) \
    $(wildcard include/config/CPU_ARM1026) \
    $(wildcard include/config/CPU_MOHAWK) \
    $(wildcard include/config/CPU_FEROCEON) \
    $(wildcard include/config/CPU_V6K) \
    $(wildcard include/config/CPU_PJ4B) \
    $(wildcard include/config/CPU_V7) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/pgtable-nopud.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/pgtable-nop4d.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/pgtable-hwdef.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/pgtable-2level-hwdef.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/tlbflush.h \
    $(wildcard include/config/SMP_ON_UP) \
    $(wildcard include/config/CPU_TLB_V4WT) \
    $(wildcard include/config/CPU_TLB_FA) \
    $(wildcard include/config/CPU_TLB_V4WBI) \
    $(wildcard include/config/CPU_TLB_FEROCEON) \
    $(wildcard include/config/CPU_TLB_V4WB) \
    $(wildcard include/config/CPU_TLB_V6) \
    $(wildcard include/config/CPU_TLB_V7) \
    $(wildcard include/config/ARM_ERRATA_720789) \
    $(wildcard include/config/ARM_ERRATA_798181) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/pgtable-2level.h \
  arch/arm/include/generated/asm/extable.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/extable.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/asm-generic/access_ok.h \
    $(wildcard include/config/ALTERNATE_USER_ADDRESS_SPACE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/cred.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/key.h \
    $(wildcard include/config/KEY_NOTIFICATIONS) \
    $(wildcard include/config/NET) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/assoc_array.h \
    $(wildcard include/config/ASSOCIATIVE_ARRAY) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sched/user.h \
    $(wildcard include/config/VFIO_PCI_ZDEV_KVM) \
    $(wildcard include/config/IOMMUFD) \
    $(wildcard include/config/WATCH_QUEUE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/ratelimit.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/posix-timers.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/alarmtimer.h \
    $(wildcard include/config/RTC_CLASS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/hrtimer.h \
    $(wildcard include/config/HIGH_RES_TIMERS) \
    $(wildcard include/config/TIME_LOW_RES) \
    $(wildcard include/config/TIMERFD) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/hrtimer_defs.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/timerqueue.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/rcu_sync.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/delayed_call.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/uuid.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/errseq.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/ioprio.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sched/rt.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/iocontext.h \
    $(wildcard include/config/BLK_ICQ) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/ioprio.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/fs_types.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/mount.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/mnt_idmapping.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/slab.h \
    $(wildcard include/config/FAILSLAB) \
    $(wildcard include/config/KFENCE) \
    $(wildcard include/config/SLUB_TINY) \
    $(wildcard include/config/SLUB_DEBUG) \
    $(wildcard include/config/SLAB_FREELIST_HARDENED) \
    $(wildcard include/config/SLAB_BUCKETS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/percpu-refcount.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/kasan.h \
    $(wildcard include/config/KASAN_STACK) \
    $(wildcard include/config/KASAN_VMALLOC) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/kasan-enabled.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/kasan-tags.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/rw_hint.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/fs.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/quota.h \
    $(wildcard include/config/QUOTA_NETLINK_INTERFACE) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/dqblk_xfs.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/dqblk_v1.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/dqblk_v2.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/dqblk_qtree.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/projid.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/uapi/linux/quota.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/cdev.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/device.h \
    $(wildcard include/config/GENERIC_MSI_IRQ) \
    $(wildcard include/config/ENERGY_MODEL) \
    $(wildcard include/config/PINCTRL) \
    $(wildcard include/config/ARCH_HAS_DMA_OPS) \
    $(wildcard include/config/DMA_DECLARE_COHERENT) \
    $(wildcard include/config/DMA_CMA) \
    $(wildcard include/config/SWIOTLB) \
    $(wildcard include/config/SWIOTLB_DYNAMIC) \
    $(wildcard include/config/ARCH_HAS_SYNC_DMA_FOR_DEVICE) \
    $(wildcard include/config/ARCH_HAS_SYNC_DMA_FOR_CPU) \
    $(wildcard include/config/ARCH_HAS_SYNC_DMA_FOR_CPU_ALL) \
    $(wildcard include/config/DMA_OPS_BYPASS) \
    $(wildcard include/config/DMA_NEED_SYNC) \
    $(wildcard include/config/IOMMU_DMA) \
    $(wildcard include/config/PM_SLEEP) \
    $(wildcard include/config/OF) \
    $(wildcard include/config/DEVTMPFS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/dev_printk.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/energy_model.h \
    $(wildcard include/config/SCHED_DEBUG) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sched/cpufreq.h \
    $(wildcard include/config/CPU_FREQ) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sched/topology.h \
    $(wildcard include/config/SCHED_CLUSTER) \
    $(wildcard include/config/SCHED_MC) \
    $(wildcard include/config/CPU_FREQ_GOV_SCHEDUTIL) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sched/idle.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/sched/sd_flags.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/ioport.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/klist.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/pm.h \
    $(wildcard include/config/VT_CONSOLE_SLEEP) \
    $(wildcard include/config/CXL_SUSPEND) \
    $(wildcard include/config/PM) \
    $(wildcard include/config/PM_CLK) \
    $(wildcard include/config/PM_GENERIC_DOMAINS) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/device/bus.h \
    $(wildcard include/config/ACPI) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/device/class.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/device/devres.h \
    $(wildcard include/config/HAS_IOMEM) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/device/driver.h \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/arch/arm/include/asm/device.h \
    $(wildcard include/config/ARM_DMA_USE_IOMMU) \
    $(wildcard include/config/ARCH_OMAP) \
  /home/ntai/yocto/build_conf/build-beagle-bone-black/tmp/work-shared/beaglebone/kernel-source/include/linux/pm_wakeup.h \

/home/ntai/embedded_linux_pratice/12/character.o: $(deps_/home/ntai/embedded_linux_pratice/12/character.o)

$(deps_/home/ntai/embedded_linux_pratice/12/character.o):
