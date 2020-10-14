#!/bin/bash

touch tis.config

list=(`ls corpus`)

echo "["> tis.config
for f in ${list[@]};
do
    echo "{
        \"files\": [
            \"CPool_bistro-matic_2019/division.c\",
            \"CPool_bistro-matic_2019/eval_expr.c\",
            \"CPool_bistro-matic_2019/infin_add.c\",
            \"CPool_bistro-matic_2019/infin_sub.c\",
            \"CPool_bistro-matic_2019/main2.c\",
            \"CPool_bistro-matic_2019/modulo.c\",
            \"CPool_bistro-matic_2019/my_str_to_word_array.c\",
            \"CPool_bistro-matic_2019/parentheses.c\",
            \"CPool_bistro-matic_2019/product.c\",
            \"CPool_bistro-matic_2019/src/analyse_string.c\",
            \"CPool_bistro-matic_2019/src/clear_string.c\",
            \"CPool_bistro-matic_2019/src/errors.c\",
            \"CPool_bistro-matic_2019/src/my_revstr.c\",
            \"CPool_bistro-matic_2019/src/power_of_ten.c\",
            \"CPool_bistro-matic_2019/src/my_strcat.c\"
        ],
        \"machdep\": \"gcc_x86_64\",
        \"compilation_cmd\": \"-ICPool_bistro-matic_2019\",
        \"filesystem\": {
            \"files\": [
                {
                    \"name\": \"inputs/input\",
                    \"from\": CPool_bistro-matic_2019/corpus/$f
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
