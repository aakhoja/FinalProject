#!/bin/bash
# Estimate pi with Montecarlo method:

echo -e "\n**** PIE CALCULATOR ****"
read -p "Enter the number of tries to calculate pie (10~100000) : " checking
num=${checking:-"10"}
echo -e "Calculating pie : "
time echo "scale=3; 4*a(1)" | bc -lq
exit 0
