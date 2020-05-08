make clean
make -j

echo "we" | sudo -S ./flush.sh

echo -e "\n----------Begin ./microbench----------"
./microbench | tee -a ./microbench-result
