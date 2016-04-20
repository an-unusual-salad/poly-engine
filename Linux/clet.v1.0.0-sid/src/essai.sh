#!/bin/sh 

./clet -d > dump 
echo "--------------------"
 ndisasm -u ./dump

