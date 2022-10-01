#! /bin/bash

RED=$(tput setaf 166)
GREEN=$(tput setaf 77)
YELLOW=$(tput setaf 220)
BLUE=$(tput setaf 153)
EOC=$(tput sgr0)

if [ "$1" == "" ] || [ "$#" -ne 1 ] || [[ ! $1 =~ ^-?[[:digit:]]+$ ]]
then
	printf "\nusage: ./run.sh [number]\n
	e.g. '${YELLOW}./run.sh 50${EOC}' will run the script 50 times w/ big-superposition maps.
	results better than expected will be highligted in ${GREEN}green${EOC},
	results worse than will be saved to maps/trace_maps/ and shown in ${RED}red${EOC}.\n\n"
	exit
fi

declare -i I=0

while [[ I -lt $1 ]]
do
	./maps/generator --big-superposition > maps/superposition/temp.map
	EXPECTED=( `grep "required: " maps/superposition/temp.map | cut -f8 -d " " | head -1` )
	RESULT=( `./lem-in <  maps/superposition/temp.map | grep ">>>>" | cut -f2 -d " "` )
	
	COLOR=${EOC}
	MAP=""
	if [ $RESULT -lt $EXPECTED ]
	then
		COLOR=${GREEN}
	elif [ $EXPECTED -lt $RESULT ]
	then
		mkdir -p maps/trace_maps/
		cp maps/superposition/temp.map maps/trace_maps/trace_${I}.map
		COLOR=${RED}
		MAP="\t--> trace_${I}.map"
	fi

	printf "Expected: $EXPECTED | Result: ${COLOR}$RESULT${EOC}${MAP}\n"

	rm -fr maps/superposition/temp.map
	I=$((I + 1))
done
