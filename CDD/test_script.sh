#!/bin/bash

build_driver(){
	echo
	read -n1 -p "Do you want to build driver(y/n)? "
	if [ $REPLY = 'y' ]
	then
		echo "Building driver........."
		if ( make )
		then
			echo "Driver Build Successfully"
		else
			echo "Driver Build Failed"
			read
		fi

	fi
}

insert_driver(){
	echo
	read -n1 -p "Do you want to insert driver(y/n):"
	if [ $REPLY = 'y' ]
	then
		echo
		echo "Inserting driver........."
		read -p "Enter NOD to inserted:" no
		read -p "Enter Device Size:" dS
		insmod ./modules/DD.ko nod=$no devSize=$dS
	fi

}

remove_driver(){
	echo
	read -n1 -p "Do you want to remove driver(y/n):"
	if [ $REPLY = 'y' ]
	then
		echo
		echo "Removing driver........."
		rmmod DD
	fi
}

watch_driver(){
	echo
	read -n1 -p "Do you want to Watch driver(y/n):"
	if [ $REPLY = 'y' ]
	then
		echo
		echo "Watching driver........."
		lsmod
		read
		dmesg
		read
		cat /proc/devices
		read
		cat /proc/modules
		read
	fi
}

clean_driver(){
	echo
	read -n1 -p "Do you want to clean driver(y/n)?"
	if [ $REPLY = 'y' ]
	then
		if ( make clean )
		then
			echo " Clean Successfull "
		else
			echo " Clean Failed "
			read
		fi
	fi
}

main_menu(){
    echo 	
    echo "Welcome to Driver testing"
    echo "1. Build Driver  "
    echo "2. Insert Driver "
    echo "3. Watch Module  "
    echo "4. Remove Module "
    echo "5. Clean Driver  "
    echo "0. Exit          "   
    read -n1 choice
    return $choice    
}

while(true)
do
	main_menu
	cv=$?
	case $cv in
		1)
			build_driver
			;;
		2)
			insert_driver
			;;
		4)
			remove_driver
			;;
		3)
			watch_driver
			;;
		5)
			clean_driver
			;;
		0)
			exit
			;;
	esac
done



