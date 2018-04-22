#!/usr/bin/env bash

#Check if this is a valid git repo
if [ ! -d .git]
then
	echo"==== This is not a valid git repository. Script will end. ===="
	exit 1
fi

# Create an "array" of directories
directories=(bin include lib src)

#Iterate over array and see if folders need to be created.
for directory in ${directories[*]}
do
	if [ ! -d $directory ]
	then
		echo "$directory doesn't exist. Creating..."
		mkdir $directory
		touch $directory/READ.md
	fi
done
#Copy the cath framework from mr.w's repo
curl https://raw.githubusercontent.com/irawoodring/CIS263_Project_Template/master/include/catch.hpp >> include/catch.hpp

#Copy the makefile from mr.w's repo
curl https://raw.githubusercontent.com/irawoodring/CIS263_Project_Template/master/Makefile >> Makefile

git add ./bin
git add ./bin/READ.md
git add ./include
git add ./include/READ.md
git add ./lib
git add ./lib/READ.md
git add ./src
git add ./src/READ.md
git add ./include/catch.hpp
git commit -m "Setup project skeleton."
git push
