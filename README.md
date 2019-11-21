# myrete-lite
---
# user guide
pa -a find the main's PID.
cat /proc/PID/status get the meminfo of main(VmRSS).
---

05.09 finish some of betamemory . using shared_ptr to manage the new token.  should using shared_ptr in other file.


05.13 finish all the base node and modify all the point to smart_point(boost::shared_ptr).


05.15 the function:get join test node from condition need to bedone.

05.16 complete the createcondition function.  one problem need tobe done: default argument should be declared only once. so we often declare it on declare function,but not in determined function. 


05.17  complete the function build alphanet. two problem new:   1.every class's default construct function need to be write				2.string getfirst(string)/string getsecond(string) which used to divied the symbol to minsymbol an maxsymbol.
								3.construct function 's argument need to be add "const" all.


05.20
add_production function need tobe completed.   and the build shared alphamemory function's second argument "root" need tobe considered.

05.29
delete the retenode .  using joinnode and betamemory instead.    debug make error.


05.30
modify the function: join_left_activation and join_right_activation when parent's token.size()=0(means the joinnode's parentnode is dummynode.)

modify the token's default construction and add some setfunctions.

make successfully first time!!!


05.30afternoon

add RHS vector. so that the terminal can print out the same number of rule's RHS.
add arg into function add_produtin() "const string &num" to refer the number of the rule/terminal.
add a function createrhs() can read RHS from rule.txt and save into the vector.

05.31 morning  add function getdataintowm() to read the data from data/data file once a line and insert into wm.

05.31night: the testjoinnode has some problem. need a way to comfirm the function. why 
rule:1
LHS:
windows = 0
rain ! 0
temprature = 33,9999
RHS:
windows = open
data:
temprature = 35
can successfully insert into terminal? why the last joinnode's testjoinnode will be true??

06.03 night: have find the problem in function of getjointestnode(),: int id,attr,vlaue=0;this one just definate the value =0 , id and attr is random int.so change them into :
int id=0;
int attr=0;
int value =0;
beside, add some code to cout the test condition.

6.04 morning
add rule.c rule.h create rule class. add the function createrule() from rule.txt.
this way, we can create more than one rule in the rule.txt. and the net can compile the multi-rule retenet.
function createrule need tobe complete.
terminal node class need tobe modified.
function add_production may need tobe modified.

06.06 morning
complete the multi-rule read and create. test multi-rule sucessfully.

06.10 add ctime include file to calculate the time.  using excel on Windows to create thousands of rules. so the function read rule file need tobe changed!

6.13 night  complete the function read rule and add timesum to count the all WME throw the net's time.

11.19
have add btree optimize . But it need some test data to confirm.  

11.21
test the btree finished. the test rule.text:  
rule: 1
LHS:
11 22 33 44 55 66 77 88
12 23 34 45 55 67 78 88
RHS:
1is fired!!!!!!!!!
end
rule: 2
LHS:
11 22 33 44 55 66 77 88
2 2 2 2 2 2 2 88
46 68 80 22 33 44 55 88
543 314 123 1234 54 356 23 88
RHS:
2 is fired!!!!!!!!!
end
rule: 3
LHS:
11 22 33 44 55 66 77 88
1 1 1 1 1 1 1 88
2 2 2 2 2 2 2 88
RHS:
3 is fired!!!!!!!!!
end

rule: 4
LHS:
2 2 2 2 2 2 2 88
1 2 3 4 5 6 7 88
54 123 43 56 32 4 56 88
1 1 1 1 1 1 1 88
14 56 23 45 76 1 34 88
RHS:
4 is fired!!!!!!!!!
end

rule: 5
LHS:
32 45 65 29 83 567 7 88
766 23 412 45 6 12 86 88
1 1 1 1 1 1 1 88
3 3 3 3 3 3 3 88
2 2 2 2 2 2 2 88
RHS:
5 is fired!!!!!!!!!
end

rule: 6
LHS:
37 35 65 59 34 547 74 88
87 12 38 47 19 30 38 88
3 3 3 3 3 3 3 88
2 2 2 2 2 2 2 88
00 91 38 13 84 75 26 88
RHS:
6 is fired!!!!!!!!!
end

rule: 7
LHS:
65 42 46 76 134 54 6 88
93 18 93 46 92 36 66 88
1 1 1 1 1 1 1 88
3 3 3 3 3 3 3 88
2 2 2 2 2 2 2 88
RHS:
7 is fired!!!!!!!!!
end

rule: 8
LHS:
84 72 62 48 59 109 47 88
2 2 2 2 2 2 2 88
1 1 1 1 1 1 1 88
8 7244 532 4 72 31 5 88
76 42 19 305 48 3 475 88
RHS:
8 is fired!!!!!!!!!
end
  

and the test data :  
37 35 65 59 34 547 74 88
87 12 38 47 19 30 38 88
3 3 3 3 3 3 3 88
00 91 38 13 84 75 26 88
2 2 2 2 2 2 2 88
65 42 46 76 134 54 6 88 
93 18 93 46 92 36 66 88
1 1 1 1 1 1 1 88
54 123 43 56 32 4 56 88
11 22 33 44 55 66 77 88

