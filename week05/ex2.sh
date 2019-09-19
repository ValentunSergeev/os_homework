#!/bin/sh

tempfile=$(mktemp ./lock.XXXX)

for (( VAR = 0; VAR < 1000; ++VAR )); do
    lockfile=./lockfile

    while ! ln $tempfile $lockfile; do
       :
    done

    value=`cat file.txt`

    IFS=', ' read -r -a array <<< "$value"

    newValue=$((array[-1]+1))

    printf " ${newValue}" >> file.txt

    rm $lockfile
done

rm $tempfile


