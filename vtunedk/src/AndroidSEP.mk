# This makefile is included from vendor/intel/*/AndroidBoard.mk.
vtunedk=true
sep_version=sep3_10
$(eval $(call build_kernel_module,$(call my-dir),sep3_10,"BOARD_HAVE_SMALL_RAM=$(BOARD_HAVE_SMALL_RAM)"))
