make clean
make -j

echo "$now"
echo -e "\n----------Begin ./microbench----------"
./microbench | tee -a ./microbench-result
