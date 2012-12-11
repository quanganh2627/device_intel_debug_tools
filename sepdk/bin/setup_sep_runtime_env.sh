#!/bin/sh
#
# =============================================================================
# Filename: setup_sep_runtime_env.sh
# Version: 1.02
# Purpose: SEP Runtime environment setup script
# Description: This script should be used to set up the run-time environment
#              for SEP.  It requires sh.  Run this script before running any
#              SEP executable, e.g., sep or sfdump5
#
# Usage: source setup_sep_runtime_env.sh
#
# Copyright(C) 2004-2011 Intel Corporation.  All Rights Reserved.
# =============================================================================

CURR_DIR=`pwd`

echo 0 > /proc/sys/kernel/nmi_watchdog
echo 0 > /proc/sys/kernel/kptr_restrict

export SEP_INSTALL_PATH=`pwd`
echo SEP is currently installed under $SEP_INSTALL_PATH
export SEP_BASE_DIR="${CURR_DIR}"
echo "SEP_BASE_DIR=${SEP_BASE_DIR}" 

export PATH="${SEP_INSTALL_PATH}:${PATH}"
export LD_LIBRARY_PATH="${SEP_INSTALL_PATH}:${LD_LIBRARY_PATH}"

# show settings of various environment variables
echo "PATH=${PATH}"
echo "LD_LIBRARY_PATH=${LD_LIBRARY_PATH}"

