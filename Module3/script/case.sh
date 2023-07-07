#!/bin/bash
echo "1. List of files \n"
echo "2. No. of Process \n"
echo "3. Today's Date \n"
echo "4. Logged Users \n"
echo "5. Exit \n"
echo "Enter Your Choice"
read ch
case $ch in
	1)ls;;
	2)ps;;
	3)date;;
	4)whoami;;
	5)exit;;
	*)echo "Wrong choise enter again"
esac
