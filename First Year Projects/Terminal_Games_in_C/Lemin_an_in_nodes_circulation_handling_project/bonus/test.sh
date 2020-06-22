#!/usr/bin/env bash

exit_code=0
pass=0
fail=0

#-------------TEST 1-------------

echo ""
echo "---- Test n°1 : Return value in case of successful end ----"

./lem_in < bonus/hantill_test1

if [ $? -ne 0 ]
then
 exit_code=1
 fail=$((fail + 1))
 echo "    ¤ Test failed ¤"
else
 pass=$((pass + 1))
 echo "    ¤ Test passed ¤"
fi

#---------END OF TEST 1----------

#-------------TEST 2-------------

echo ""
echo "---- Test n°2 : Return value in case of wrong file given ----"

./lem_in < main.c

if [ $? -ne 84 ]
then
 exit_code=1
 fail=$((fail + 1))
 echo "    ¤ Test failed ¤"
else
 pass=$((pass + 1))
 echo "    ¤ Test passed ¤"
fi

#---------END OF TEST 2----------

#-------------TEST 3-------------

echo ""
echo "---- Test n°3 : Return value in case of no argument / file given ----"

./lem_in

if [ $? -ne 84 ]
then
 exit_code=1
 fail=$((fail + 1))
 echo "    ¤ Test failed ¤"
else
 pass=$((pass + 1))
 echo "    ¤ Test passed ¤"
fi

#---------END OF TEST 3----------

#-------------TEST 4-------------

echo ""
echo "---- Test n°4 : The output is ok ----"

./lem_in < bonus/hantill_basictest > bonus/output.txt
diff -q bonus/output.txt bonus/output_basictest > /dev/null
comp_value=$?

if [ $comp_value -eq 1 ]
then
 exit_code=1
 fail=$((fail + 1))
 echo "    ¤ Test failed ¤"
else
 pass=$((pass + 1))
 echo "    ¤ Test passed ¤"
fi

#---------END OF TEST 4----------

#-------------TEST 5-------------

echo ""
echo "---- Test n°5 : The output is ok but with a medium antill ----"

./lem_in < bonus/hantill_test1 > bonus/output.txt
diff -q bonus/output.txt bonus/output_test1 > /dev/null
comp_value=$?

if [ $comp_value -eq 1 ]
then
 exit_code=1
 fail=$((fail + 1))
 echo "    ¤ Test failed ¤"
else
 pass=$((pass + 1))
 echo "    ¤ Test passed ¤"
fi

#---------END OF TEST 5----------

#-------------TEST 6-------------

echo ""
echo "---- Test n°6 : The output is ok but with a bigger antill ----"

./lem_in < bonus/hantill_test2 > bonus/output.txt
diff -q bonus/output.txt bonus/output_test2 > /dev/null
comp_value=$?

if [ $comp_value -eq 1 ]
then
 exit_code=1
 fail=$((fail + 1))
 echo "    ¤ Test failed ¤"
else
 pass=$((pass + 1))
 echo "    ¤ Test passed ¤"
fi

#---------END OF TEST 6----------

#---------TESTS SUMMARY----------

if [ $exit_code -ne 0 ]
then
 echo ""
 echo ""
 echo "<<< $fail ERRORS found during the execution of the tests.  >>>"
else
 echo ""
 echo ""
 echo "<<< No errors were found during the execution of the tests. >>>"
fi
 
echo ""
echo ""
echo "---- Tests completed ----"
echo ""
echo "  ¤ Passed $pass || Failed $fail ¤"
echo ""
echo ""
dateTest=`date`
echo "---- End of testing at: $dateTest ----"
echo ""
 
exit 0
 
#----------END OF FILE-----------