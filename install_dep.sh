#!/bin/sh

TMP_LIBFT_DIR=tmpLibft
LIBFT_REPO=https://github.com/PalmNeko/Libt

cd $(dirname "$0") || ( echo 'error change dir' && exit 1 )

git clone ${LIBFT_REPO} ./${TMP_LIBFT_DIR}

cp -r ./${TMP_LIBFT_DIR}/submit ./submit/Libft

rm -rf ./${TMP_LIBFT_DIR}