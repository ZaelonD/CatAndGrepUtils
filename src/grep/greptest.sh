SUCCESS=0 FAIL=0 COUNTER=0
RED=$"\033[91m" GREEN=$"\033[92m"
MY_UTIL_NAME=s21_grep ORIGINAL_UTIL_NAME=grep
files=(test1.txt test2.txt test3.txt)
flags=(-i -v -c -l -n -h -s -o)
examples=(1337 test prov ^t 1..7 qwer)
patternfiles=(reg1.txt reg2.txt)

# # 1 флаг 1 файл
# for file in "${files[@]}"
# do
#     for flag in "${flags[@]}"
#     do
#         for example in "${examples[@]}"
#         do
#             MY_UTIL_COMMAND="./$MY_UTIL_NAME $flag $example $file"
#             ORIGINAL_UTIL_COMMAND="$ORIGINAL_UTIL_NAME $flag $example $file"
#             $MY_UTIL_COMMAND > my_util_result.txt
#             $ORIGINAL_UTIL_COMMAND > original_util_result.txt
#             if diff -q my_util_result.txt original_util_result.txt >/dev/null 2>&1;
#             then
#                 printf "$GREEN%s\n" "$MY_UTIL_COMMAND"
#                 let "COUNTER++"
#                 let "SUCCESS++"
#                 printf "%s\n\n" "$COUNTER - SUCCESS"
#             else
#                 printf "$RED%s\n" "$MY_UTIL_COMMAND"
#                 let "COUNTER++"
#                 let "FAIL++"
#                 printf "$RED%s\n\n" "$COUNTER - FAIL"
#             fi
#             rm my_util_result.txt
#             rm original_util_result.txt
#         done
#     done
# done

# # 1 флаг и несколько файлов

# for flag in "${flags[@]}"
# do
#     for example in "${examples[@]}"
#     do
#         MY_UTIL_COMMAND="./$MY_UTIL_NAME $flag $example ${files[@]}"
#         ORIGINAL_UTIL_COMMAND="$ORIGINAL_UTIL_NAME $flag $example ${files[@]}"
#         $MY_UTIL_COMMAND > my_util_result.txt
#         $ORIGINAL_UTIL_COMMAND > original_util_result.txt
#         if diff -q my_util_result.txt original_util_result.txt >/dev/null 2>&1;
#         then
#             printf "$GREEN%s\n" "$MY_UTIL_COMMAND"
#             let "COUNTER++"
#             let "SUCCESS++"
#             printf "%s\n\n" "$COUNTER - SUCCESS"
#         else
#             printf "$RED%s\n" "$MY_UTIL_COMMAND"
#             let "COUNTER++"
#             let "FAIL++"
#             printf "$RED%s\n\n" "$COUNTER - FAIL"
#         fi
#         rm my_util_result.txt
#         rm original_util_result.txt
#     done
# done

# # 2 флага 1 файл

# for file in "${files[@]}"
# do
#     for flag1 in "${flags[@]}"
#     do
#         for flag2 in "${flags[@]}"
#         do
#             if [[ "$flag1" != "$flag2" ]]
#             then
#                 for example in "${examples[@]}"
#                 do
#                     MY_UTIL_COMMAND="./$MY_UTIL_NAME $flag1 $flag2 $example $file"
#                     ORIGINAL_UTIL_COMMAND="$ORIGINAL_UTIL_NAME $flag1 $flag2 $example $file"
#                     $MY_UTIL_COMMAND > my_util_result.txt
#                     $ORIGINAL_UTIL_COMMAND > original_util_result.txt
#                     if diff -q my_util_result.txt original_util_result.txt >/dev/null 2>&1;
#                     then
#                         printf "$GREEN%s\n" "$MY_UTIL_COMMAND"
#                         let "COUNTER++"
#                         let "SUCCESS++"
#                         printf "%s\n\n" "$COUNTER - SUCCESS"
#                     else
#                         printf "$RED%s\n" "$MY_UTIL_COMMAND"
#                         let "COUNTER++"
#                         let "FAIL++"
#                         printf "$RED%s\n\n" "$COUNTER - FAIL"
#                     fi
#                     rm my_util_result.txt
#                     rm original_util_result.txt
#                 done
#             fi
#         done
#     done
# done

# # 2 флага и несколько файлов

# for flag1 in "${flags[@]}"
# do
#     for flag2 in "${flags[@]}"
#     do
#         if [[ "$flag1" != "$flag2" ]]
#         then
#             for example in "${examples[@]}"
#             do
#                 MY_UTIL_COMMAND="./$MY_UTIL_NAME $flag1 $flag2 $example ${files[@]}"
#                 ORIGINAL_UTIL_COMMAND="$ORIGINAL_UTIL_NAME $flag1 $flag2 $example ${files[@]}"
#                 $MY_UTIL_COMMAND > my_util_result.txt
#                 $ORIGINAL_UTIL_COMMAND > original_util_result.txt
#                 if diff -q my_util_result.txt original_util_result.txt >/dev/null 2>&1;
#                 then
#                     printf "$GREEN%s\n" "$MY_UTIL_COMMAND"
#                     let "COUNTER++"
#                     let "SUCCESS++"
#                     printf "%s\n\n" "$COUNTER - SUCCESS"
#                 else
#                     printf "$RED%s\n" "$MY_UTIL_COMMAND"
#                     let "COUNTER++"
#                     let "FAIL++"
#                     printf "$RED%s\n\n" "$COUNTER - FAIL"
#                 fi
#                 rm my_util_result.txt
#                 rm original_util_result.txt
#             done
#         fi
#     done
# done

# # 3 флага 1 файл

# for file in "${files[@]}"
# do
#     for flag1 in "${flags[@]}"
#     do
#         for flag2 in "${flags[@]}"
#         do
#             for flag3 in "${flags[@]}"
#             do
#                 if [[ "$flag1" != "$flag2" ]] && [[ "$flag1" != "$flag3" ]] && [[ "$flag2" != "$flag3" ]]
#                 then
#                     for example in "${examples[@]}"
#                     do
#                         MY_UTIL_COMMAND="./$MY_UTIL_NAME $flag1 $flag2 $flag3 $example $file"
#                         ORIGINAL_UTIL_COMMAND="$ORIGINAL_UTIL_NAME $flag1 $flag2 $flag3 $example $file"
#                         $MY_UTIL_COMMAND > my_util_result.txt
#                         $ORIGINAL_UTIL_COMMAND > original_util_result.txt
#                         if diff -q my_util_result.txt original_util_result.txt >/dev/null 2>&1;
#                         then
#                             printf "$GREEN%s\n" "$MY_UTIL_COMMAND"
#                             let "COUNTER++"
#                             let "SUCCESS++"
#                             printf "%s\n\n" "$COUNTER - SUCCESS"
#                         else
#                             printf "$RED%s\n" "$MY_UTIL_COMMAND"
#                             let "COUNTER++"
#                             let "FAIL++"
#                             printf "$RED%s\n\n" "$COUNTER - FAIL"
#                         fi
#                         rm my_util_result.txt
#                         rm original_util_result.txt
#                     done
#                 fi
#             done
#         done
#     done
# done

# 3 флага и несколько файлов

for flag1 in "${flags[@]}"
do
    for flag2 in "${flags[@]}"
    do
        for flag3 in "${flags[@]}"
        do
            if [[ "$flag1" != "$flag2" ]] && [[ "$flag1" != "$flag3" ]] && [[ "$flag2" != "$flag3" ]]
            then
                for example in "${examples[@]}"
                do
                    MY_UTIL_COMMAND="./$MY_UTIL_NAME $flag1 $flag2 $flag3 $example ${files[@]}"
                    ORIGINAL_UTIL_COMMAND="$ORIGINAL_UTIL_NAME $flag1 $flag2 $flag3 $example ${files[@]}"
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
                        echo "Your output:\n"
                        cat my_util_result.txt
                        echo "\n\nGrep output:\n"
                        cat original_util_result.txt
                        echo "\n"
                    fi
                    rm my_util_result.txt
                    rm original_util_result.txt
                done
            fi
        done
    done
done

printf "$GREEN%s\n" "SUCCESS = $SUCCESS"
printf "$RED%s\n" "FAIL = $FAIL"

# # 3 files 2 flags
# for flag1 in "${flags[@]}"
# do
#     for flag2 in "${flags[@]}"
#     do
#         if [[ "$flag1" != "$flag2" ]]
#         then
#             for tem in "${template[@]}"
#             do
#                 echo "\n-$flag1 -$flag2 $tem ${files[0]} ${files[1]} ${files[2]}:"
#                 ./s21_grep "-$flag1" "-$flag2" "$tem" "${files[0]}" "${files[1]}" "${files[2]}" > s21grep_output.txt
#                 grep "-$flag1" "-$flag2" "$tem" "${files[0]}" "${files[1]}" "${files[2]}" > grep_output.txt
#                 if diff -q s21grep_output.txt grep_output.txt >/dev/null 2>&1;
#                 then
#                     let "COUNTER++"
#                     let "SUCCESS++"
#                     echo "$COUNTER - Success"
#                 else 
#                     let "COUNTER++"
#                     let "FAIL++"
#                     echo "$COUNTER - Fail"
#                     echo "Your output:\n"
#                     cat s21grep_output.txt
#                     echo "\n\nGrep output:\n"
#                     cat grep_output.txt
#                     echo "\n"
#                 fi
#                 rm s21grep_output.txt
#                 rm grep_output.txt
#             done
            
#         fi
#     done
# done

# # # 3 files -f and -e + 2 other flags
# for patfile in "${patternfiles[@]}"
# do
#     for flag1 in "${flags[@]}"
#     do
#         for flag2 in "${flags[@]}"
#         do
#             if [[ "$flag1" != "$flag2" ]]
#             then
#                 for tem in "${template[@]}"
#                 do
#                     echo "\n-$flag1 -$flag2 -e$tem -f$patfile ${files[0]} ${files[1]} ${files[2]}:"
#                     ./s21_grep "-$flag1" "-$flag2" "-e$tem" "-f$patfile" "${files[0]}" "${files[1]}" "${files[2]}" > s21grep_output.txt
#                     grep "-$flag1" "-$flag2" "-e$tem" "-f$patfile" "${files[0]}" "${files[1]}" "${files[2]}" > grep_output.txt
#                     if diff -q s21grep_output.txt grep_output.txt >/dev/null 2>&1;
#                     then
#                         let "COUNTER++"
#                         let "SUCCESS++"
#                         echo "$COUNTER - Success"
#                     else 
#                         let "COUNTER++"
#                         let "FAIL++"
#                         echo "$COUNTER - Fail"
#                         echo "Your output:\n"
#                         cat s21grep_output.txt
#                         echo "\n\nGrep output:\n"
#                         cat grep_output.txt
#                         echo "\n"
#                     fi
#                     rm s21grep_output.txt
#                     rm grep_output.txt
#                 done
                
#             fi
#         done
#     done
# done