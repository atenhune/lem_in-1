#! /bin/bash

RED=$(tput setaf 166)
GREEN=$(tput setaf 77)
YELLOW=$(tput setaf 220)
BLUE=$(tput setaf 153)
EOC=$(tput sgr0)

if [ "$1" == "" ] || [ "$#" -ne 1 ] || [[ ! $1 =~ ^-?[[:digit:]]+$ ]]
then
	printf "\nusage: ./run.sh [number]\n
	E.g. '${YELLOW}./run.sh 50${EOC}' will run the script 50 times on big-superposition maps.
	Selected maps will be saved in maps/trace_maps/ directory.
	Results better than expected will be shown in ${GREEN}green${EOC},
	and results worse than will be highlighted in ${RED}red${EOC}.\n\n"
	exit
fi

declare -i UNDER=0
declare -i U_RES=0
declare -i OVER=0
declare -i O_RES=0
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
		UNDER=$((UNDER + 1))
		U_RES=$((U_RES + DIFF))
		if [ $DIFF -gt 2 ]
		then
			cp maps/trace_maps/temp.map maps/trace_maps/under_${I}__${DIFF}.map
			MSG="\t+${DIFF} -->\tunder_${I}__${DIFF}.map"
		fi
	elif [ $EXPECTED -lt $RESULT ]
	then
		COLOR=${RED}
		DIFF=$(($RESULT - $EXPECTED))
		OVER=$((OVER + 1))
		O_RES=$((O_RES + DIFF))
		cp maps/trace_maps/temp.map maps/trace_maps/trace_${I}__${DIFF}.map
		MSG="\t-${DIFF} -->\ttrace_${I}__${DIFF}.map"
	fi

	printf "Expected: $EXPECTED | Result: ${COLOR}$RESULT${EOC}${MSG}\n"

	rm -fr maps/trace_maps/temp.map
	I=$((I + 1))
	sleep 0.3
done

printf "DONE\n\nReport:\n"
printf " ${GREEN}${UNDER}${EOC}/$1 of maps were solved better than expected.\n"
if [ $UNDER -gt 0 ]
then
	U_AVR=$(echo "$U_RES/$UNDER" | bc -l)
	printf "  avarage: +"
	printf %.1f\\n $U_AVR
fi

printf " ${RED}${OVER}${EOC}/$1 of maps were solved worse than expected.\n"
if [ $OVER -gt 0 ]
then
	O_AVR=$(echo "$O_RES/$OVER" | bc -l)
	printf "  avarage: -"
	printf %.1f\\n\\n $O_AVR
fi
printf "\nDo you wish to remove trace maps? (yes/no)\n"
read remove_trace
if [ "$remove_trace" == "yes" ]
then
	rm -fr maps/trace_maps/
fi
exit
