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
		read -p "Enter no of Registers:" nR
		read -p "Enter register Size:" rS
		insmod ./modules/DD.ko nod=$no devSize=$dS noReg=$nR regSize=$rS
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

build_app(){
	echo
	read -n1 -p "Do you want to build app(y/n)?"
	if [ $REPLY = 'y' ]
	then
		cd ./app
		echo "Building app............"
		if ( make )
		then
			echo "App Build Successfully"
		else
			echo "App Build Failed"
			read
		fi
		cd ..
	
	fi
}

test_driver(){
	echo
	read -n1 -p "Do you want to test driver(y/n)?"
	if [ $REPLY = 'y' ]
	then
		cd ./app
		read -p "Enter Major No of driver:" mn
		min=0
		echo major=$mn
		echo minor=$min
		mknod -m 666 ./DD c $mn $min
		ls -al
		read
		if ( ./app DD )
		then
			echo "App executed successfully"
		else
			echo "App execution failed"
			read
		fi
		unlink DD
		ls -al
		read
		cd ..

	fi

}

clean_app(){
	echo
	read -n1 -p "Do you want to clean app(y/n)?"
	if [ $REPLY = 'y' ]
	then
		cd ./app
		if ( make clean )
		then
			echo " Clean Successfull "
		else
			echo " Clean Failed "
			read
		fi
		cd ..
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
    echo "6. Build Application "
    echo "7. Test Driver with App "
    echo "8. Clean Application "
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
		6)
			build_app
			;;
		7)
			test_driver
			;;
		8)
			clean_app
			;;
		0)
			exit
			;;
	esac
done



