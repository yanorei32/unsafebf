#!/bin/bash

compilers=("gcc" "clang")
compile_options=("" "-O0" "-O1" "-O2" "-O3" "-Og" "-Ofast" "-Os" "-Oz")
errored_cases=()
dir=$(cd "$(dirname "$0")" && pwd)

for cc in "${compilers[@]}"; do
	if ! type "$cc" > /dev/null 2>&1; then
		echo -e "\e[1;93mWARNING: $cc is not installed. Skip tests!\e[0m"
		continue
	fi

	for options in "${compile_options[@]}"; do
		for f in "$dir"/tests/*.bf; do
			echo    "TEST    : $cc $options"
			echo    "TESTCASE: $(basename "$f")"
			echo -n "RESULT  : "

			diff <($cc main.c $options -o unsafebf 2>/dev/null && ./unsafebf "$(cat "$f")") <(echo 0) >/dev/null

			if [[ $? -eq 0 ]]; then
				echo -e "\e[1;92mOK\e[0m"
			else
				echo -e "\e[1;91mERR\e[0m"
				errored_cases+=("$cc $options $(basename "$f")")
			fi
			echo
		done
	done
done



if [[ ${#errored_cases[@]} -eq 0 ]]; then
	echo yeah! worked in all cases!
else
	echo Errored in:
	for c in "${errored_cases[@]}"; do
		echo "- $c"
	done
fi
