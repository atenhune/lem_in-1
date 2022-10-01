#! /bin/bash

RED=$(tput setaf 166)
GREEN=$(tput setaf 77)
YELLOW=$(tput setaf 220)
BLUE=$(tput setaf 153)
EOC=$(tput sgr0)

if [ "$1" == "" ] || [ "$#" -ne 1 ] || [[ ! $1 =~ ^-?[[:digit:]]+$ ]]
then
	printf "\nusage: ./run.sh [number]\n
	e.g. '${YELLOW}./run.sh 50${EOC}' will run the script 50 times on big-superposition maps.
	selected maps will be saved in maps/trace_maps/ directory.
	results better than expected will be shown in ${GREEN}green${EOC},
	results worse than will be highlighted in ${RED}red${EOC}.\n\n"
	exit
fi

declare -i I=0

printf "\nTesting $1 big-superposition maps.\n\n"

while [[ I -lt $1 ]]
do
	mkdir -p maps/trace_maps/
	./maps/generator --big-superposition > maps/trace_maps/temp.map
	EXPECTED=( `grep "required: " maps/trace_maps/temp.map | cut -f8 -d " " | head -1` )
	RESULT=( `./lem-in <  maps/trace_maps/temp.map | grep ">>>>" | cut -f2 -d " "` )
	
	COLOR=${EOC}
	DIFF=""
	MSG=""
	if [ $RESULT -lt $EXPECTED ]
	then
		COLOR=${GREEN}
		DIFF=$(($EXPECTED - $RESULT))
		if [ $DIFF -gt 2 ]
		then
			cp maps/trace_maps/temp.map maps/trace_maps/under_${I}__${DIFF}.map
			MSG="\t-${DIFF} -->\tunder_${I}__${DIFF}.map"
		fi
	elif [ $EXPECTED -lt $RESULT ]
	then
		COLOR=${RED}
		DIFF=$(($RESULT - $EXPECTED))
		cp maps/trace_maps/temp.map maps/trace_maps/trace_${I}__${DIFF}.map
		MSG="\t+${DIFF} -->\ttrace_${I}__${DIFF}.map"
	fi

	printf "Expected: $EXPECTED | Result: ${COLOR}$RESULT${EOC}${MSG}\n"

	rm -fr maps/trace_maps/temp.map
	I=$((I + 1))
	sleep 1
done
