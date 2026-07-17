#!/bin/bash
# Turn the led on the front panel with a selected color
echo "Enter the color:"

read color

printf "PLS=00\r" > /dev/ttyS2
printf "BLK=00\r" > /dev/ttyS2

if [ "$color" = "" ]; then
    echo "No color entered."
elif [ "$color" = "red" ]; then
    echo "Setting led to red."
    printf "LED=02\r" > /dev/ttyS2
elif [ "$color" = "green" ]; then
    echo "Setting led to green."
    printf "LED=04\r" > /dev/ttyS2
elif [ "$color" = "blue" ]; then
    echo "Setting led to blue."
    printf "LED=01\r" > /dev/ttyS2
else
    echo "Invalid color entered."
fi