SUCCESS=0 FAIL=0 COUNTER=0
RED=$"\033[91m" GREEN=$"\033[92m"
MY_UTIL_NAME=s21_cat ORIGINAL_UTIL_NAME=cat
files=(test1.txt test2.txt test3.txt test4.txt)
flags=(-b -n -s -v -e -t)

# 1 флаг 1 файл

for file in "${files[@]}"
do
    for flag in "${flags[@]}"
    do
        MY_UTIL_COMMAND="./$MY_UTIL_NAME $flag $file"
        ORIGINAL_UTIL_COMMAND="$ORIGINAL_UTIL_NAME $flag $file"
        $MY_UTIL_COMMAND > my_util_result.txt
        $ORIGINAL_UTIL_COMMAND > original_util_result.txt
        if diff -q my_util_result.txt original_util_result.txt >/dev/null 2>&1;
        then
            printf "$GREEN%s\n" "$MY_UTIL_COMMAND"
            let "COUNTER++"
            let "SUCCESS++"
            printf "%s\n\n" "$COUNTER - SUCCESS"
        else
            printf "$RED%s\n" "$MY_UTIL_COMMAND"
            let "COUNTER++"
            let "FAIL++"
            printf "$RED%s\n\n" "$COUNTER - FAIL"
        fi
        rm my_util_result.txt
        rm original_util_result.txt
    done
done

# 1 флаг и несколько файлов

for flag in "${flags[@]}"
do
    MY_UTIL_COMMAND="./$MY_UTIL_NAME $flag ${files[@]}"
    ORIGINAL_UTIL_COMMAND="$ORIGINAL_UTIL_NAME $flag ${files[@]}"
    $MY_UTIL_COMMAND > my_util_result.txt
    $ORIGINAL_UTIL_COMMAND > original_util_result.txt
    if diff -q my_util_result.txt original_util_result.txt >/dev/null 2>&1;
    then
        printf "$GREEN%s\n" "$MY_UTIL_COMMAND"
        let "COUNTER++"
        let "SUCCESS++"
        printf "%s\n\n" "$COUNTER - SUCCESS"
    else
        printf "$RED%s\n" "$MY_UTIL_COMMAND"
        let "COUNTER++"
        let "FAIL++"
        printf "$RED%s\n\n" "$COUNTER - FAIL"
    fi
    rm my_util_result.txt
    rm original_util_result.txt
done

# 2 флага 1 файл

for file in "${files[@]}"
do
    for flag1 in "${flags[@]}"
    do
        for flag2 in "${flags[@]}"
        do
            if [[ "$flag1" != "$flag2" ]]
            then
                MY_UTIL_COMMAND="./$MY_UTIL_NAME $flag1 $flag2 $file"
                ORIGINAL_UTIL_COMMAND="$ORIGINAL_UTIL_NAME $flag1 $flag2 $file"
                $MY_UTIL_COMMAND > my_util_result.txt
                $ORIGINAL_UTIL_COMMAND > original_util_result.txt
                if diff -q my_util_result.txt original_util_result.txt >/dev/null 2>&1;
                then
                    printf "$GREEN%s\n" "$MY_UTIL_COMMAND"
                    let "COUNTER++"
                    let "SUCCESS++"
                    printf "%s\n\n" "$COUNTER - SUCCESS"
                else
                    printf "$RED%s\n" "$MY_UTIL_COMMAND"
                    let "COUNTER++"
                    let "FAIL++"
                    printf "$RED%s\n\n" "$COUNTER - FAIL"
                fi
                rm my_util_result.txt
                rm original_util_result.txt
            fi
        done
    done
done

# 2 флага и несколько файлов

for flag1 in "${flags[@]}"
do
    for flag2 in "${flags[@]}"
    do
        if [[ "$flag1" != "$flag2" ]]
        then
            MY_UTIL_COMMAND="./$MY_UTIL_NAME $flag1 $flag2 ${files[@]}"
            ORIGINAL_UTIL_COMMAND="$ORIGINAL_UTIL_NAME $flag1 $flag2 ${files[@]}"
            $MY_UTIL_COMMAND > my_util_result.txt
            $ORIGINAL_UTIL_COMMAND > original_util_result.txt
            if diff -q my_util_result.txt original_util_result.txt >/dev/null 2>&1;
            then
                printf "$GREEN%s\n" "$MY_UTIL_COMMAND"
                let "COUNTER++"
                let "SUCCESS++"
                printf "%s\n\n" "$COUNTER - SUCCESS"
            else
                printf "$RED%s\n" "$MY_UTIL_COMMAND"
                let "COUNTER++"
                let "FAIL++"
                printf "$RED%s\n\n" "$COUNTER - FAIL"
            fi
            rm my_util_result.txt
            rm original_util_result.txt
        fi
    done
done

printf "$GREEN%s\n" "SUCCESS = $SUCCESS"
printf "$RED%s\n" "FAIL = $FAIL"





#                 echo "Your output:\n"
#                 cat s21cat_output.txt
#                 echo "\n\nCat output:\n"
#                 cat cat_output.txt
#                 echo "\n"