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
