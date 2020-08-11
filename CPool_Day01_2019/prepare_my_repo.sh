#!/bin/bash
blih -u alexandre.viry@epitech.eu repository create $1
blih -u alexandre.viry@epitech.eu repository setacl $1 ramassage-tek r
blih -u alexandre.viry@epitech.eu repository getacl $1
