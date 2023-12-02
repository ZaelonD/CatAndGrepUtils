SUCCESS=0
FAIL=0
COUNTER=0

RED="$(tput setaf 1)"
GREEN="$(tput setaf 2)"

files=("test.txt" "test1.txt" "empty.txt")
template=("1337" "test" "prov" "^t" "1..7")
flags=("i" "v" "c" "l" "n" "h" "s" "o")
patternfiles=("pat1.txt" "pat2.txt")

# 1 file 1 flag

for file1 in "${files[@]}"
do
    for flag1 in "${flags[@]}"
    do
        for tem in "${template[@]}"
        do
            echo "\n-$flag1 $tem $file1:"
            ./s21_grep "-$flag1" "$tem" "$file1" > s21grep_output.txt
            grep "-$flag1" "$tem" "$file1" > grep_output.txt
            if diff -q s21grep_output.txt grep_output.txt >/dev/null 2>&1;
            then
                let "COUNTER++"
                let "SUCCESS++"
                echo "$COUNTER - Success"
            else 
                let "COUNTER++"
                let "FAIL++"
                echo "$COUNTER - Fail"
            fi
            rm s21grep_output.txt
            rm grep_output.txt
        done
    done
done

# 3 files 1 flag

# for flag1 in "${flags[@]}"
# do
#     for tem in "${template[@]}"
#     do
#         echo "\n-$flag1 $tem ${files[0]} ${files[1]} ${files[2]}:"
#         ./s21_grep "-$flag1" "$tem" "${files[0]}" "${files[1]}" "${files[2]}" > s21grep_output.txt

#         grep "-$flag1" "$tem" "${files[0]}" "${files[1]}" "${files[2]}" > grep_output.txt
#         if diff -q s21grep_output.txt grep_output.txt >/dev/null 2>&1;
#         then
#             let "COUNTER++"
#             let "SUCCESS++"
#             echo "$COUNTER - Success"
#         else 
#             let "COUNTER++"
#             let "FAIL++"
#             echo "$COUNTER - Fail"
#         fi
#         rm s21grep_output.txt
#         rm grep_output.txt
#     done
# done

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

# # 3 files -f and -e + 2 other flags
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
echo "$GREEN Success = $SUCCESS"
Echo "$RED Fail = $FAIL"