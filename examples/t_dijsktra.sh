#!/bin/bash

tests=(
"test/1.txt"
"test/2.txt"
)

for test in ${tests[@]};do
  cp ${test} t_graph.1.txt
  echo "================================================================================"
  echo "test ${test}"
  ./t_dijsktra.exe
done

