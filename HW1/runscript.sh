OUTPUT_F="output.log"
for i in {0..1000}; do
    ./reality4 >> $OUTPUT_F
done