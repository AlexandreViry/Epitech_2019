#!/bin/bash

mkdir corpus

for f in `ls out/crashes/`;
do
    cp "out/crashes/$f" "./corpus"
done

rm -rf out

cd corpus

for f in `ls`;
do
    mv $f `sha256sum  $f | cut -d' ' -f1 | cut -c1-15`
done

cp "*" "../old_corpus"
