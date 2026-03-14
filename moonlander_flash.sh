#!/bin/bash
chcp.com 65001 > /dev/null 2>&1

export PYTHONIOENCODING=utf-8:surrogateescape
export PYTHONUTF8=1

export LANG='en_US.UTF-8'
export LC_ALL='en_US.UTF-8'
qmk flash //wsl.localhost/arch/home/dobin/repo/qmk_userspace/zsa_moonlander_hyeondobin.bin
