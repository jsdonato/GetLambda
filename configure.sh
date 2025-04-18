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
        > ${PWD}/.cache
	echo ${GMP_DIR} >> ${PWD}/.cache
	echo ${PREFIX} >> ${PWD}/.cache
        unset -v GMP_DIR
        unset -v PREFIX
fi
