#!/bin/bash

for f in `ls out/crashes/`;
do
    cp "out/crashes/$f" "./corpus"
done

cd corpus

for f in `ls`;
do
    mv $f `sha256sum  $f | cut -d' ' -f1 | cut -c1-15`
done
