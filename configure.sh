#!/bin/bash

unset -v GMP_DIR
unset -v PREFIX
while getopts g:p: option; do
        case ${option} in
                g) GMP_DIR=$OPTARG ;;
                p) PREFIX=$OPTARG ;;
                \?) echo "Unsupported option -$OPTARG." ;;
                :) echo "Option -$OPTARG requires an argument." ;;
        esac
done

shift "$((OPTIND - 1))"

if [[ -z "${GMP_DIR}" ]]; then
	echo "Error: GMP_DIR not defined"
	exit 1
elif [[ -z "${PREFIX}" ]]; then
	echo "Error: PREFIX not defined"
	exit 1
else
        if [ ! -d ${PREFIX} ]; then
                mkdir ${PREFIX}
        fi
        if [ ! -f ${PWD}/build_cache ]; then
                touch ${PWD}/build_cache
        fi
        > ${PWD}/build_cache
	echo ${GMP_DIR} >> ${PWD}/build_cache
	echo ${PREFIX} >> ${PWD}/build_cache
        unset -v GMP_DIR
        unset -v PREFIX
fi
