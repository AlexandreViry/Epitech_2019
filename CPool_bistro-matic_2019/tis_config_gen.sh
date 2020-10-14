#!/bin/bash

touch tis.config

list=(`ls corpus`)

echo "["> tis.config
for f in ${list[@]};
do
    echo "{
        \"files\": [
            \"CPool_bistro-matic/division.c\",
            \"CPool_bistro-matic/eval_expr.c\",
            \"CPool_bistro-matic/infin_add.c\",
            \"CPool_bistro-matic/infin_sub.c\",
            \"CPool_bistro-matic/main2.c\",
            \"CPool_bistro-matic/modulo.c\",
            \"CPool_bistro-matic/my_str_to_word_array.c\",
            \"CPool_bistro-matic/parentheses.c\",
            \"CPool_bistro-matic/product.c\",
            \"CPool_bistro-matic/src/analyse_string.c\",
            \"CPool_bistro-matic/src/clear_string.c\",
            \"CPool_bistro-matic/src/errors.c\",
            \"CPool_bistro-matic/src/my_revstr.c\",
            \"CPool_bistro-matic/src/power_of_ten.c\",
            \"CPool_bistro-matic/src/my_strcat.c\"
        ],
        \"machdep\": \"gcc_x86_64\",
        \"compilation_cmd\": \"-ICPool_bistro-matic\",
        \"filesystem\": {
            \"files\": [
                {
                    \"name\": \"inputs/input\",
                    \"from\": CPool_bistro-matic/corpus/$f
                }
            ]
        }" >> tis.config
    if [ $f = ${list[-1]} ];
    then
        echo "}" >> tis.config
    else
        echo "}," >> tis.config
    fi
done
echo "]" >> tis.config
mv tis.config ../
