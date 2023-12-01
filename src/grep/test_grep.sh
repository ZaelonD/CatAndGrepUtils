SUCCESS=0
FAIL=0
COUNTER=0

RED="$(tput setaf 1)"
GREEN="$(tput setaf 2)"

files=("test_1_grep.txt" "test_2_grep.txt" "empty.txt")
template=("1337" "test" "prov" "1..7")
flags=("i" "v" "c" "l" "n" "h" "s" "o" "e")

# 1 file 1 flag
for file1 in "${files[@]}"
do
    for flag1 in "${flags[@]}"
    do
        for temp in "${template[@]}"
        do
            echo "\n -$flag1 $temp $file1:"
            ./s21_grep "-$flag1" "$temp" "$file1" > s21grep_output.txt
            grep "-$flag1" "$temp" "$file1" > grep_output.txt
            if diff -q s21grep_output.txt grep_output.txt >/dev/null 2>&1;
            then
                let "COUNTER++"
                let "SUCCESS++"
                echo "$COUNTER - $GREEN Success"
            else 
                let "COUNTER++"
                let "FAIL++"
                echo "$COUNTER - $RED Fail"
            fi
            rm s21grep_output.txt
            rm grep_output.txt
        done
    done
done

# 3 files 1 flag
for flag1 in "${flags[@]}"
do
    for temp in "${template[@]}"
    do
        echo "\n -$flag1 $temp ${files[0]} ${files[1]} ${files[2]}:"
        ./s21_grep "-$flag1" "$temp" "${files[0]}" "${files[1]}" "${files[2]}" > s21grep_output.txt

        grep "-$flag1" "$temp" "${files[0]}" "${files[1]}" "${files[2]}" > grep_output.txt
        if diff -q s21grep_output.txt grep_output.txt >/dev/null 2>&1;
        then
            let "COUNTER++"
            let "SUCCESS++"
            echo "$COUNTER - $GREEN Success"
        else 
            let "COUNTER++"
            let "FAIL++"
            echo "$COUNTER - $RED Fail"
        fi
        rm s21grep_output.txt
        rm grep_output.txt
    done
done

# 3 files 2 flags
for flag1 in "${flags[@]}"
do
    for flag2 in "${flags[@]}"
    do
        if [[ "$flag1" != "$flag2" ]]
        then
            for temp in "${template[@]}"
            do
                echo "\n -$flag1 -$flag2 $temp ${files[0]} ${files[1]} ${files[2]}:"
                ./s21_grep "-$flag1" "-$flag2" "$temp" "${files[0]}" "${files[1]}" "${files[2]}" > s21grep_output.txt
                grep "-$flag1" "-$flag2" "$temp" "${files[0]}" "${files[1]}" "${files[2]}" > grep_output.txt
                if diff -q s21grep_output.txt grep_output.txt >/dev/null 2>&1;
                then
                    let "COUNTER++"
                    let "SUCCESS++"
                    echo "$COUNTER - $GREEN Success"
                else 
                    let "COUNTER++"
                    let "FAIL++"
                    echo "$COUNTER - $RED Fail"
                fi
                rm s21grep_output.txt
                rm grep_output.txt
            done
        fi
    done
done

echo ""
echo "Success = $SUCCESS"
Echo "$RED Fail = $FAIL"