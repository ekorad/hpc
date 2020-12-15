rm -f results.csv

for i in {1..40}
	do
		echo `./main fisier.txt output encrypt $i` >> results.csv
	done
