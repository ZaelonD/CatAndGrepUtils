SUCCESS=0
FAIL=0
COUNTER=0

files=("test.txt" "test2.txt")
flags=("-b" "-n" "-s" "-v" "-e" "-t")

for file in "${files[@]}"
do
    for flag1 in "${flags[@]}"
    do
        for flag2 in "${flags[@]}"
        do
            echo "\n$flag1 $flag2 -v ${files[0]} ${files[1]}:"
            ./s21_cat "$flag1" "-v" "$flag2" "${files[0]}" "${files[1]}" > s21cat_output.txt
            cat "$flag1" "$flag2" "-v" "${files[0]}" "${files[1]}" > cat_output.txt
            if diff -q s21cat_output.txt cat_output.txt >/dev/null 2>&1;
            then
                let "COUNTER++"
                let "SUCCESS++"
                echo "$COUNTER - Success"
            else 
                let "COUNTER++"
                let "FAIL++"
                echo "$COUNTER - Fail"
                echo "Your output:\n"
                cat s21cat_output.txt
                echo "\n\nCat output:\n"
                cat cat_output.txt
                echo "\n"
            fi
            rm s21cat_output.txt
            rm cat_output.txt
        done
    done
done

echo "\nSuccess = $SUCCESS"
Echo "Fail = $FAIL"