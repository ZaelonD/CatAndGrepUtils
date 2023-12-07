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

# 3 флага 1 файл

for file in "${files[@]}"
do
    for flag1 in "${flags[@]}"
    do
        for flag2 in "${flags[@]}"
        do
            for flag3 in "${flags[@]}"
            do
                if [[ "$flag1" != "$flag2" ]] && [[ "$flag1" != "$flag3" ]] && [[ "$flag2" != "$flag3" ]]
                then
                    MY_UTIL_COMMAND="./$MY_UTIL_NAME $flag1 $flag2 $flag3 $file"
                    ORIGINAL_UTIL_COMMAND="$ORIGINAL_UTIL_NAME $flag1 $flag2 $flag3 $file"
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
done

# 3 флага и несколько файлов

for flag1 in "${flags[@]}"
do
    for flag2 in "${flags[@]}"
    do
        for flag3 in "${flags[@]}"
        do
            if [[ "$flag1" != "$flag2" ]] && [[ "$flag1" != "$flag3" ]] && [[ "$flag2" != "$flag3" ]]
            then
                MY_UTIL_COMMAND="./$MY_UTIL_NAME $flag1 $flag2 $flag3 ${files[@]}"
                ORIGINAL_UTIL_COMMAND="$ORIGINAL_UTIL_NAME $flag1 $flag2 $flag3 ${files[@]}"
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

# 4 флага 1 файл

for file in "${files[@]}"
do
    for flag1 in "${flags[@]}"
    do
        for flag2 in "${flags[@]}"
        do
            for flag3 in "${flags[@]}"
            do
                for flag4 in "${flags[@]}"
                do
                    if 
                    [[ "$flag1" != "$flag2" ]] && [[ "$flag1" != "$flag3" ]] && [[ "$flag2" != "$flag3" ]] && 
                    [[ "$flag1" != "$flag4" ]] && [[ "$flag2" != "$flag4" ]] && [[ "$flag3" != "$flag4" ]]
                    then
                        MY_UTIL_COMMAND="./$MY_UTIL_NAME $flag1 $flag2 $flag3 $flag4 $file"
                        ORIGINAL_UTIL_COMMAND="$ORIGINAL_UTIL_NAME $flag1 $flag2 $flag3 $flag4 $file"
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
    done
done

# 4 флага и несколько файлов

for flag1 in "${flags[@]}"
do
    for flag2 in "${flags[@]}"
    do
        for flag3 in "${flags[@]}"
        do
            for flag4 in "${flags[@]}"
            do
                if 
                [[ "$flag1" != "$flag2" ]] && [[ "$flag1" != "$flag3" ]] && [[ "$flag2" != "$flag3" ]] && 
                [[ "$flag1" != "$flag4" ]] && [[ "$flag2" != "$flag4" ]] && [[ "$flag3" != "$flag4" ]]
                then
                    MY_UTIL_COMMAND="./$MY_UTIL_NAME $flag1 $flag2 $flag3 $flag4 ${files[@]}"
                    ORIGINAL_UTIL_COMMAND="$ORIGINAL_UTIL_NAME $flag1 $flag2 $flag3 $flag4 ${files[@]}"
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
done

# 5 флагов 1 файл

for file in "${files[@]}"
do
    for flag1 in "${flags[@]}"
    do
        for flag2 in "${flags[@]}"
        do
            for flag3 in "${flags[@]}"
            do
                for flag4 in "${flags[@]}"
                do
                    for flag5 in "${flags[@]}"
                    do
                        if 
                        [[ "$flag1" != "$flag2" ]] && [[ "$flag1" != "$flag3" ]] && [[ "$flag2" != "$flag3" ]] && 
                        [[ "$flag1" != "$flag4" ]] && [[ "$flag2" != "$flag4" ]] && [[ "$flag3" != "$flag4" ]] &&
                        [[ "$flag1" != "$flag5" ]] && [[ "$flag2" != "$flag5" ]] && [[ "$flag3" != "$flag5" ]] &&
                        [[ "$flag4" != "$flag5" ]]
                        then
                            MY_UTIL_COMMAND="./$MY_UTIL_NAME $flag1 $flag2 $flag3 $flag4 $flag5 $file"
                            ORIGINAL_UTIL_COMMAND="$ORIGINAL_UTIL_NAME $flag1 $flag2 $flag3 $flag4 $flag5 $file"
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
        done
    done
done

# 5 флагов и несколько файлов

for flag1 in "${flags[@]}"
do
    for flag2 in "${flags[@]}"
    do
        for flag3 in "${flags[@]}"
        do
            for flag4 in "${flags[@]}"
            do
                for flag5 in "${flags[@]}"
                do
                    if 
                    [[ "$flag1" != "$flag2" ]] && [[ "$flag1" != "$flag3" ]] && [[ "$flag2" != "$flag3" ]] && 
                    [[ "$flag1" != "$flag4" ]] && [[ "$flag2" != "$flag4" ]] && [[ "$flag3" != "$flag4" ]] &&
                    [[ "$flag1" != "$flag5" ]] && [[ "$flag2" != "$flag5" ]] && [[ "$flag3" != "$flag5" ]] &&
                    [[ "$flag4" != "$flag5" ]]
                    then
                        MY_UTIL_COMMAND="./$MY_UTIL_NAME $flag1 $flag2 $flag3 $flag4 $flag5 ${files[@]}"
                        ORIGINAL_UTIL_COMMAND="$ORIGINAL_UTIL_NAME $flag1 $flag2 $flag3 $flag4 $flag5 ${files[@]}"
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
    done
done

# 6 флагов 1 файл

for file in "${files[@]}"
do
    for flag1 in "${flags[@]}"
    do
        for flag2 in "${flags[@]}"
        do
            for flag3 in "${flags[@]}"
            do
                for flag4 in "${flags[@]}"
                do
                    for flag5 in "${flags[@]}"
                    do
                        for flag6 in "${flags[@]}"
                        do
                            if 
                            [[ "$flag1" != "$flag2" ]] && [[ "$flag1" != "$flag3" ]] && [[ "$flag2" != "$flag3" ]] && 
                            [[ "$flag1" != "$flag4" ]] && [[ "$flag2" != "$flag4" ]] && [[ "$flag3" != "$flag4" ]] &&
                            [[ "$flag1" != "$flag5" ]] && [[ "$flag2" != "$flag5" ]] && [[ "$flag3" != "$flag5" ]] &&
                            [[ "$flag4" != "$flag5" ]] && [[ "$flag1" != "$flag6" ]] && [[ "$flag2" != "$flag6" ]] &&
                            [[ "$flag3" != "$flag6" ]] && [[ "$flag4" != "$flag6" ]] && [[ "$flag5" != "$flag6" ]]
                            then
                                MY_UTIL_COMMAND="./$MY_UTIL_NAME $flag1 $flag2 $flag3 $flag4 $flag5 $flag6 $file"
                                ORIGINAL_UTIL_COMMAND="$ORIGINAL_UTIL_NAME $flag1 $flag2 $flag3 $flag4 $flag5 $flag6 $file"
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
            done
        done
    done
done

# 6 флагов и несколько файлов

for flag1 in "${flags[@]}"
do
    for flag2 in "${flags[@]}"
    do
        for flag3 in "${flags[@]}"
        do
            for flag4 in "${flags[@]}"
            do
                for flag5 in "${flags[@]}"
                do
                    for flag6 in "${flags[@]}"
                    do
                        if 
                        [[ "$flag1" != "$flag2" ]] && [[ "$flag1" != "$flag3" ]] && [[ "$flag2" != "$flag3" ]] && 
                        [[ "$flag1" != "$flag4" ]] && [[ "$flag2" != "$flag4" ]] && [[ "$flag3" != "$flag4" ]] &&
                        [[ "$flag1" != "$flag5" ]] && [[ "$flag2" != "$flag5" ]] && [[ "$flag3" != "$flag5" ]] &&
                        [[ "$flag4" != "$flag5" ]] && [[ "$flag1" != "$flag6" ]] && [[ "$flag2" != "$flag6" ]] &&
                        [[ "$flag3" != "$flag6" ]] && [[ "$flag4" != "$flag6" ]] && [[ "$flag5" != "$flag6" ]]
                        then
                            MY_UTIL_COMMAND="./$MY_UTIL_NAME $flag1 $flag2 $flag3 $flag4 $flag5 $flag6 ${files[@]}"
                            ORIGINAL_UTIL_COMMAND="$ORIGINAL_UTIL_NAME $flag1 $flag2 $flag3 $flag4 $flag5 $flag6 ${files[@]}"
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
        done
    done
done

printf "$GREEN%s\n" "SUCCESS = $SUCCESS"
printf "$RED%s\n" "FAIL = $FAIL"