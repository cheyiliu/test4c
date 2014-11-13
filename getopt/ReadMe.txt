Here are some examples showing what this program prints with
different combinations of arguments:

     % testopt
     aflag = 0, bflag = 0, cvalue = (null)

     % testopt -a -b
     aflag = 1, bflag = 1, cvalue = (null)

     % testopt -ab
     aflag = 1, bflag = 1, cvalue = (null)

     % testopt -c foo
     aflag = 0, bflag = 0, cvalue = foo

     % testopt -cfoo
     aflag = 0, bflag = 0, cvalue = foo

     % testopt arg1
     aflag = 0, bflag = 0, cvalue = (null)
     Non-option argument arg1

     % testopt -a arg1
     aflag = 1, bflag = 0, cvalue = (null)
     Non-option argument arg1

     % testopt -c foo arg1
     aflag = 0, bflag = 0, cvalue = foo
     Non-option argument arg1

     % testopt -a -- -b
     aflag = 1, bflag = 0, cvalue = (null)
     Non-option argument -b

     % testopt -a -
     aflag = 1, bflag = 0, cvalue = (null)
     Non-option argument -

