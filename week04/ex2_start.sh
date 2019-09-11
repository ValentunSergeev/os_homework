#!/usr/bin/env bash

./ex2.out &

for (( VAR = 0; VAR < 5; ++VAR )); do
    pstree $!

    sleep 1
done
