#!/bin/bash
# Write a message to the front panel display
echo "Enter the message to display:"
read message

if [ "$message" = "" ]; then
    echo "No message entered."
else
    echo "Writing message to front panel display."
    printf "LN1=%s\r" "$message" > /dev/ttyS2
fi

# Make the message scroll across the display using a loop with a delay
for a in {1..5}; do
    message1="$message"
    for i in {1..16}; do
        printf "LN1=%s\r" "$message1" > /dev/ttyS2

        # subtract one character from the message to create a scrolling effect
        message1=${message1:1}

        sleep 0.2
    done
done
